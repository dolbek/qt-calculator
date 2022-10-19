#pragma once
#include <string>
#include <vector>

using namespace std;

class Formatter{
public:
    static vector<string> generatePostfix(const string& str);	//Convert the given string to postfix notation
    static string toString(int i);      //Returns the given integer as string
    static string toString(double d);   //Returns the given double as string

private:
    static int operatorPrecedence(string &c);	//Returns the precedence of the given operator
};

