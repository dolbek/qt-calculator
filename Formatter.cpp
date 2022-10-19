#include "Formatter.h"
#include <stack>
#include <stdexcept>
#include <sstream>
#include "CalculatorEnums.h"

//Converts the given string calculation into postfix notation
vector<string> Formatter::generatePostfix(const string& str) {

	//The vector to store the infix expression
	vector<string> postfix;

	//Stack for holding operators
    stack<string> stack;

    size_t length;

	if (str != "")
		length = str.length();
	else
		length = 0;

	//Loop through each character in the expression, sorting them to be added to the postfix vector
	for (int i = 0; i < length; ++i) {
        string subStr{ str.at(i) };

		/*	
			If a character is a digit that is followed by more digits, (ie a multi-digit
			number) it is divided into a substring to be added to the vector as a whole.
			Else, single-digit numbers are added as-is.
			The right side of the first OR condition is as follows: "-" is considered a digit if
			it is the first character, or if it follows an operator. Otherwise,
			it must be a subtraction operator.
		*/
        if (isdigit(subStr.at(0)) || subStr == "." || (subStr.at(0) == SUB && (i == 0 || !isdigit(str.at(i - 1))))) {
			int j{ i + 1 };
            if(j < length){
                string d{ str.at(j) };

                if (isdigit(str.at(j)) || d == ".") {
                    while ((j < length && isdigit(str.at(j))) || (j < length && str.at(j) == '.'))
                        ++j;
                    string number{ str.substr(i, j-i) };
                    i = j - 1;
                    postfix.push_back(number);
                }
                else
                    postfix.push_back(subStr);
            }
            else
                postfix.push_back(subStr);
		}
		/*
			Handle scientific notation.Skips over the "E+" in "x E+ y".The "x" is
			already in the vector. Adds 10 as the next entry, followed by "y", followed by
			"^" and "*". Final result is adding the infix expression "x E+ y" as the postfix
			expression "x 10 y ^ *" which evaluates correctly.
		*/
        else if (subStr.at(0) == SCINOT) {
			postfix.push_back("10");
			int j{ i + 2 };
			char d{ str.at(j) };

			if (j < length && (isdigit(d) || d == '.')) {
				while (j < length && (isdigit(str.at(j)) || str.at(j) == '.'))
					++j;
                string number{ str.substr(i + 2, j-(i+2)) };
				i = j - 1;
				postfix.push_back(number);
			}
            postfix.push_back("^");
            postfix.push_back("*");
		}
		/*
			Open parentheses are pushed onto the stack
		*/
        else if (subStr == "(")
            stack.push(subStr);
		/*
			On a close parenthesis, pop the contents of the stack and add it to the vector
            until the open parenthesis is reached, which is discarded.
		*/
        else if (subStr == ")") {
			try {
                while (stack.top() != "(") {
					if (stack.empty()) {
						throw range_error("Stack is empty");	//If an error is thrown here, the expression is invalid
					}
                    postfix.push_back(stack.top());
					stack.pop();
				}
			}
            catch (range_error&) {
				throw;	//Propagate the error
			}
		}

		/*
			Operators are pushed onto the stack if it is empty, or if the operator on top of the stack
            has a lower precedence than the new one. If not, the higher precedence operator is popped
            and added to the vector, after which the new operator is pushed to the stack.
		*/
		else {
            while (!stack.empty() && operatorPrecedence(subStr) <= operatorPrecedence(stack.top())) {
                postfix.push_back(stack.top());
				stack.pop();
			}
            stack.push(subStr);
		}
	}
	//The remaining operators on the stack are popped and added to the vector.
    while (!stack.empty()) {
        if(stack.top() == "(")
            stack.pop();
        else {
            postfix.push_back(stack.top());
            stack.pop();
        }
	}
	//Return the postfix vector
	return postfix;
}

//Returns an int value representing the precedence of an operator
int Formatter::operatorPrecedence(string &str) {

    char c{str.at(0)};
	switch (c) {
	case EXP:
	case SQRT:
	case SIN:
	case COS:
	case TAN:
		return 3;
	case MULT:
	case DIV:
		return 2;
	case ADD:
	case SUB:
		return 1;
	default:
		return 0;
	}
}

//Returns the given integer as string
string Formatter::toString(int i) {
    stringstream ss;
    ss << i;
    return ss.str();
}

//Returns the given double as string
string Formatter::toString(double d) {
    stringstream ss;
    ss << d;
    return ss.str();
}
