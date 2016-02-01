#include "stdafx.h"
#include "CppUnitTest.h"
#include "Common.h"
#include <functional>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace BST;
using namespace std::placeholders;

namespace UnitTest
{
	TEST_CLASS(TestBSTOperations)
	{
	public:
		TEST_METHOD(TestCreate)
		{
			Node* root = CreateNode(nullptr, 0);
			CreateNode(root, 1);
			CreateNode(root, 2);
			CreateNode(root, 3);
			CreateNode(root, 4);

			Logger::WriteMessage("In order");
			VisitInOrder(root, std::bind(&TestBSTOperations::VisitCallback, this, _1));
			Logger::WriteMessage("Postorder");
			VisitPostorder(root, std::bind(&TestBSTOperations::VisitCallback, this, _1));
			Logger::WriteMessage("Preorder");
			VisitPreorder(root, std::bind(&TestBSTOperations::VisitCallback, this, _1));
		}

		TEST_METHOD(TestFind)
		{
			Node* root = CreateNode(nullptr, 5);
			CreateNode(root, 10);
			CreateNode(root, 23);
			CreateNode(root, 4);
			CreateNode(root, 8);
			CreateNode(root, -20);

			Logger::WriteMessage("In order");
			VisitInOrder(root, std::bind(&TestBSTOperations::VisitCallback, this, _1));

			Assert::AreEqual(Find(root, 5)->data, 5);
			Assert::AreEqual(Find(root, 23)->data, 23);
			Assert::AreEqual(Find(root, 8)->data, 8);
			Assert::IsTrue(Find(root, 1000) == nullptr);
		}

		TEST_METHOD(TestCountAndDepth)
		{
			Node* root = CreateNode(nullptr, 5);
			CreateNode(root, 10);
			CreateNode(root, 23);
			CreateNode(root, 4);
			CreateNode(root, 8);
			CreateNode(root, -20);

			Logger::WriteMessage("In order");
			VisitInOrder(root, std::bind(&TestBSTOperations::VisitCallback, this, _1));

			Assert::AreEqual(Count(root), 6);
			Assert::AreEqual(GetDepth(root), 3);
		}

	private:
		void VisitCallback(Node* node)
		{
			Logger::WriteMessage(std::to_string(node->data).c_str());
		}

	};
}
