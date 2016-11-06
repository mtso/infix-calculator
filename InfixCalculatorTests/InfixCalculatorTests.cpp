#include "stdafx.h"
#include "CppUnitTest.h"
#include "InfixCalculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace InfixCalculatorTests
{
	TEST_CLASS(InfixCalculatorTests)
	{
	public:

		// names
		// x = *
		// d = /
		// p = +
		// m = -

		TEST_METHOD(Evaluate1p1)
		{
			InfixCalculator infcalc;
			infcalc.setInfixExp("1+1");
			Assert::AreEqual(2, infcalc.getResult());
		}

		TEST_METHOD(Evaluate3x3)
		{
			InfixCalculator infcalc;
			infcalc.setInfixExp("3*3");
			Assert::AreEqual(9, infcalc.getResult());
		}

		TEST_METHOD(Evaluate3x3p3x3)
		{
			InfixCalculator infcalc;
			infcalc.setInfixExp("3*(3+3)*3");
			Assert::AreEqual(54, infcalc.getResult());
		}
		
		TEST_METHOD(Evaluate1p3p4d5x3)
		{
			InfixCalculator infcalc;
			infcalc.setInfixExp("1+(3+4/5)*3");
			Assert::AreEqual(10, infcalc.getResult());
		}

		TEST_METHOD(Evaluate1p3p4d5x3withExtraParens)
		{
			InfixCalculator infcalc;
			infcalc.setInfixExp("(1+(3+4/5))*3");
			Assert::AreEqual(12, infcalc.getResult());
		}

		TEST_METHOD(Evaluate1m3p4d5m9)
		{
			InfixCalculator infcalc;
			infcalc.setInfixExp("(1)-(3+(4/5))-9");
			Assert::AreEqual(-11, infcalc.getResult());
		}

		TEST_METHOD(Evaluate1p1x3d4m6p2d6x3p9m8d7d5p3m2m1)
		{
			InfixCalculator infcalc;
			infcalc.setInfixExp("((1+1*(3/4-(6+2/6*3)+(9-8/7))/5+3)-2)*1");
			Assert::AreEqual(2, infcalc.getResult());
		}

		TEST_METHOD(Evaluate1p1m0x3d4m6p2d6x3p0x9m8d7d5p3m2m1)
		{
			InfixCalculator infcalc;
			infcalc.setInfixExp("((1+1-0*(3/4-(6+2/6*3)+(0*(9-8)/7))/5+3)-2)*1");
			Assert::AreEqual(3, infcalc.getResult());
		}
	};
}