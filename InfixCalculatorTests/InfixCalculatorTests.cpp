#include "stdafx.h"
#include "CppUnitTest.h"
#include "InfixCalculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace InfixCalculatorTests
{
	TEST_CLASS(InfixCalculatorTests)
	{
	public:

		TEST_METHOD(EvaluateExpression)
		{
			InfixCalculator infcalc;
			infcalc.setInfixExp("1+1");
			Assert::AreEqual(3, infcalc.getResult());
		}

	};
}