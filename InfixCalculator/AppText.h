// InfoText.h
// Lab 3: Infix Calculator
// CIS 22C F2016: Adrian Marroquin, Matthew Tso

/**
 * Text constants used in main.
 */
#ifndef INFIXCALCULATOR_APPTEXT_H
#define INFIXCALCULATOR_APPTEXT_H

const char* OPTION_PLAIN_LONG = "--plain";
const char* OPTION_PLAIN_SHORT = "-p";
const char* COLOR_NORMAL = "COLOR 07";
const char* COLOR_LIGHT = "COLOR F5";
const char* PAUSE = "PAUSE";

const char* LOGO_TOP          = " \x0C9\x0BB\x0C9\x0CB\x0BB";
const char* LOGO_BOT          = " \x0CC\x0B9\x0BA\x0BA\x0BA";
const char* LOGO_TITLE        = "INSTRUMENTS";

const char* TEXT_INTRO        = " == AM-89 Infix Calculator ==\n"
                                " (H)elp to view available commands\n"
                                " (Q)uit to exit the program";
const char* TEXT_PROMPT       = " Enter an infix expression: ";
const char* TEXT_ERROR        = " > Invalid syntax, please try again.";
const char* TEXT_HELP         = " > (H)elp: View the available commands.\n"
                                " > (C)olor: Toggle fancy colors.\n"
								" > (I)nfo: View information about this calculator program.\n"
								" > (Q)uit: Exit the program.\n";
const char* TEXT_COLOR_ON     = " > Fancy colors on.";
const char* TEXT_COLOR_OFF    = " > Fancy colors off.";
const char* TEXT_INFO         = " > AM-89 is a command line infix calculator built by Adrian Marroquin and\n"
                                " > Matthew Tso for De Anza's CIS 22C in the Fall of 2016 taught by Professor\n"
								" > Manish Goel.\n";
const char* TEXT_QUIT         = " Bye bye-- See you next time :)";

#endif