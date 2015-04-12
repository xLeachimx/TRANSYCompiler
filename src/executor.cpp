/*FILE: validity.hpp
*Author: Michael Huelsman
*Description:
*  Implementation of executor.hpp
*  Implementation fo base executor functions
*  Tag of s suppresses warnings
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::atoi;
using std::cin;

#include "validity.hpp"
#include "generalstack.hpp"
#include "table.hpp"
#include "eread.hpp"
#include "ewrite.hpp"
#include "estop.hpp"
#include "ecdump.hpp"
#include "elisto.hpp"
#include "enop.hpp"
#include "egoto.hpp"
#include "eifa.hpp"
#include "earead.hpp"
#include "eawrite.hpp"
#include "eloop.hpp"
#include "eloopend.hpp"
#include "elread.hpp"
#include "elwrite.hpp"
#include "eif.hpp"
#include "ecls.hpp"
#include "esubp.hpp"
#include "eassignment.hpp"

//does the actual job of parsing the .obj file
//returns true iff successful
bool parseObjFile(string filename, int buffer[MAX_OBJ_LINES][MAX_OBJ_LINE_SIZE],int lineSizes[], int &length, int maxLines, int maxLineSize);
//converts a string into a series of integers
//returns true iff successful
bool parseObjLine(string str, int line[], int &size, int maxSize);
//converts a filename to the apprpriate .core filename by changing the extension
//returns that transformation
string translateToCore(string filename);
//does the actual job of parsing the .core file
//returns true iff successful
bool parseCoreFile(string filename, Core *c);
//converts a filename to the apprpriate .literal filename by changing the extension
//returns that transformation
string translateToLiteral(string filename);
//does the actual job of parsing the .literal file
//returns true iff successful
bool parseLiteralFile(string filename, string lits[]);

//actual main execution function
void execute(string filename, Core *core, string *lits);

//actual main execution function for brainfuck
void executeBf(string filename);

int executorMain(int argc, char **argv){
	//flags
	bool supressWarnings = false;
	bool zeroInit = false;
	bool brainfuck = false;
	char c;
	while(--argc > 0 && (*++argv)[0] == '-'){
		while((c = *++argv[0])){
			switch(c){
			case 's':
				supressWarnings = true;
				break;
			case 'z':
				zeroInit = true;
				break;
			case 'b':
				brainfuck = true;
				break;
			default:
				cout << "Bad flag:" << c <<endl;
				break;
			}
		}
	}
	//preprocess the files
	for(int i = 0;i < argc;i++){
		if(brainfuck){
			executeBf(argv[i]);
		}
		else{
			string filename = argv[i];
			Core coreMem;
			string literals[MAX_TABLE_ENTRIES];
			if(!parseCoreFile(translateToCore(filename),&coreMem)){
				cout << "ERROR: Problem accessing core file" <<endl;
				return 0;
			}
			if(!coreMem.getAddrContent(VALID_FLAG_LOC)){
				cout << "ERROR: Compilation Failed" <<endl;
				return 0;
			}
			if(!parseLiteralFile(translateToLiteral(filename),literals) && !supressWarnings){
				cout << "WARNING: No Literals being drawn in" <<endl;
			}
			if(zeroInit){
				for(int i =0;i < CORE_SIZE;i++){
					if(coreMem.getAddrContent(i) == DEFAULT_VAL)coreMem.changeAddr(i,0.0);
				}
			}
			execute(filename,&coreMem,literals);
		}
	}
	return 0;
}

void execute(string filename, Core *core, string *lits){
	int objCode[MAX_OBJ_LINES][MAX_OBJ_LINE_SIZE];
	int length = 0;
	int lineSizes[MAX_OBJ_LINES];
	int loopsSeen[MAX_OBJ_LINES];
	for(int i = 0;i < MAX_OBJ_LINES;i++){
		loopsSeen[i] = false;
	}
	GeneralStack<int> loopStack;
	if(!parseObjFile(filename,objCode,lineSizes,length,MAX_OBJ_LINES,MAX_OBJ_LINE_SIZE)){
		cout << "ERROR: Problem opening/parsing object file" << endl;
		return;
	}
	int pc = 0;
	while(pc < length){
		// cout << objCode[pc][0] <<endl;
		// cout << "Line: " << pc << " Operator: " << objCode[pc][0] <<endl;
		if(isRead(objCode[pc][0])){
			int error = executeRead(&objCode[pc][1], lineSizes[pc]-1, core);
			if(error != NO_ERROR){
				cout << "ERROR: " << errorStringExecutor(error) <<endl;
				return;
			}
		}
		else if(isWrite(objCode[pc][0])){
			int error = executeWrite(&objCode[pc][1], lineSizes[pc]-1, core);
			if(error != NO_ERROR){
				cout << "ERROR: " << errorStringExecutor(error) <<endl;
				return;
			}

		}
		else if(isStop(objCode[pc][0])){
			return;
		}
		else if(isCdump(objCode[pc][0])){
			int error = executeCdump(&objCode[pc][1], lineSizes[pc]-1, core);
			if(error != NO_ERROR){
				cout << "ERROR: " << errorStringExecutor(error) <<endl;
				return;
			}
		}
		else if(isListo(objCode[pc][0])){
			int error = executeListo(objCode, lineSizes, length);
			if(error != NO_ERROR){
				cout << "ERROR: " << errorStringExecutor(error) <<endl;
				return;
			}
		}
		else if(isNop(objCode[pc][0])){
			pc++;
			continue;
		}
		else if(isGoto(objCode[pc][0])){
			int error = executeGoto(&objCode[pc][1], lineSizes[pc]-1, &pc);
			if(error != NO_ERROR){
				cout << "ERROR: " << errorStringExecutor(error) <<endl;
				return;
			}
			continue;
		}
		else if(isIfa(objCode[pc][0])){
			int error = executeIfa(&objCode[pc][1], lineSizes[pc]-1, core, &pc);
			if(error != NO_ERROR){
				cout << "ERROR: " << errorStringExecutor(error) <<endl;
				return;
			}
			continue;
		}
		else if(isAread(objCode[pc][0])){
			int error = executeAread(&objCode[pc][1], lineSizes[pc]-1, core);
			if(error != NO_ERROR){
				cout << "ERROR: " << errorStringExecutor(error) <<endl;
				return;
			}
		}
		else if(isAwrite(objCode[pc][0])){
			int error = executeAwrite(&objCode[pc][1], lineSizes[pc]-1, core);
			if(error != NO_ERROR){
				cout << "ERROR: " << errorStringExecutor(error) <<endl;
				return;
			}
		}
		else if(isSubp(objCode[pc][0])){
			int error = executeSubp(&objCode[pc][1], lineSizes[pc]-1, core);
			if(error != NO_ERROR){
				cout << "ERROR: " << errorStringExecutor(error) <<endl;
				return;
			}
		}
		else if(isLoop(objCode[pc][0])){
			bool end = false;
			bool seen = loopsSeen[pc];
			if(!loopStack.push(pc)){
				cout << "ERROR: Too many nested loops" <<endl;
				return;
			}
			int error = executeLoop(&objCode[pc][1],lineSizes[pc]-1,core,seen,&end);
			loopsSeen[pc] = true;
			if(error != NO_ERROR){
				cout << "ERROR: " << errorStringExecutor(error) <<endl;
				return;
			}
			if(end){
				int matchingEnd;
				int count = 1;
				for(matchingEnd = pc+1; matchingEnd < MAX_OBJ_LINES; matchingEnd++){
					if(isLoop(objCode[matchingEnd][0]))count++;
					if(isLoopEnd(objCode[matchingEnd][0]))count--;
					if(count == 0)break;
				}
				loopsSeen[pc] = false;
				loopStack.pop(count);
				pc = matchingEnd+1;
				continue;
			}
		}
		else if(isLoopEnd(objCode[pc][0])){
			if(!loopStack.pop(pc)){
				cout << "ERROR: Loop Ended with no where to return" <<endl;
				return;
			}
			continue;
		}
		else if(isLread(objCode[pc][0])){
			int error = executeLread(&objCode[pc][1], lineSizes[pc]-1, lits);
			if(error != NO_ERROR){
				cout << "ERROR: " << errorStringExecutor(error) <<endl;
				return;
			}
		}
		else if(isLwrite(objCode[pc][0])){
			int error = executeLwrite(&objCode[pc][1], lineSizes[pc]-1, lits);
			if(error != NO_ERROR){
				cout << "ERROR: " << errorStringExecutor(error) <<endl;
				return;
			}
		}
		else if(isIf(objCode[pc][0])){
			int error = executeIf(&objCode[pc][1], lineSizes[pc]-1, core, &pc);
			if(error != NO_ERROR){
				cout << "ERROR: " << errorStringExecutor(error) <<endl;
				return;
			}
			continue;
		}
		else if(isCls(objCode[pc][0])){
			int error = executeCls();
			if(error != NO_ERROR){
				cout << "ERROR: " << errorStringExecutor(error) <<endl;
				return;
			}
		}
		else if(isAssignment(objCode[pc][0])){
			int error = executeAssignment(&objCode[pc][1], lineSizes[pc]-1, core);
			if(error != NO_ERROR){
				cout << "ERROR: " << errorStringExecutor(error) <<endl;
				return;
			}
		}
		else{
			cout << "Here" <<endl;
		}
		pc++;
	}
}


//does the actual job of parsing the .obj file
//returns true iff successful
bool parseObjFile(string filename, int buffer[MAX_OBJ_LINES][MAX_OBJ_LINE_SIZE],int lineSizes[], int &length, int maxLines, int maxLineSize){
	int counter = 0;
	string line;
	ifstream fin;
	fin.open(filename.c_str());
	if(!fin.is_open())return false;
	getline(fin,line);
	while(!fin.eof()){
		if(counter >= maxLines){
			length = counter;
			fin.close();
			return false;
		}
		if(!parseObjLine(line, buffer[counter], lineSizes[counter], maxLineSize)){
			length = counter;
			fin.close();
			return false;
		}
		getline(fin,line);
		counter++;
	}
	length = counter;
	fin.close();
	return true;
}
//converts a string into a series of integers
//returns true iff successful
bool parseObjLine(string str, int line[],int &size, int maxSize){
	vector<string> elements = split(str,' ');
	if(elements.size() > maxSize)return false;
	for(int i = 0;i < elements.size();i++){
		line[i] = atoi(elements[i].c_str());
	}
	size = elements.size();
	return true;
}
//converts a filename to the apprpriate .core filename by changing the extension
//returns that transformation
string translateToCore(string filename){
	string newName = filename;
	newName.erase(newName.rfind('.'));
	return newName+".core";
}
//does the actual job of parsing the .core file
//returns true iff successful
bool parseCoreFile(string filename, Core *c){
	int counter = 0;
	double temp;
	ifstream fin;
	fin.open(filename.c_str());
	fin.precision(10);
	if(!fin.is_open())return false;
	fin >> temp;
	while(!fin.eof()){
		if(counter >= CORE_SIZE){
			fin.close();
			return false;
		}
		if(temp != DEFAULT_VAL)c->changeAddr(counter++,temp);
		fin >> temp;
	}
	fin.close();
	return true;
}
//converts a filename to the apprpriate .literal filename by changing the extension
//returns that transformation
string translateToLiteral(string filename){
	string newName = filename;
	newName.erase(newName.rfind('.'));
	return newName+".literal";
}
//does the actual job of parsing the .literal file
//returns true iff successful
bool parseLiteralFile(string filename, string lits[]){
	int counter = 0;
	string temp;
	ifstream fin;
	fin.open(filename.c_str());
	if(!fin.is_open())return false;
	getline(fin,temp);
	while(!fin.eof()){
		if(counter >= MAX_TABLE_ENTRIES){
			fin.close();
			return false;
		}
		lits[counter++] = temp;
		getline(fin,temp);
	}
	fin.close();
	return true;
}

/*-------------------------------------------\
|   This is the special part of the executor |
|   This part compiler brainfuck code        |
|                                            |
|   http://en.wikipedia.org/wiki/Brainfuck   |
|                                            |
|                                            |
\-------------------------------------------*/

//actual main execution function for brainfuck
void executeBf(string filename){
	ifstream fin;
	fin.open(filename.c_str());
	string temp;
	getline(fin,temp);
	//brainfuck vars
	char tape[CORE_SIZE];
	for(int i = 0;i < CORE_SIZE;i++){
		tape[i] = 0;
	}
	int location = 0;
	GeneralStack<int> loopStack;
	for(int i = 0;i < temp.length();i++){
		if(location >= CORE_SIZE || location < 0){
			cout << "Execution error" <<endl;
			return;
		}
		switch(temp[i]){
			case '0':
				tape[location]++;
				break;
			case '1':
				tape[location]--;
				break;
			case '2':
				location++;
				break;
			case '3':
				location--;
				break;
			case '4':
				if(!loopStack.push(location)){
					cout << "Execution error" <<endl;
					return;
				}
				break;
			case '5':
				if(tape[location] != 0){
					if(!loopStack.pop(location)){
						cout << "Execution error" <<endl;
						return;
					}
				}
				break;
			case '6':
				cin >> tape[location];
				break;
			case '7':
				cout << tape[location];
				break;
			default:
				cout << "Execution error" <<endl;
				return;
				break;
		}
	}
	fin.close();
}
