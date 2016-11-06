#include "stdafx.h"
#include "CppUnitTest.h"
#include "InfixCalculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace InfixCalculatorTests
{
	TEST_CLASS(InfixCalculatorTests)
	{
	public:

		TEST_METHOD(Evaluate1p1)
		{
			InfixCalculator infcalc;
			infcalc.setInfixExp("1+1");
			Assert::AreEqual(2, infcalc.getResult());
		}

		TEST_METHOD(Evaluate3x3)
		{
			InfixCalculator infcalc;
			infcalc.setInfixExp("3x3");
			Assert::AreEqual(9, infcalc.getResult());
		}

		TEST_METHOD(Evaluate3x3p3x3)
		{
			InfixCalculator infcalc;
			infcalc.setInfixExp("3x(3+3)x3");
			Assert::AreEqual(54, infcalc.getResult());
		}

	};
}