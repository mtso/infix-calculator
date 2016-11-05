// Parser.cpp
// Lab 3: Infix Calculator
// CIS 22C F2016
// Adrian Marroquin, Matthew Tso

#ifndef INFIXCALCULATOR_PARSER_CPP
#define INFIXCALCULATOR_PARSER_CPP

#include "Parser.h"

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

	for (int i = 0; i < inputString.length(); i++) {

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
		
		
	}


	return true;
}


bool isOperator(const char& inputChar)
{
	switch (inputChar) {
	case '*':
	case '/':
	case '+':
	case '-':
		return true;
		break;

	default:
		return false;
	}
}

bool isInteger(const char& inputChar)
{
	switch (inputChar) {
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case '0':
		return true;
		break;

	default:
		return false;
	}
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