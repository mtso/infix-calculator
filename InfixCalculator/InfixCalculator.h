// InfixCalculator.h
// Lab 3: Infix Calculator
// CIS 22C F2016: Adrian Marroquin, Matthew Tso

#ifndef INFIXCALCULATOR_INFIXCALCULATOR_H
#define INFIXCALCULATOR_INFIXCALCULATOR_H

#include <iostream>
#include <string>
#include "StackADT\Stack.h"
#include "Operator.h"
#include "Parser.h"

using namespace std;

/**
 * The InfixCalculator objects holds the stacks
 * and resulting value and postfix string conversion
 * of an infix expression input.
 *
 * evaluateExpression(), performOperation(), and 
 * safelyPushOperator(current:) are completely coupled.
 *
 * setInfixExp(inputExpression) is the entry point for 
 * the expression evaluation procedure.
 */
class InfixCalculator
{
private:
	/** Contains the integer terms */
	Stack<int> valueStack;

	/** Stack for Operator objects */
	Stack<Operator> operatorStack;
	
	/** Contains the most recent input expression. */
	string infixExp;
	
	/** Contains the most recent expression in postfix form. */
	string postfixExp;

	/** Stores the result of the evaluated infix expression */
	int result;

	/**
	 * Calculates the expression stored in infixExp. 
	 * SIDE-EFFECTS: 
	 *    Uses performOperation() to calculate the values at each
	 *    Operator pop() and safelyPushOperator(current:)
	 *    to push operators depending on precedence.
	 * string postfixExp created through character appends during these operations
	 * int result is set at the end
	 */
	void evaluateExpression();

	/**
	 * Pops and performs the top operator on the top two operands.
	 * Then pushes the result onto the integer stack.
	 * Appends the popped operator to the postfixExpression string.
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
	 * Takes in an input expression, evaluates it,
	 * and then stores and returns the result.
	 * If the input expression is valid, the postfixExp
	 * will be cleared in preparation to take in characters
	 * and infixExp set to the input string.
	 * 
	 * Calls evaluateExpression() once the expression is set.
	 *
	 * @throw char* the input expression if it is syntactically incorrect.
	 * @return int evaluated result.
	 */
	int setInfixExp(const string& inputExpression);

	/**
	 * @return int the result of the last-set input expression.
	 */
	int getResult() const;

	/**
	 * @return string the last-set input expression in infix form.
	 */
	string getInfixExp() const;

	/**
	 * @return string the postfix form of the last expression.
	 */
	string getPostfixExp() const;
};

#endif

