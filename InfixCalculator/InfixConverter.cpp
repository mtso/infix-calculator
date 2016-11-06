// InfixConverter.h
// Lab 3: Postfix Operations
// CIS 22C F2016: Adrian Marroquin, Matthew Tso\

/**
* Converts an infix expression into postfix form
*/

#ifndef INFIXCALCULATOR_INFIXCONVERTER_CPP
#define INFIXCALCULATOR_INFIXCONVERTER_CPP

#include "InfixConverter.h"

string convertInfixToPostfix(const string& infixExp)
{
	Stack<char> operandStack;
	Stack<char> operatorStack;

	for (int i = 0; i < infixExp.length(); i++) {
		switch (infixExp[i]) {

		}
	}

	return "";
}

#endif