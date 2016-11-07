// InfixConverter.h
// Lab 3: Postfix Operations
// CIS 22C F2016: Adrian Marroquin, Matthew Tso\

/**
* Converts an infix expression into postfix form
*/

#ifndef INFIXCALCULATOR_INFIXCONVERTER_CPP
#define INFIXCALCULATOR_INFIXCONVERTER_CPP

#include "InfixCalculator.h"

// Adrian's corner
string convertInfixToPostfix(const string& inputString)
{
	Stack<int> valueStack;
	Stack<char> operatorStack;
	string postfixExp;

	for (char current : inputString)
	{
		switch (current)
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			valueStack.push(atoi(&current));
			break;
		case '(':
			operatorStack.push(current);
			break;

		case '*':
		case '/':
		case '+':
		case '-':
			if (operatorStack.isEmpty()) {
				operatorStack.push(current);
			}
			else if (Operator::precedenceOf(current) > Operator::precedenceOf(operatorStack.peek())) {
				operatorStack.push(current);
			}
			else {
				while (!operatorStack.isEmpty() && Operator::precedenceOf(current) <= Operator::precedenceOf(operatorStack.peek())) {
					//performOperation();
				}
				operatorStack.push(current);
			}
			break;

		case ')':
			while (operatorStack.peek() != '(') {
				//performOperation();
			}
			operatorStack.pop();
			break;

		default:
			string errorMsg = "Unrecognized character passed to InfixCalculator: ";
			errorMsg += current;
			throw errorMsg;
		}
		// Display Current state of stacks
		// not implemented

		// PostFix Expression Builder
		if (valueStack.getLength() == 2 && operatorStack.getLength() == 1)
		{
			postfixExp.append(to_string(valueStack.pop()));
			postfixExp.append(to_string(valueStack.pop()));
			postfixExp.append(to_string(operatorStack.pop()));
		}
	}
	return postfixExp;
}
// End Adrian's Corner

int InfixCalculator::setInfixExp(const string& inputExpression)
{
	if (Parser::isSyntacticallyCorrect(inputExpression)) {
		infixExp = inputExpression;
		evaluateExpression();
		return result;
	}
	else {
		throw "Invalid syntax: " + inputExpression;
	}
}

int InfixCalculator::getResult() const
{
	return result;
}

string InfixCalculator::getInfixExp() const
{
	return infixExp;
}

void InfixCalculator::evaluateExpression()
{
	char current;

	for (int i = 0; i < (int)infixExp.length(); i++) {

		current = infixExp[i];
#ifdef DEBUG
		// DEBUGOUTPUT
		cout << "Evaluating: " << current << endl;
#endif

		if (isdigit(current)) {
			valueStack.push(atoi(&current));

#ifdef DEBUG
			// DEBUGOUTPUT
			cout << "valueStack top: " << valueStack.peek() << endl;
#endif
			continue;
		}

		// If the current is not a digit, it must be an operator.
		switch (current) {
		case '(':
			// Open paren is lowest precedence and is always pushed.
			operatorStack.push(current);
			break;
	
		case '*':
		case '/':
		case '+':
		case '-':
			// Makes sure precedence is respected if it is an arithmetic operator.
			safelyPushOperator(current);
			break;
	
		case ')':
			// Call performOperation until opening paren is encountered
			while (operatorStack.peek() != '(') {
				performOperation();
			}
			// Pop opening paren '(' off
			operatorStack.pop();
			break;
	
		default:
			string errorMsg = "Unrecognized character passed to InfixCalculator: ";
			errorMsg += current;
			throw errorMsg;
		}
	}

	while (!operatorStack.isEmpty()) {
		performOperation();
	}

	result = valueStack.peek();
}

void InfixCalculator::safelyPushOperator(const char& current)
{
	if (operatorStack.isEmpty()) {
		operatorStack.push(current);
	}
	else if (Operator::precedenceOf(current) > Operator::precedenceOf(operatorStack.peek())) {
		operatorStack.push(current);
	}
	else {
		while (!operatorStack.isEmpty() && Operator::precedenceOf(current) <= Operator::precedenceOf(operatorStack.peek())) {
			performOperation();
		}
		operatorStack.push(current);
	}
}

void InfixCalculator::performOperation()
{
	int operandRight = valueStack.pop();
	int operandLeft = valueStack.pop();
	char operatorChar = operatorStack.pop();
	int intermediaryResult;

	// TODO: Make an Operator class such that the following can replace the switch statement:
	// intermediaryResult = operatorChar.operateOn(operandLeft, operandRight);

	switch (operatorChar)
	{
	case '*':
		intermediaryResult = operandLeft * operandRight;
		break;

	case '/':
		intermediaryResult = operandLeft / operandRight;
		break;

	case '+':
		intermediaryResult = operandLeft + operandRight;
		break;

	case '-':
		intermediaryResult = operandLeft - operandRight;
		break;

	default:
		string errorMessage = "Attempted an invalid operation using: ";
		errorMessage += operatorChar;
		throw errorMessage;
	}

#ifdef DEBUG
	// DEBUGOUTPUT
	cout << "Left: " << operandLeft << ", Right: " << operandRight << ", Operator: " << operatorChar << endl;
	cout << "Intermediary result: " << intermediaryResult << endl;
#endif

	valueStack.push(intermediaryResult);
}

#endif