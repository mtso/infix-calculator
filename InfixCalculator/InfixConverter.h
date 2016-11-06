// InfixConverter.h
// Lab 3: Postfix Operations
// CIS 22C F2016: Adrian Marroquin, Matthew Tso\

/**
 * Converts an infix expression into postfix form
 */

#ifndef INFIXCALCULATOR_INFIXCONVERTER_H
#define INFIXCALCULATOR_INFIXCONVERTER_H

#include <string>
#include "StackADT\Stack.h"

using namespace std;

string convertInfixToPostfix(const string& inputString);

#endif