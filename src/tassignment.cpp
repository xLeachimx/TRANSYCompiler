#include "validity.hpp"
#include "tassignment.hpp"
#include "token.hpp"
#include "tokenStack.hpp"
#include <cstdio>
#include <cstdlib>
using std::atoi;
using std::sprintf;

#define MAX_TOKENS_IN_STORE 101

//tokenizes a statement according to assignment statement rules
//returns the number of tokens stored
int tokenize(string str, Token store[], int size);

//runs the tokenized line through the transducer returns false if there is an error
bool transduction(Token line[], int size);

//implementation of the parse Assignment function
string parseAssignment(string line, SymTable *symTable){
	string result = "20 ";
	Token tokens[MAX_TOKENS_IN_STORE];
	int size = tokenize(line, tokens, MAX_TOKENS_IN_STORE);
	transduction(tokens,size);
	for(int i = 0;i < size;i++){
		if(tokens[i].token == "ID"){
			if(validSymbol(tokens[i].getSymbol())){
				int addr = symtable.retrieve(tokens[i].getSymbol());
				if(addr == -1){
					addr = symtable.insert(tokens[i].getSymbol());
				}
				result += sprintf(buffer,"%d",addr);
				result += ' ';
			}
			else if(validNumber(tokens[i].getSymbol())){
				string temp = standardizeNumber(tokens[i].getSymbol());
				int addr = symtable.retrieve(temp);
				if(addr == -1){
					addr = symtable.insert(temp);
				}
				result += sprintf(buffer,"%d",addr);
				result += ' ';
			}
			else if(tokens[i].getSymbol()[0] == '-' && validSymbol(tokens[i].getSymbol().substr(1))){
			}
		}
		else{
			if(tokens[i].getSymbol() == "=")result += "-1 ";
			else if(tokens[i].getSymbol() == "+")result += "-6 ";
			else if(tokens[i].getSymbol() == "-")result += "-7 ";
			else if(tokens[i].getSymbol() == "*")result += "-4 ";
			else if(tokens[i].getSymbol() == "/")result += "-5 ";
			else if(tokens[i].getSymbol() == "[")result += "-2 ";
			else if(tokens[i].getSymbol() == "^")result += "-3 ";
		}
	}
	return result;
}

//implementation of the vaild assignment function
int validAssignment(string line, SymTable *symTable){
	if(!validCharsAssignment(line))return BAD_FORM;
	Token tokens[MAX_TOKENS_IN_STORE];
	int size = tokenize(line, tokens, MAX_TOKENS_IN_STORE);
	for(int i = 0;i < size;i++){
		if(tokens[i].getToken() == "ID"){
			if(!validNumber(tokens[i].getSymbol()) && !validSymbol(tokens[i].getSymbol()))return BAD_ARGS;
		}
	}
	if(!transduction(tokens,size))return BAD_FORM;
	for(int i = 0;i < size;i++){
		if(tokens[i].token == "ID"){
			if( !(validSymbol(tokens[i].getSymbol())) && !(validNumber(tokens[i].getSymbol())) && !(tokens[i].getSymbol()[0] == '-' && validSymbol(tokens[i].getSymbol().substr(1))) ){
				return BAD_ARGS;
			}
		}
	}
	return NO_ERROR;
}

int tokenize(string str, Token store[], int size){
	int lastStop = 0;
	int insert = 0;
	char lastOper = ' ';
	bool operSeen = false;
	for(int i = 0;i < str.length();i++){
		if(isOperator(str[i])){
			if(operSeen && isMathOperator(lastOper) && str[i] == '-'){
				operatorSeen = false;
				continue;
			}
			operatorSeen = true;
			lastOper = str[i];
			string temp = str.substr(lastStop, i-lastStop);
			lastStop = i + 1;
			Token t = Token(temp, "ID");
			store[insert++] = t;
			if(insert == size) return size;
			t = Token(str[i], str[i]);
			store[insert++] = t;
			if(insert == size) return size;
		}
		else if(i == str.length()-1){
			string temp = str.substr(lastStop, i-lastStop+1);
			lastStop = i + 1;
			Token t = Token(temp, "ID");
			store[insert++] = t;
			store[insert++] = Token("EOL","EOL");
			if(insert == size) return size;
		}
	}
	return insert;
}


//The rest on this file has to do with transduction

void setupTransducer(Transducer &t){
	Rule temp;
	//line one
	temp.topStack = Token("","INVALID");
	temp.input = Token("","ID");
	temp.action = S1;
	t.addRule(temp);
	temp.topStack = Token("","INVALID");
	temp.input = Token("","=");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","INVALID");
	temp.input = Token("","[");
	temp.action = S2;
	t.addRule(temp);
	//line two
	temp.topStack = Token("","=");
	temp.input = Token("","ID");
	temp.action = S1;
	t.addRule(temp);
	temp.topStack = Token("","=");
	temp.input = Token("","+");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","=");
	temp.input = Token("","-");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","=");
	temp.input = Token("","*");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","=");
	temp.input = Token("","/");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","=");
	temp.input = Token("","(");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","=");
	temp.input = Token("","[");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","=");
	temp.input = Token("","^");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","=");
	temp.input = Token("","EOL");
	temp.action = U2;
	t.addRule(temp);
	//line three
	temp.topStack = Token("","+");
	temp.input = Token("","ID");
	temp.action = S1;
	t.addRule(temp);
	temp.topStack = Token("","+");
	temp.input = Token("","+");
	temp.action = U1;
	t.addRule(temp);
	temp.topStack = Token("","+");
	temp.input = Token("","-");
	temp.action = U1;
	t.addRule(temp);
	temp.topStack = Token("","+");
	temp.input = Token("","*");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","+");
	temp.input = Token("","/");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","+");
	temp.input = Token("","(");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","+");
	temp.input = Token("",")");
	temp.action = U3;
	t.addRule(temp);
	temp.topStack = Token("","+");
	temp.input = Token("","[");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","+");
	temp.input = Token("","]");
	temp.action = U4;
	t.addRule(temp);
	temp.topStack = Token("","+");
	temp.input = Token("","^");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","+");
	temp.input = Token("","EOL");
	temp.action = U2;
	t.addRule(temp);
	//line four
	temp.topStack = Token("","-");
	temp.input = Token("","ID");
	temp.action = S1;
	t.addRule(temp);
	temp.topStack = Token("","-");
	temp.input = Token("","+");
	temp.action = U1;
	t.addRule(temp);
	temp.topStack = Token("","-");
	temp.input = Token("","-");
	temp.action = U1;
	t.addRule(temp);
	temp.topStack = Token("","-");
	temp.input = Token("","*");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","-");
	temp.input = Token("","/");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","-");
	temp.input = Token("","(");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","-");
	temp.input = Token("",")");
	temp.action = U3;
	t.addRule(temp);
	temp.topStack = Token("","-");
	temp.input = Token("","[");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","-");
	temp.input = Token("","]");
	temp.action = U4;
	t.addRule(temp);
	temp.topStack = Token("","-");
	temp.input = Token("","^");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","-");
	temp.input = Token("","EOL");
	temp.action = U2;
	t.addRule(temp);
	//line five
	temp.topStack = Token("","*");
	temp.input = Token("","ID");
	temp.action = S1;
	t.addRule(temp);
	temp.topStack = Token("","*");
	temp.input = Token("","+");
	temp.action = U1;
	t.addRule(temp);
	temp.topStack = Token("","*");
	temp.input = Token("","-");
	temp.action = U1;
	t.addRule(temp);
	temp.topStack = Token("","*");
	temp.input = Token("","*");
	temp.action = U1;
	t.addRule(temp);
	temp.topStack = Token("","*");
	temp.input = Token("","/");
	temp.action = U1;
	t.addRule(temp);
	temp.topStack = Token("","*");
	temp.input = Token("","(");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","*");
	temp.input = Token("",")");
	temp.action = U3;
	t.addRule(temp);
	temp.topStack = Token("","*");
	temp.input = Token("","[");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","*");
	temp.input = Token("","]");
	temp.action = U4;
	t.addRule(temp);
	temp.topStack = Token("","*");
	temp.input = Token("","^");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","*");
	temp.input = Token("","EOL");
	temp.action = U2;
	t.addRule(temp);
	//line six
	temp.topStack = Token("","(");
	temp.input = Token("","ID");
	temp.action = S1;
	t.addRule(temp);
	temp.topStack = Token("","(");
	temp.input = Token("","+");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","(");
	temp.input = Token("","-");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","(");
	temp.input = Token("","*");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","(");
	temp.input = Token("","/");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","(");
	temp.input = Token("","(");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","(");
	temp.input = Token("",")");
	temp.action = U3;
	t.addRule(temp);
	temp.topStack = Token("","(");
	temp.input = Token("","[");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","(");
	temp.input = Token("","]");
	temp.action = U4;
	t.addRule(temp);
	temp.topStack = Token("","(");
	temp.input = Token("","^");
	temp.action = S2;
	t.addRule(temp);
	//line seven
	//line eight
	temp.topStack = Token("","[");
	temp.input = Token("","ID");
	temp.action = S1;
	t.addRule(temp);
	temp.topStack = Token("","[");
	temp.input = Token("","+");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","[");
	temp.input = Token("","-");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","[");
	temp.input = Token("","*");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","[");
	temp.input = Token("","/");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","[");
	temp.input = Token("","(");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","[");
	temp.input = Token("",")");
	temp.action = U3;
	t.addRule(temp);
	temp.topStack = Token("","[");
	temp.input = Token("","[");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","[");
	temp.input = Token("","]");
	temp.action = U4;
	t.addRule(temp);
	temp.topStack = Token("","[");
	temp.input = Token("","^");
	temp.action = S2;
	t.addRule(temp);
	//line nine
	//line ten
	temp.topStack = Token("","^");
	temp.input = Token("","ID");
	temp.action = S1;
	t.addRule(temp);
	temp.topStack = Token("","^");
	temp.input = Token("","+");
	temp.action = U1;
	t.addRule(temp);
	temp.topStack = Token("","^");
	temp.input = Token("","-");
	temp.action = U1;
	t.addRule(temp);
	temp.topStack = Token("","^");
	temp.input = Token("","*");
	temp.action = U1;
	t.addRule(temp);
	temp.topStack = Token("","^");
	temp.input = Token("","/");
	temp.action = U1;
	t.addRule(temp);
	temp.topStack = Token("","^");
	temp.input = Token("","(");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","^");
	temp.input = Token("",")");
	temp.action = U3;
	t.addRule(temp);
	temp.topStack = Token("","^");
	temp.input = Token("","[");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","^");
	temp.input = Token("","]");
	temp.action = U4;
	t.addRule(temp);
	temp.topStack = Token("","^");
	temp.input = Token("","^");
	temp.action = S2;
	t.addRule(temp);
	temp.topStack = Token("","^");
	temp.input = Token("","EOL");
	temp.action = U2;
	t.addRule(temp);
}

bool transduction(Token line[], int size){
	Transducer temp;
	setupTransducer(temp);
	TokenStack one;
	TokenStack two;
	int action = BAD_ACTION;
	for(int i = 0;i < size;i++){
		int action = temp.getAction(line[i],two.peek());
		switch action{
			case U1:
				if(!one.push(two.pop()))return false;
				break;
			case U2:
				while(two.size() > 0){
					if(!one.push(two.pop()))return false;
				}
				break;
			case U3:
				while(two.peek().token != '('){
					if(two.size() <= 0)return false;
					if(!one.push(two.pop()))return false;
				}
				two.pop();
				break;
			case U4:
				while(two.peek().token != '['){
					if(two.size() <= 0)return false;
					if(!one.push(two.pop()))return false;
				}
				if(!one.push(two.pop()))return false;
				break;
			case S1:
				if(!one.push(line[i]))return false;
				break;
			case S2:
				if(!two.push(line[i]))return false;
				break;
			default:
				return false;
				break;
		}
	}
	if(action != U2)return false;
	one.copyContents(line,size);
	return true;
}