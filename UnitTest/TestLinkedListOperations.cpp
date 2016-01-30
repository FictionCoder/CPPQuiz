#include "stdafx.h"
#include "CppUnitTest.h"
#include "Common.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(TestLinkedListOperations)
	{
		typedef Node<char> Node;
	public:
		TEST_METHOD(TestReverse)
		{
			Node A('A');
			Node B('B');
			Node C('C');
			Node D('D');

			A.Next = &B;
			B.Next = &C;
			C.Next = &D;

			PrintLinkedList(&A);

			Node* pReversedNode = Node::ReverseLinkedList(&A);
			std::string ret = PrintLinkedList(pReversedNode);

			Assert::IsTrue(ret.compare("DCBA") == 0);
		}
	private:
		std::string PrintLinkedList(const Node* pHead) const
		{
			Logger::WriteMessage("Linked list:");
			std::string ret;
			while (pHead != nullptr)
			{
				ret += pHead->GetData();
				pHead = pHead->Next;
			}
			Logger::WriteMessage(ret.c_str());
			return ret;
		}
	};
}