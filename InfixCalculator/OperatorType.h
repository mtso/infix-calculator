// OperatorType.h
// Lab 3: Postfix Operations
// CIS 22C F2016: Adrian Marroquin, Matthew Tso

enum OperatorType
{
	OPENING_PAREN,
	CLOSING_PAREN,
	ADDITION,
	SUBTRACTION,
	MULTIPLICATION,
	DIVISION
};

// Book's algorithm treats parens as operators with the lowest precedence
int precedenceOf(const char& test)
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