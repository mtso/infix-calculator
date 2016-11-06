// InfixConverter.h
// Lab 3: Postfix Operations
// CIS 22C F2016: Adrian Marroquin, Matthew Tso\

/**
 * Converts an infix expression into postfix form
 */

#ifndef INFIXCALCULATOR_INFIXCALCULATOR_H
#define INFIXCALCULATOR_INFIXCALCULATOR_H

#include <iostream>
#include <string>
#include "StackADT\Stack.h"
#include "Operator.h"

using namespace std;

string convertInfixToPostfix(const string& inputString);

class InfixCalculator
{
private:
	Stack<int> valueStack;
	Stack<char> operatorStack;
	string infixExp;
	//string postfixExp;
	int result;

	void performOperation();
	void evaluateExpression();

public:
	bool setInfixExp(const string& inputExpression);
	int getResult() const;
};

#endif