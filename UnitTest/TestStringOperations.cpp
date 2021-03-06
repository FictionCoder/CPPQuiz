#include "stdafx.h"
#include "CppUnitTest.h"
#include "Common.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(TestStringOperations)
	{
	public:
		TEST_METHOD(TestToLower)
		{
			Assert::AreEqual(ToLower('A'), 'a');
			Assert::AreEqual(ToLower('a'), 'a');
			Assert::AreEqual(ToLower('!'), '!');
		}

		TEST_METHOD(TestToUpper)
		{
			Assert::AreEqual(ToUpper('a'), 'A');
			Assert::AreEqual(ToUpper('A'), 'A');
			Assert::AreEqual(ToUpper('!'), '!');
		}

		TEST_METHOD(TestStrCmp)
		{
			Assert::IsTrue(StrCmp("abc", "abc") == 0);
			Assert::IsTrue(StrCmp("", "") == 0);
			Assert::IsTrue(StrCmp("ab", "abc") < 0);
			Assert::IsTrue(StrCmp("Abc", "abc") < 0);
			Assert::IsTrue(StrCmp("", "abc") < 0);
			Assert::IsTrue(StrCmp("abc", "") > 0);
			// Unsigned char testing.
			char a[] = {-1, 0};			
			char b[] = {'a', 0};
			Assert::IsTrue(StrCmp(a, b) > 0);
		}

		TEST_METHOD(TestStrCmpN)
		{
			Assert::IsTrue(StrCmpN("abc", "abc", 0) == 0);
			Assert::IsTrue(StrCmpN("abC", "abc", 2) == 0);
			Assert::IsTrue(StrCmpN("abC", "abc", 3) < 0);
			Assert::IsTrue(StrCmpN("", "abc", 3) < 0);
			Assert::IsTrue(StrCmpN("abc", "", 3) > 0);
			Assert::IsTrue(StrCmpN("abc", "abC", 5) > 0);
		}

		TEST_METHOD(TestReverse)
		{
			char testSentence[] = "Sentence to be resevered";
			ReverseWordsInSentence(testSentence);
			Assert::IsTrue(strcmp(testSentence, "resevered be to Sentence") == 0);

			char testSentenceExtraSpaces[] = "  Sentence to  be resevered ";
			ReverseWordsInSentenceIgnoreSpaces(testSentenceExtraSpaces);
			Assert::IsTrue(strcmp(testSentenceExtraSpaces, " resevered be  to Sentence  ") == 0);
		}
	};
}


