#include "stdafx.h"
#include "CppUnitTest.h"
#include "Common.h"
#include <functional>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(TestSortingOperations)
	{
	public:
		TEST_METHOD(TestBubleSort)
		{
			TestSortingAlgorithm(BubbleSort);
		}

		TEST_METHOD(TestQuickSort)
		{
			TestSortingAlgorithm(QuickSort);
		}

	private:
		void ValidateSortingResult(const vector<int>& arr)
		{
			Logger::WriteMessage("Start to validate array");
			string arrString;
			for (auto i = arr.cbegin(); i != arr.cend(); ++i)
			{
				arrString += to_string(*i);
				arrString += '\t';
				auto j = i + 1;
				if (j != arr.cend())
				{
					Assert::IsTrue(*i <= *j);
				}
			}

			Logger::WriteMessage(arrString.c_str());
		}

		void TestSortingAlgorithm(std::function<void(vector<int>&)> sortAlgorithm)
		{
			vector<int> arr;
			sortAlgorithm(arr);
			ValidateSortingResult(arr);

			arr.push_back(0);
			arr.push_back(1);
			arr.push_back(2);
			arr.push_back(3);
			sortAlgorithm(arr);
			ValidateSortingResult(arr);

			arr.clear();
			arr.push_back(3);
			arr.push_back(2);
			arr.push_back(1);
			arr.push_back(0);
			sortAlgorithm(arr);
			ValidateSortingResult(arr);


			arr.clear();
			arr.push_back(2);
			arr.push_back(0);
			arr.push_back(0);
			arr.push_back(1);
			arr.push_back(3);
			sortAlgorithm(arr);
			ValidateSortingResult(arr);

			arr.clear();
			arr.push_back(3);
			arr.push_back(2);
			arr.push_back(4);
			arr.push_back(2);
			arr.push_back(7);
			arr.push_back(11);
			sortAlgorithm(arr);
			ValidateSortingResult(arr);
		}
	};
}
