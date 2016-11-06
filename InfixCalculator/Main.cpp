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
	string expression = "3*(3+3)*3";
	try {
		int result = infcalc.setInfixExp(expression);
		cout << "Final result: " << result << endl;
	}
	catch (string error) {
		cout << "Error setting expression: " << error << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}