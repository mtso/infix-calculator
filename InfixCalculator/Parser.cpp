// Parser.cpp
// Lab 3: Infix Calculator
// CIS 22C F2016
// Adrian Marroquin, Matthew Tso

#ifndef INFIXCALCULATOR_PARSER_CPP
#define INFIXCALCULATOR_PARSER_CPP

#include "Parser.h"

bool isValidCharacter(const char& inputChar);
bool isInteger(const char& inputChar);
bool isOpenParen(const char& inputChar);
bool isClosingParen(const char& inputChar);
bool isOperator(const char& inputChar);

bool Parser::isSyntacticallyCorrect(const std::string& inputString)
{
	if (inputString.length() < 3)
	{
		return false;
	}
	
	int openingParens = 0;

	for (int i = 0; i < (int)inputString.length(); i++) {

		if (!isValidCharacter(inputString[i])) {
			return false;
		}

		// Don't compare the last character with the null terminator
		if (i < inputString.length() - 1)
		{
			// False if two consecutive integers
			if (isInteger(inputString[i]) && isInteger(inputString[i + 1])) {
				return false;
			}

			// False if two consecutive operators
			if (isOperator(inputString[i]) && isOperator(inputString[i + 1])) {
				return false;
			}
		}

		if (isOpenParen(inputString[i])) {
			openingParens++;

			// Return false if an integer is on the left side of the opening paren
			// will not assume that the user intended a multiplication operation.
			if (i > 0 && isInteger(inputString[i - 1])) {
				return false;
			}

			// Return false if an operator is on the right side (inside) of the opening paren
			if (i < inputString.length() - 1 && isOperator(inputString[i + 1])) {
				return false;
			}
		}

		if (isClosingParen(inputString[i])) {
			// Cannot have a closing paren before an opening paren
			if (openingParens == 0) {
				return false;
			}
			// 'Close' the pair of parens
			else {
				openingParens--;
			}

			// Return false if an operator is on the left side (inside) of the closing paren
			// will not assume that the user intended a multiplication operation.
			if (i > 0 && isOperator(inputString[i - 1])) {
				return false;
			}

			// Return false if an integer is on the right side of the closing paren
			// will not assume that the user intended a multiplication operation.
			if (i < inputString.length() - 1 && isInteger(inputString[i + 1])) {
				return false;
			}
		}
		
		if (isOperator(inputString[i])) {
			// An operator cannot be first/last character
			if (i == 0 || i == inputString.length() - 1) {
				return false;
			}
		}
	}

	// Make sure all opening parens have been closed
	if (openingParens > 0) {
		return false;
	}

	return true;
}

bool isValidCharacter(const char& inputChar)
{
	return 
		isOperator(inputChar) || 
		isInteger(inputChar) ||
		isOpenParen(inputChar) || 
		isClosingParen(inputChar);
}

bool isOperator(const char& inputChar)
{
	switch (inputChar) {
	case '*':
	case '/':
	case '+':
	case '-':
		return true;

	default:
		return false;
	}
}

bool isInteger(const char& inputChar)
{
	return isdigit(inputChar) != 0;
}

bool isOpenParen(const char& inputChar)
{
	return (inputChar == '(') ? true : false;
}

bool isClosingParen(const char& inputChar)
{
	return (inputChar == ')') ? true : false;
}

#endif