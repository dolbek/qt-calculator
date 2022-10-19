#pragma once
#include "CalculatorEnums.h"
#include <string>
#include <vector>

using namespace std;

class Calculator{

public:
    Calculator() = default;			//Constructor
	string calculate(const string& calc);	//Public method to calculate the value of calculation as string
	void setMemory(const string& mem);		//Set memory
    string getMemory();				//Get memory
	void memoryAdd(const string& val);		//Add to memory
	void memorySub(const string& val);		//Subtract from memory
	bool hasMemory();				//Return true if there is something stored in memory
	bool hasError();				//Return true if there is an error
	void clearError();				//Clears any errors
	ErrorType getErrorType();		//Returns the type of error
	
private:
	double calculate(const vector<string>& postfix);	//Calculates the value of a postfix expression
	bool isNumber(const string& str);					//Return true if the string is a number
    string formatOutput(double num);			//Return the string equivalent of the passed double

	//Some status tracking variables
	ErrorType errorType{ ErrorType::NONE };	//Type of current error
	double memory{ 0 };						//Currently stored memory value

	//Various state flags
	bool isError{ false };			//True if there is an error
	bool disregardCalc{ false };	//True if the calculation should be paused for now during running operations
};

