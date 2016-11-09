// Main.cpp
// Lab 3: Infix Calculator
// CIS 22C F2016: Adrian Marroquin, Matthew Tso

#include <cstdlib>
#include <iostream>
#include <string>

#include "InfixCalculator.h"
#include "AppText.h"

using namespace std;

/**
 * Toggles between a light and dark color scheme.
 */
bool toggleFancyMode();

/**
 * Creates command line process that allows the evaluation
 * of infix expressions until the user quits.
 *
 * Commands:
 * (H)elp
 * (C)olor
 * (I)nfo
 * (Q)uit
 * Default: [Input Expression String]
 */
int main(int argc, char** argv)
{

#ifndef DEBUG

	// Initialize Input/Output variables
	string inputExp;
	int result;
	char command;

	// Initialize calculator and logic options
	InfixCalculator calculator;
	bool fancyModeOption = true;
	bool shouldContinue = true;

	// Evaluate command line arguments
	string option;
	for (int i = 0; i < argc; i++) {
		option = argv[i];
		if (option == OPTION_PLAIN_LONG || option == OPTION_PLAIN_SHORT) {
			fancyModeOption = false;
		}
	}

	system(COLOR_NORMAL);
	if (fancyModeOption) {
		toggleFancyMode();

		// Output logo header
		cout << LOGO_TOP << endl;
		cout << LOGO_BOT << LOGO_TITLE 
			 << endl << endl;
	}

	cout << TEXT_INTRO << endl << endl;

	while (shouldContinue) {

		cout << TEXT_PROMPT;
		cin >> inputExp;
		command = inputExp[0];

		switch (toupper(command)) {
		case CMD_HELP:
			cout << TEXT_HELP << endl;
			break;

		case CMD_COLOR:
			fancyModeOption = toggleFancyMode();
			cout << (fancyModeOption ? TEXT_COLOR_ON : TEXT_COLOR_OFF) << endl;
			break;

		case CMD_INFO:
			cout << TEXT_INFO << endl;
			break;


		case CMD_QUIT:
			cout << TEXT_QUIT;
			cin >> command;
			cout << endl;

			shouldContinue = (toupper(command) == CMD_CONFIRM) ? false : true;
			break;

		default:
			// Evaluate the input if it wasn't a recognized command.
			try {
				result = calculator.setInfixExp(inputExp);
				cout << " > Postfix: " << calculator.getPostfixExp() << endl;
				cout << " > Result: " << result << endl << endl;
			}
			catch (string error) {
				cout << TEXT_ERROR << endl;
			}
		}

	}

	cout << endl << TEXT_FAREWELL << endl;
	system(COLOR_NORMAL);

#else

	system(COLOR_NORMAL);

	// DEBUGGING OUTPUT
	InfixCalculator infcalc;
	string testExpression = "3*(3+3)*3";
	try {
		int result = infcalc.setInfixExp(testExpression);
		cout << "Final result: " << result << endl;
		cout << infcalc.getPostfixExp() << endl;
	}
	catch (string error) {
		cout << TEXT_ERROR << error << endl;
	}

#endif

	cout << ' ';
	system(PAUSE);
	return 0;
}

bool toggleFancyMode()
{
	static bool isFancyMode = false;

	isFancyMode = !isFancyMode;
	isFancyMode ? system(COLOR_LIGHT) : system(COLOR_NORMAL);
	return isFancyMode;
}