// Operator.h
// Lab 3: Infix Calculator
// CIS 22C F2016: Adrian Marroquin, Matthew Tso

#ifndef INFIXCALCULATOR_OPERATOR_H
#define INFIXCALCULATOR_OPERATOR_H

#include "OperatorPrecedence.h"

using namespace std;

/**
 * Operator object stores information about the
 * raw char value of the operator and precedence category.
 */
class Operator
{
private:
	char rawValue;
	OperatorPrecedence precedence;

public:
	/**
	 * Constructs an Operator object using the passed in char.
	 */
	Operator(const char& operatorChar);

	/**
	 * Returns the result of: operand1 (Operator) operand2
	 */
	int performOn(const int& operandLeft, const int& operandRight) const;

	/**
	 * @return int Operator's precedence when subtracted against input Operator
	 *  0 Equal precedence
	 *  1 Greater precedence
	 * -1 Lesser precedence
	 */
	int precedenceAgainst(const Operator& comparand) const;

	/**
	 * Applies operator== to raw char value.
	 */
	bool operator== (const Operator& right) const;

	/**
	 * Applies operator!= to raw char value.
	 */
	bool operator!= (const char& right) const;

	/**
	 * @return char value of operator
	 */
	char getRawValue() const;

	/**
	 * Applies the operator> to precedence.
	 */
	bool operator> (const Operator& right) const;

	/**
	 * Applies the operator<= to precedence.
	 */
	bool operator<= (const Operator& right) const;
};

#endif