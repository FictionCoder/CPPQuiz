#include "stdafx.h"
#include "CppUnitTest.h"
#include "Common.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(TestBinaryOperation)
	{
	public:
		
		TEST_METHOD(TestIsPowerOf2)
		{			
			Assert::IsTrue(IsPowerOf2(0));
			Assert::IsTrue(IsPowerOf2(1));
			Assert::IsTrue(IsPowerOf2(1<<4));
			Assert::IsFalse(IsPowerOf2(3));
			Assert::IsFalse(IsPowerOf2(211));
		}

		TEST_METHOD(TestCountBit)
		{
			Assert::AreEqual(CountBit(0), 0);
			Assert::AreEqual(CountBit(1), 1);
			Assert::AreEqual(CountBit(3), 2);
			Assert::AreEqual(CountBit(8), 1);
			Assert::AreEqual(CountBit(0xf), 4);
			Assert::AreEqual(CountBit(0xe0f), 7);
		}
	};
}

