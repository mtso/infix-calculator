// Lab 3: Infix Calculator
// CIS 22C F2016
// Adrian Marroquin, Matthew Tso

#ifndef INFIXCALCULATOR_PARSER_CPP
#define INFIXCALCULATOR_PARSER_CPP

#include "Parser.h"

bool Parser::isSyntacticallyCorrect(const std::string& infixExpression)
{
	if (infixExpression.length() < 3)
	{
		return false;
	}
	else
	{
		return true;
	}
}


#endif