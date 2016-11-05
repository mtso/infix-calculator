#include "Operator.h"
#include <string>
#include <map>

Operator::Operator()
{
	precedences['+'] = 1;
	precedences['-'] = 1;
	precedences['*'] = 2;
	precedences['/'] = 2;
	precedences['('] = 3;
	precedences[')'] = 3;
}


int Operator::precedence(char ch)
{
	return precedences[ch];
}