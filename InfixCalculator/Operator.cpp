#ifndef INFIXCALCULATOR_OPERATOR_CPP
#define INFIXCALCULATOR_OPERATOR_CPP

#include "Operator.h"
//#include <string>
//#include <map>

//int Operator::precedence(char ch)
//{
//	return precedences[ch];
//}


template <int O>
OperatorClass::OperatorClass(const char& operatorChar) : rawValue(operatorChar)
{
	/*switch (O) {
	case '*':
		type = MULTIPLICATION;
		break;

	case '/':
		type = DIVISION;
		break;

	case '+':
		type = ADDITION;
		break;

	case '-':
		type = SUBTRACTION;
		break;

	case '(':
		type = OPENING_PAREN;
		break;

	case ')':
		type = CLOSING_PAREN;
		break;

	default:
		throw "Attempted construction of operator with character: " + operatorChar;
	}*/
	
	switch (operatorChar) {
	case '*':
		type = MULTIPLICATION;
		break;

	case '/':
		type = DIVISION;
		break;

	case '+':
		type = ADDITION;
		break;

	case '-':
		type = SUBTRACTION;
		break;

	case '(':
		type = OPENING_PAREN;
		break;

	case ')':
		type = CLOSING_PAREN;
		break;

	default:
		throw "Attempted construction of operator with character: " + operatorChar;
	}
}

template <int O>
int OperatorClass::operateOn(const int& operandLeft, const int& operandRight) const
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

template <int O>
int OperatorClass::precedenceAgainst(const OperatorClass& comparand) const
{
	return type - comparand.type;
}


int Operator::precedenceOf(const char& test)
{
	switch (test)
	{
	case '*':
	case '/':
		//case '%':
		return 2;

	case '+':
	case '-':
		return 1;

	case '(':
	case ')':
		return 0;

	default:
		throw "Tried to test the precedence of a character that was not one of: ()*/%+-";
	}
}



template <>
int OperatorClass<'*'>::operateOn(const int& operandLeft, const int& operandRight) const
{
	return operandLeft * operandRight;
}
#endif