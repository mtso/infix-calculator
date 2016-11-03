#include "stdafx.h"
#include "CppUnitTest.h"
#include "Main.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace InfixCalculatorTests
{		
	TEST_CLASS(InfixCalculator)
	{
	public:
		
		TEST_METHOD(TestLife)
		{
			// TODO: Your test code here
			Assert::AreEqual(42, getLife());
		}

	};
}