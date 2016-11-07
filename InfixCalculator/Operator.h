// Operator.h
// Lab 3: Postfix Operations
// CIS 22C F2016: Adrian Marroquin, Matthew Tso

#ifndef INFIXCALCULATOR_OPERATOR_H
#define INFIXCALCULATOR_OPERATOR_H

#include "OperatorType.h"

using namespace std;

template <int O>
class OperatorClass
{
private:
	char rawValue;
	OperatorType type;

public:
	OperatorClass(const char& operatorChar);

	/**
	 * Returns the result of: operand1 (Operator) operand2
	 */
	int operateOn(const int& operandLeft, const int& operandRight) const;

	/**
	 * Returns:
	 *  0 Equal precedence
	 *	1 Greater precedence
	 * -1 Lesser precednce
	 */
	int precedenceAgainst(const OperatorClass& comparand) const;
};

template <>
class OperatorClass<'*'>
{
	int operateOn(const int& operandLeft, const int& operandRight) const;
};

namespace Operator {
	// Book's algorithm treats parens as operators with the lowest precedence
	int precedenceOf(const char& test);
}

#endif