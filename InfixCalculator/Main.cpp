#include <iostream>
#include <string>

#include "InfixCalculator.h"

using namespace std;

bool toggleFancyMode();

int main(int argc, char** argv)
{

#ifndef DEBUG

	bool fancyModeOption = true;
	bool shouldContinue = true;
	string inputExp;
	InfixCalculator calculator;
	int result;
	char command;

	string option;
	for (int i = 0; i < argc; i++) {
		option = argv[i];
		if (option == "--plain" || option == "-p") {
			fancyModeOption = false;
		}
	}

	system("COLOR 07");
	if (fancyModeOption) {
		toggleFancyMode();

		string fancyFirst  = " \x0C9\x0BB\x0C9\x0CB\x0BB";
		string fancySecond = " \x0CC\x0B9\x0BA\x0BA\x0BA";
		fancySecond.append("INSTRUMENTS");

		cout << fancyFirst  << endl;
		cout << fancySecond << endl << endl;
	}

	cout << " == AM-89 Infix Calculator ==" << endl;
	cout << " (H)elp to view available commands\n (Q)uit to exit the program" << endl << endl;

	while (shouldContinue) {

		cout << " Enter an infix expression: ";
		cin >> inputExp;
		command = inputExp[0];

		switch (toupper(command)) {
		case 'H':
			cout << " > (H)elp: View the available commands." << endl
				<< " > (C)olor: Toggle fancy colors." << endl
				<< " > (I)nfo: View information about this calculator program." << endl
				<< " > (Q)uit: Exit the program." << endl;
			break;

		case 'C':
			fancyModeOption = toggleFancyMode();
			cout << (fancyModeOption ? " > Fancy colors on." : " > Fancy colors off.") << endl;
			break;

		case 'I':
			cout << " > AM-89 is a command line infix calculator built by Adrian Marroquin and " << endl
				<< " > Matthew Tso for De Anza's CIS 22C in the Fall of 2016 taught by Professor " << endl
				<< " > Manish Goel." << endl;
			break;

		case 'Q':
			shouldContinue = false;
			break;

		default:
			// Evaluate the input if it wasn't a recognized command.
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

	system("COLOR 07");

	// DEBUGOUTPUT ROUTINE
	InfixCalculator infcalc;
	string expression = "3*(3+3)*3";
	try {
		int result = infcalc.setInfixExp(expression);
		cout << "\x1b[6m Final result: " << result << endl;
	}
	catch (string error) {
		cout << "Error setting expression: " << error << endl;
	}

#endif

	cout << ' ';
	system("pause");
	return 0;
}

bool toggleFancyMode()
{
	static bool isFancyMode = false;

	isFancyMode = !isFancyMode;
	isFancyMode ? system("COLOR F5") : system("COLOR 07");
	return isFancyMode;
}