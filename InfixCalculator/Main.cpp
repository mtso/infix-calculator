#include <iostream>
#include <string>

#include "InfixCalculator.h"

using namespace std;

int main(int argc, char** argv)
{
	//string infixExp;
	//cout << "Echo an infix expression: ";
	//cin >> infixExp;
	//for (int i = 0; i < infixExp.length(); i++)
	//{
	//	cout << infixExp[i];
	//}

	// DEBUGOUTPUT ROUTINE
	InfixCalculator infcalc;
	bool isValidSyntax = infcalc.setInfixExp("3*3");
	if (isValidSyntax) {
		int result = infcalc.getResult();
		cout << "Final result: " << result << endl;
	}
	else {
		cout << "Invalid syntax: " << infcalc.getInfixExp() << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}