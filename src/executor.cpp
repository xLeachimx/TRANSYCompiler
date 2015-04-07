/*FILE: validity.hpp
*Author: Michael Huelsman
*Description:
*  Implementation of executor.hpp
*  Implementation fo base executor functions
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::atoi;

#include "validity.hpp"

//does the actual job of parsing the .obj file
//returns true iff successful
bool parseObjFile(string filename, int buffer[][],int lineSizes[], int maxLines, int maxLineSize);
//converts a string into a series of integers
//returns true iff successful
bool parseObjLine(string str, int line[], int maxSize);
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

int main(){
	//flags
	bool supressWarnings = false;
	char c;
	while(--argc > 0 && (*++argv)[0] == '-'){
		while((c = *++argv[0])){
			switch(c){
			case 's':
				supressWarnings = true;
				break;
			default:
				cout << "Bad flag:" << c <<endl;
				break;
			}
		}
	}
	//preprocess the files
	for(int i = 0;i < argc;i++){
		string filename = argv[i];
		Core coreMem;
		string literals[MAX_TABLE_ENTRIES];
		if(!parseObjFile(translateToCore(filename),&coreMem)){
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
		execute(filename,&coreMem,literals);
	}
	return 0;
}

void execute(string filename, Core *core, string *lits){
	int objCode[MAX_OBJ_LINES][MAX_OBJ_LINE_SIZE];
	int lineSizes[MAX_OBJ_LINES];
	if(!parseObjFile(filename,objCode,lineSizes,MAX_OBJ_LINES,MAX_OBJ_LINE_SIZE)){
		cout << "ERROR: Problem opening/parsing object file" << endl;
		return;
	}
	int pc = 0;
	while(pc < MAX_OBJ_LINES){
		if(isRead(objCode[pc][0])){
		}
		else if(isWrite(objCode[pc][0])){
		}
		else if(isStop(objCode[pc][0])){
		}
		else if(isCdump(objCode[pc][0])){
		}
		else if(isListo(objCode[pc][0])){
		}
		else if(isNop(objCode[pc][0])){
		}
		else if(isGoto(objCode[pc][0])){
		}
		else if(isIfa(objCode[pc][0])){
		}
		else if(isAread(objCode[pc][0])){
		}
		else if(isAwrite(objCode[pc][0])){
		}
		else if(isSubp(objCode[pc][0])){
		}
		else if(isLoop(objCode[pc][0])){
			bool end = false;
			bool seen = false;
			executeLoop((&objCode[pc])++,lineSizes[pc],core,seen,&end);
			if(end){
				int matchingEnd;
				count = 1;
				for(matchingEnd = pc+1; matchingEnd < MAX_OBJ_LINES; matchingEnd++){
					if(isLoop(objCode[matchingEnd][0]))count++;
					if(isLoopEnd(objCode[matchingEnd][0]))count--;
					if(count == 0)break;
				}
				pc = matchingEnd+1;
			}
		}
		else if(isLoopEnd(objCode[pc][0])){
		}
		else if(isLread(objCode[pc][0])){
		}
		else if(isLwrite(objCode[pc][0])){
		}
		else if(isIf(objCode[pc][0])){
		}
		else if(isCls(objCode[pc][0])){
		}
		else if(isAssignment(objCode[pc][0])){
		}
	}
}


//does the actual job of parsing the .obj file
//returns true iff successful
bool parseObjFile(string filename, int buffer[][],int lineSizes[], int maxLines, int maxLineSize){
	int counter = 0;
	string line;
	ifstream fin;
	fin.open(filename.c_str());
	if(!fin.is_open())return false;
	getline(fin,line);
	while(!fin.eof()){
		if(counter >= maxLines){
			fin.close();
			return false;
		}
		if(!parseObjLine(line, buffer[i], maxLineSize)){
			fin.close();
			return false;
		}
		getline(fin,temp);
	}
	fin.close();
}
//converts a string into a series of integers
//returns true iff successful
bool parseObjLine(string str, int line[], int maxSize){
	vector<string> elements = split(str,' ');
	if(elements.size() > maxSize)return false;
	for(int i = 0;i < elements.size();i++){
		line[i] = atoi(elements[i].c_str());
	}
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
}