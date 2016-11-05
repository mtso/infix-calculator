#include "stdafx.h"
#include "CppUnitTest.h"
#include "Parser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace InfixCalculatorTests
{
	TEST_CLASS(ParserTest)
	{
	public:

		TEST_METHOD(ParseExpression)
		{
			const int EXP_ARRLEN = 10;

			char* trueExp[EXP_ARRLEN];
			char* falseExp[EXP_ARRLEN];

			trueExp[0] = "1+1";
			trueExp[1] = "4+(4*4)";
			trueExp[2] = "1+(3+4/5)*3";
			trueExp[3] = "(1+(3+4/5))*3";
			trueExp[4] = "(1)-(3+(4/5))-9";
			trueExp[5] = "1+1";
			trueExp[6] = "1+1";
			trueExp[7] = "1+1";
			trueExp[8] = "1+1";
			trueExp[9] = "1+1";

			falseExp[0] = "";
			falseExp[1] = "2++";
			falseExp[2] = "**3";
			falseExp[3] = "(1)+(3+4/5))*3";
			falseExp[4] = "(1)-(3+)-9";			// < TODO returns true
			falseExp[5] = "1+3(4/5)";
			falseExp[6] = "(1+)-(3+(4/5))-9";	// < TODO returns true
			falseExp[7] = "";
			falseExp[8] = "";
			falseExp[9] = "";

			for (int i = 0; i < EXP_ARRLEN; i++) {
				Assert::IsTrue(Parser::isSyntacticallyCorrect(trueExp[i]));
			}

			for (int i = 0; i < EXP_ARRLEN; i++) {
				Assert::IsFalse(Parser::isSyntacticallyCorrect(falseExp[i]));
			}
		}

	};
}