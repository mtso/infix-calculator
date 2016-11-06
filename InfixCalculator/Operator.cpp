#ifndef INFIXCALCULATOR_OPERATOR_CPP
#define INFIXCALCULATOR_OPERATOR_CPP

#include "Operator.h"
//#include <string>
//#include <map>

//Operator::Operator(const char& operatorChar) : rawValue(operatorChar)
//{
//
//}


//int Operator::precedence(char ch)
//{
//	return precedences[ch];
//}

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

#endif