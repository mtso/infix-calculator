// OperatorPrecedence.h
// Lab 3: Infix Calculator
// CIS 22C F2016: Adrian Marroquin, Matthew Tso

#ifndef INFIXCALCULATOR_OPERATORTYPE_H
#define INFIXCALCULATOR_OPERATORTYPE_H

/**
 * Defines three classes of operator precedence.
 * Parentheses are considered to be the lowest
 * precedence according to the book's algorithm.
 */
enum OperatorPrecedence
{
	PARENTHESES = 0,
	ADD_SUBTRACT = 1,
	MULTI_DIVIDE = 2,
};

#endif