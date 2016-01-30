#pragma once

template<typename T>
class Node
{
public:
	Node(T value)
		:
		mData(value),
		Next(nullptr)
	{
	}

	T GetData()
	{
		return mData;
	}

	T GetData() const
	{
		return mData;
	}

	static Node<T>* ReverseLinkedList(Node<T>* pHead)
	{
		Node* pNewHead = nullptr;
		while (pHead != nullptr)
		{
			Node* pNext = pHead->Next;
			pHead->Next = pNewHead;
			pNewHead = pHead;
			pHead = pNext;
		}

		return pNewHead;
	}

public:
	Node<T>* Next;
private:
	T mData;
};