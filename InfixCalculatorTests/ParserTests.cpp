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
			// TODO: Your test code here
			Assert::IsFalse(Parser::isSyntacticallyCorrect(""));
			Assert::IsTrue(Parser::isSyntacticallyCorrect("1+1"));
			
			char* test = "1++";
			Assert::IsFalse(Parser::isSyntacticallyCorrect(test));


			Assert::IsFalse(Parser::isSyntacticallyCorrect("1+3(4/5)"));
			Assert::IsTrue(Parser::isSyntacticallyCorrect("1+(3+4/5)*3"));

			Assert::IsTrue(Parser::isSyntacticallyCorrect("(1+(3+4/5))*3"));

		}

	};
}