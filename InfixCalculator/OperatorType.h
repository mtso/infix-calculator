

enum OperatorType
{
	OPENING_PAREN,
	CLOSING_PAREN,
	ADDITION,
	SUBTRACTION,
	MULTIPLICATION,
	DIVISION
};

int precedenceOf(const char& test)
{
	switch (test)
	{
	case '(':
	case ')':
		return 2;
		
	case '*':
	case '/':
	//case '%':
		return 1;

	case '+':
	case '-':
		return 0;

	default:
		throw "Tried to test the precedence of a character that was not one of: ()*/%+-";
	}
}