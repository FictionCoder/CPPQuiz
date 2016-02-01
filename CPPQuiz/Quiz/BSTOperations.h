#pragma once
#include <functional>
namespace BST
{
	class Node
	{
	public:
		Node(int nodeData) : data(nodeData), left(nullptr), right(nullptr){}
		Node(int nodeData, Node* leftNode, Node* rightNode) : data(nodeData), left(leftNode), right(rightNode){}
	public:
		int data;
		Node* left;
		Node* right;
	};

	typedef std::function<void(Node*)> VisitFunc;

	// Create a BST node under the root. If the root argument is nullptr, return a root node instead.
	Node* CreateNode(Node* root, int data);

	int GetDataLevel(const Node* root, int data);

	int Count(const Node* root);

	int GetDepth(const Node* node);

	void VisitPreorder(Node* node, VisitFunc callback);

	void VisitPostorder(Node* node, VisitFunc callback);

	void VisitInOrder(Node* node, VisitFunc callback);

	Node* Find(Node* root, int data);
}
