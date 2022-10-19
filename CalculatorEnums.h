#pragma once

//Constants
const char ADD = '+';
const char SUB = '-';
const char MULT = '*';
const char DIV = '/';
const char EXP = '^';
const char SQRT = 'r';
const char SIN = 's';
const char COS = 'c';
const char TAN = 't';
const char SCINOT = 'e';

//List of operators
enum class Operator { ADD = ADD, SUB = SUB, MULT = MULT, DIV = DIV, EXP = EXP, SQRT = SQRT, SIN = SIN, COS = COS, TAN = TAN, SCINOT = SCINOT };

//Error types
enum class ErrorType { NONE, INPUT, DIVZERO, NEQSQRT, OTHER, MEMORY };
