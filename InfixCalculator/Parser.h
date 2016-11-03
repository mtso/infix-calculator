// Lab 3: Infix Calculator
// CIS 22C F2016
// Adrian Marroquin, Matthew Tso

#ifndef INFIXCALCULATOR_PARSER_H
#define INFIXCALCULATOR_PARSER_H

#include <string>

namespace Parser 
{
	bool isSyntacticallyCorrect(const std::string& infixExpression);
}

#endif