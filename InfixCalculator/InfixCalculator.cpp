// InfixConverter.h
// Lab 3: Postfix Operations
// CIS 22C F2016: Adrian Marroquin, Matthew Tso\

/**
* Converts an infix expression into postfix form
*/

#ifndef INFIXCALCULATOR_INFIXCONVERTER_CPP
#define INFIXCALCULATOR_INFIXCONVERTER_CPP

#include "InfixCalculator.h"

bool InfixCalculator::setInfixExp(const string& inputExpression)
{
	infixExp = inputExpression;

	if (Parser::isSyntacticallyCorrect(infixExp)) {
		evaluateExpression();
		return true;
	}
	else {
		return false;
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

		// DEBUGOUTPUT
		cout << "Evaluating: " << current << endl;

		switch (current) {
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
			// DEBUGOUTPUT
			cout << "valueStack top: " << valueStack.peek() << endl;
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
					performOperation();
				}
				operatorStack.push(current);
			}
			break;
	
		case ')':
			while (operatorStack.peek() != '(') {
				performOperation();
			}
			operatorStack.pop();
	
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

void InfixCalculator::performOperation()
{
	int operandRight = valueStack.pop();
	int operandLeft = valueStack.pop();

	char operatorChar = operatorStack.pop();

	int intermediaryResult;
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

	// DEBUGOUTPUT
	cout << "Left: " << operandLeft << ", Right: " << operandRight << ", Operator: " << operatorChar << endl;
	cout << "Intermediary result: " << intermediaryResult << endl;

	valueStack.push(intermediaryResult);
}

#endif