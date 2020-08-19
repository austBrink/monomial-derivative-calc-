#include<String>
#include<stdio.h>
#include<iostream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(void) {
	string userFunction = "";
	cout<<"\n\n\t Enter a Function in this form: \n f(x) = ax^{b} \n"<<endl;
	getline(cin,userFunction);
	string sTemp = "";
	int i = 0;
	i = userFunction.find("=");
	string functionDef = "";
	functionDef = userFunction.substr(0, i); 
	userFunction.replace(0, i+1, "");
	int param1 = functionDef.find_last_of('(');
	int param2 = functionDef.find_first_of(')');
	string parameter = functionDef.substr(param1+1, param2-2);
	i = userFunction.find(parameter);
	string constMult = userFunction.substr(0, i);
	i = userFunction.find("^");
	string exponent = "";
	int brack1 = userFunction.find_last_of('{');
	int brack2 = userFunction.find_first_of('}');
	exponent = userFunction.substr(brack1+1,brack2);
	exponent = exponent.erase(exponent.find("}"));
	double fConst = atof(constMult.c_str());
	double fExp = atof(exponent.c_str());
	fConst = fConst * fExp;
	fExp = fExp - 1;
	int x = functionDef.find("(");
	functionDef.insert(x,"'");
	cout << "Your derivative is..." << endl;
	cout << functionDef << "= " << fConst << parameter << "^{" << fExp << "}" <<endl;
	return 0;
}
