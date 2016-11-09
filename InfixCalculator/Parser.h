// Parser.h
// Lab 3: Infix Calculator
// CIS 22C F2016: Adrian Marroquin, Matthew Tso

#ifndef INFIXCALCULATOR_PARSER_H
#define INFIXCALCULATOR_PARSER_H

#include <string>

namespace Parser 
{
	/**
	 * Evaluates a given arithmetic expression for valid infix syntax.
	 *
	 * Parsing rules:
	 * - Operands can only be single digit integers
	 * - Only binary operators * / + - are allowed.
	 * - Every opening paren must have a closing paren
	 * - Operands directly adjacent to the outside of a paren 
	 *   will not be assumed to mean multiplication.
	 *   (Which means that each opening paren must not have
	 *   an integer on its left side and must have an integer
	 *   or paren on its right side; vice versa for closing paren.)
	 *
	 * @param string input expression
	 * @return bool true if valid, false if not
	 */
	bool isSyntacticallyCorrect(const std::string& inputExpression);
}

#endif