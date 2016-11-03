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
			Assert::IsTrue(Parser::isSyntacticallyCorrect("1"));
		}

	};
}