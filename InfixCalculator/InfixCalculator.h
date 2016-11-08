// InfixConverter.h
// Lab 3: Postfix Operations
// CIS 22C F2016: Adrian Marroquin, Matthew Tso\

/**
 * Converts an infix expression into postfix form
 */

#ifndef INFIXCALCULATOR_INFIXCALCULATOR_H
#define INFIXCALCULATOR_INFIXCALCULATOR_H

#include <iostream>
#include <string>
#include "\ADTLibrary\Stack.h"
#include "Operator.h"
#include "Parser.h"

using namespace std;

// Takes a minimal infix expression and returns equivalenent postfix expression
string convertInfixToPostfix(const string& inputString);

class InfixCalculator
{
private:
	Stack<int> valueStack;
	Stack<Operator> operatorStack;
	string infixExp;
	string postfixExp;

	// Stores the result of the evaluated infix expression
	int result;

	/**
	 * Calculates the expression stored in infixExp.
	 */
	void evaluateExpression();

	/**
	 * Pops and performs the top operator on the top two operands.
	 * Then pushes the result onto the integer stack.
	 */
	void performOperation();

	/**
	 * Pushes an operator onto the operator stack.
	 * Makes sure that all operators of greater precedence
	 * before it are properly popped and evaluated.
	 */
	void safelyPushOperator(const char& current);

public:
	/**
	 * Takes in an input expression, then evaluates it,
	 * and then stores and returns the result.
	 * Will throw if the input expression is syntactically incorrect.
	 */
	int setInfixExp(const string& inputExpression);

	/**
	 * Returns the result of the last-set input expression.
	 */
	int getResult() const;

	/**
	 * Returns the last-set input expression in infix form.
	 */
	string getInfixExp() const;

	string getPostfixExp() const;
};

#endif