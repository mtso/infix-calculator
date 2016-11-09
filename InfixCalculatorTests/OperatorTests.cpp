#include "stdafx.h"
#include "CppUnitTest.h"
#include "Operator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace InfixCalculatorTests
{
	TEST_CLASS(OperatorTests)
	{
	public:

		TEST_METHOD(Addition) {
			Operator add = '+';

			Assert::AreEqual('+', add.getRawValue());
			Assert::AreEqual(5, add.performOn(2, 3));
		}

		TEST_METHOD(Subtraction) {
			Operator minus = '-';

			Assert::AreEqual('-', minus.getRawValue());
			Assert::AreEqual(-1, minus.performOn(2, 3));
		}

		TEST_METHOD(Division) {
			Operator divide = '/';

			Assert::AreEqual('/', divide.getRawValue());
			Assert::AreEqual(1, divide.performOn(3, 3));
		}

		TEST_METHOD(Multiplication) {
			Operator multiply = '*';

			Assert::AreEqual('*', multiply.getRawValue());
			Assert::AreEqual(6, multiply.performOn(2, 3));
		}

		TEST_METHOD(OpenParen) {
			Operator openP = '(';

			Assert::AreEqual('(', openP.getRawValue());

			try {
				openP.performOn(2, 3);
			}
			catch (char* error) {
				Assert::AreEqual("Attempted construction of operator with character: (", error);
			}
			catch (...) {
				Assert::Fail();
			}
		}

		TEST_METHOD(ClosingParen) {
			Operator closingP = ')';

			Assert::AreEqual(')', closingP.getRawValue());

			try {
				closingP.performOn(2, 3);
			}
			catch (char* error) {
				Assert::AreEqual("Attempted construction of operator with character: )", error);
			}
			catch (...) {
				Assert::Fail();
			}
		}
	};
}