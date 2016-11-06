// Operator.h
// Lab 3: Postfix Operations
// CIS 22C F2016: Adrian Marroquin, Matthew Tso

#ifndef INFIXCALCULATOR_OPERATOR_H
#define INFIXCALCULATOR_OPERATOR_H

//#include "OperatorType.h"

using namespace std;

//class Operator
//{
//private:
//	char rawValue;
//	//int precedence;
//	//OperatorType type;
//
//public:
//	//Operator(const char& operatorChar);
//
//	//int operateOn(const int& operand1, const int& operand2);
//	//int precedence(char ch);
//};

namespace Operator {
	// Book's algorithm treats parens as operators with the lowest precedence
	int precedenceOf(const char& test);
}

#endif