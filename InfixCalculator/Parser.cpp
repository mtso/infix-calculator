// Lab 3: Infix Calculator
// CIS 22C F2016
// Adrian Marroquin, Matthew Tso

#ifndef INFIXCALCULATOR_PARSER_CPP
#define INFIXCALCULATOR_PARSER_CPP

#include "Parser.h"

bool Parser::isSyntacticallyCorrect(const std::string& inputString)
{
	if (inputString.length() < 3)
	{
		return false;
	}
	
	for (int i = 0; i < inputString.length(); i++) {

	}


	return true;
}


#endif