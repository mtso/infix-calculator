// Operator.h
// Lab 3: Postfix Operations
// CIS 22C F2016: Adrian Marroquin, Matthew Tso

#ifndef OPERATOR_H
#define OPERATOR_H
#include <map>

using namespace std;

class Operator
{
private:
	map <char, int> precedences;

	//int precedence;


public:
	Operator();

	int precedence(char ch);
};

#endif