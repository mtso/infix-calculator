#ifndef INFIXCALCULATOR_OPERATOR_CPP
#define INFIXCALCULATOR_OPERATOR_CPP

#include "Operator.h"

Operator::Operator(const char& operatorChar) : rawValue(operatorChar)
{
	switch (operatorChar) {
	case '*':
	case '/':
		precedence = MULTI_DIVIDE;
		break;

	case '+':
	case '-':
		precedence = ADD_SUBTRACT;
		break;

	case '(':
	case ')':
		precedence = PARENTHESES;
		break;

	default:
		throw "Attempted construction of operator with character: " + operatorChar;
	}
}

int Operator::operateOn(const int& operandLeft, const int& operandRight) const
{
	switch (rawValue) {
	case '*':
		return operandLeft * operandRight;
		
	case '/':
		return operandLeft / operandRight;

	case '+':
		return operandLeft + operandRight;

	case '-':
		return operandLeft - operandRight;

	default:
		throw "Invalid operation attempted with " + rawValue;
	}
}

int Operator::precedenceAgainst(const Operator& comparand) const
{
	return precedence - comparand.precedence;
}

bool Operator::operator== (const Operator& right) const
{
	return rawValue == right.rawValue;
}

bool Operator::operator!= (const char& right) const
{
	return rawValue != right;
}

char Operator::getRawValue() const
{
	return rawValue;
}

#endif