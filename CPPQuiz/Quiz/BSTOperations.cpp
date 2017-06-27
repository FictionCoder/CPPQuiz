#include "stdafx.h"
#include "BSTOperations.h"

namespace BST
{
	Node* CreateNode(Node* root, int data)
	{
		if (root == nullptr)
		{
			return new Node(data);
		}

		if (data < root->data)
		{
			if (nullptr == root->left)
			{
				root->left = new Node(data);
				return root->left;
			}
			else
			{
				return CreateNode(root->left, data);
			}
		}
		else
		{
			if (nullptr == root->right)
			{
				root->right = new Node(data);
				return root->right;
			}
			else
			{
				return CreateNode(root->right, data);
			}
		}
	}

	int GetDataLevel(const Node* root, int data);

	int Count(const Node* root)
	{
		if (nullptr == root)
		{
			return 0;
		}

		return 1 + Count(root->left) + Count(root->right);
	}

	int GetDepth(const Node* node)
	{
		if (nullptr == node)
		{
			return 0;
		}

		int leftDepth = GetDepth(node->left);
		int rightDepth = GetDepth(node->right);

		return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
	}

	void VisitPreorder(Node* node, VisitFunc callback)
	{
		if (nullptr == node)
		{
			return;
		}

		if (callback != nullptr)
		{
			callback(node);
		}

		VisitPreorder(node->left, callback);
		VisitPreorder(node->right, callback);
	}

	void VisitPostorder(Node* node, VisitFunc callback)
	{
		if (nullptr == node)
			return;

		VisitPostorder(node->left, callback);
		VisitPostorder(node->right, callback);

		if (callback != nullptr)
		{
			callback(node);
		}
	}

	void VisitInOrder(Node* node, VisitFunc callback)
	{
		if (nullptr == node)
			return;

		VisitInOrder(node->left, callback);

		if (callback != nullptr)
		{
			callback(node);
		}

		VisitInOrder(node->right, callback);
	}

	Node* Find(Node* root, int data)
	{
		if (root == nullptr)
		{
			return nullptr;
		}

		if (data == root->data)
		{
			return root;
		}
		else if (data < root->data)
		{
			return Find(root->left, data);
		}
		else
		{
			return Find(root->right, data);
		}
	}
}
