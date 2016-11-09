// InfixCalculator.cpp
// Lab 3: Infix Calculator
// CIS 22C F2016: Adrian Marroquin, Matthew Tso

#include "InfixCalculator.h"

int InfixCalculator::setInfixExp(const string& inputExpression)
{
	if (Parser::isSyntacticallyCorrect(inputExpression)) {
		infixExp = inputExpression;
		postfixExp = ""; // Clear the previous postfix expression
		evaluateExpression();
		return result;
	}
	else {
		throw "Invalid syntax: " + inputExpression;
	}
}

void InfixCalculator::evaluateExpression()
{
	char current;

	// Iterate through the infix expression
	for (int i = 0; i < (int)infixExp.length(); i++) 
	{
		current = infixExp[i];

#ifdef DEBUG
		cout << "Evaluating: " << current << endl;
#endif

		if (isdigit(current)) 
		{
			// Push the integer form of the operand onto the valueStack.
			valueStack.push(atoi(&current));

			// Append the character form of the operand to postfix string.
			postfixExp += current;

#ifdef DEBUG
			cout << "valueStack top: " << valueStack.peek() << endl;
#endif
			continue;
		}

		// If the current is not a digit, it must be an operator.
		switch (current) 
		{
		case '(':
			// Open paren is lowest precedence and is always pushed.
			operatorStack.push(Operator(current));
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

	// Pop remaining operators after the entire expression has been pushed
	while (!operatorStack.isEmpty()) 
	{
		performOperation();
	}

	// If peek() was used, the valueStack would contain a 
	// history of the calculations underneath the top value.
	result = valueStack.pop();
}

void InfixCalculator::safelyPushOperator(const char& currentChar)
{
	Operator op = Operator(currentChar);

	if (operatorStack.isEmpty()) {
		operatorStack.push(op);
	}
	else if (op > operatorStack.peek()) {
		operatorStack.push(op);
	}
	else {
		while (!operatorStack.isEmpty() && op <= operatorStack.peek()) {
			performOperation();
		}
		// Push operator after operators of greater or equal 
		// precedence have been popped or if none are left.
		operatorStack.push(op);
	}
}

void InfixCalculator::performOperation()
{
	int right = valueStack.pop();
	int left = valueStack.pop();
	Operator operation = operatorStack.pop();
	int result;

	result = operation.performOn(left, right);

#ifdef DEBUG
	cout << "Left: " << left << ", Right: " << right << ", Operator: " << operation.getRawValue() << endl;
	cout << "Intermediary result: " << result << endl;
#endif

	valueStack.push(result);

	// Append operator to postfix expression after each operand evaluation.
	postfixExp += operation.getRawValue();
}

// ACCESSORS

int InfixCalculator::getResult() const
{
	return result;
}

string InfixCalculator::getInfixExp() const
{
	return infixExp;
}

string InfixCalculator::getPostfixExp() const
{
	return postfixExp;
}