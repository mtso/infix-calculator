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
			char* falseExp[EXP_ARRLEN * 2];

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
			falseExp[4] = "(1)-(3+)-9";
			falseExp[5] = "1+3(4/5)";
			falseExp[6] = "(1+)-(3+(4/5))-9";
			falseExp[7] = "2+2+";
			falseExp[8] = "*2+7";
			falseExp[9] = "(3/8";
			falseExp[10] = "3 4";
			falseExp[11] = "3 4";
			falseExp[12] = "3 4";
			falseExp[13] = "3 4";
			falseExp[14] = "3 4";
			falseExp[15] = "3 4";
			falseExp[16] = "3 4";
			falseExp[17] = "3 4";
			falseExp[18] = "3 4";
			falseExp[19] = "3 4";


			for (int i = 0; i < EXP_ARRLEN; i++) {
				Assert::IsTrue(Parser::isSyntacticallyCorrect(trueExp[i]));
			}

			for (int i = 0; i < EXP_ARRLEN * 2; i++) {
				Assert::IsFalse(Parser::isSyntacticallyCorrect(falseExp[i]));
			}
		}

	};
}