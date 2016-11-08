// Operator.h
// Lab 3: Postfix Operations
// CIS 22C F2016: Adrian Marroquin, Matthew Tso

#ifndef INFIXCALCULATOR_OPERATOR_H
#define INFIXCALCULATOR_OPERATOR_H

#include "OperatorPrecedence.h"

using namespace std;


class Operator
{
private:
	char rawValue;
	OperatorPrecedence precedence;

public:
	Operator(const char& operatorChar);

	/**
	 * Returns the result of: operand1 (Operator) operand2
	 */
	int performOn(const int& operandLeft, const int& operandRight) const;

	/**
	 * Returns:
	 *  0 Equal precedence
	 *  1 Greater precedence
	 * -1 Lesser precednce
	 */
	int precedenceAgainst(const Operator& comparand) const;

	bool operator== (const Operator& right) const;

	bool operator!= (const char& right) const;

	char getRawValue() const;

	bool operator> (const Operator& right) const;

	bool operator<= (const Operator& right) const;
};

#endif