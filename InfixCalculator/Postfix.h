// Parser.h
// Lab 3: Infix Calculator
// CIS 22C F2016
// Adrian Marroquin, Matthew Tso

#ifndef INFIXCALCULATOR_POSTFIX_H
#define INFIXCALCULATOR_POSTFIX_H

#include "Stack.h"
#include <string>
using namespace std;

class Postfix
{
private:
	Stack<int> valstack;
	Stack<char> opstack;

public:
	string convert(const string& infixExpression) 
};

#endif