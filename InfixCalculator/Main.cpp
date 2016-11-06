#include <iostream>
#include <string>

#include "InfixCalculator.h"

using namespace std;

int main(int argc, char** argv)
{

#ifndef DEBUG

	bool fancyMode = true;
	bool shouldContinue = true;
	string inputExp;
	InfixCalculator calculator;
	int result;

	string option;
	for (int i = 0; i < argc; i++) {
		option = argv[i];
		if (option == "--plain" || option == "-p" || option == "--debug" || option == "-d") {
			fancyMode = false;
		}
	}

	system("COLOR 07");
	if (fancyMode) {
		system("COLOR F5");

		string fancyFirst = " \x0C9\x0BB\x0C9\x0CB\x0BB";
		string fancySecond = " \x0CC\x0B9\x0BA\x0BA\x0BA";
		fancySecond.append("INDUSTRIES");

		cout << fancyFirst << endl;
		cout << fancySecond << endl << endl;
		cout << " == AM-89 Infix Calculator ==" << endl;
	}

	cout << " (H)elp to view available commands\n (Q)uit to exit the program" << endl << endl;

	while (shouldContinue) {

		cout << " Enter an infix expression: ";
		cin >> inputExp;

		if (toupper(inputExp[0]) == 'Q') {
			shouldContinue = false;
			break;
		}
		else if (toupper(inputExp[0]) == 'H') {
			cout << " > Enter (h)elp for the available commands or (q)uit to exit the program." << endl;
		}
		else {

			try {
				result = calculator.setInfixExp(inputExp);
				cout << " > Result: " << result << endl;
			}
			catch (string error) {
				cout << " > Invalid syntax, please try again." << endl;
			}
		}

	}

	cout << endl << " Bye bye-- See you next time :)" << endl;
	system("COLOR 07");

#else

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

#endif

	cout << ' ';
	system("pause");
	return 0;
}