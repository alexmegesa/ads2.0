#include "BinaryTree.h"
#include <random>

BinaryTree::~BinaryTree()
{
	deleteSubTree(m_root);
}

Node* BinaryTree::getRoot()
{
	return m_root;
}

Node* BinaryTree::addNode(Node* startNode, const int key)
{	
	if (startNode == nullptr)
	{
		if (m_root == nullptr)
		{
			m_root = new Node(key);
			return m_root;
		}
		else
			return nullptr;
	}

	if (startNode->leftChild == nullptr)
	{
		startNode->leftChild = new Node(key);
		return startNode->leftChild;
	}

	else if (startNode->rightChild == nullptr)
	{
		startNode->rightChild = new Node(key);
		return startNode->rightChild;

	}

	else
	{
		if (rand() % 2)
		{
			return addNode(startNode->leftChild, key);
		}
		else
		{
			return addNode(startNode->rightChild, key);
		}
	}
}

void BinaryTree::deleteSubTree(Node* subTreeRoot)
{
	if (subTreeRoot)
	{
		deleteSubTree(subTreeRoot->leftChild);
		deleteSubTree(subTreeRoot->rightChild);
		delete subTreeRoot;
		if (subTreeRoot == m_root)
		{
			m_root = nullptr;
		}
	}
}

void BinaryTree::clearingTree()
{	
	deleteSubTree(m_root);
}

bool BinaryTree::isEmpty()
{
	return m_root == nullptr;
}

int BinaryTree::height(Node *subTreeRoot)
{	
	if (subTreeRoot)
	{
		int left = height(subTreeRoot->leftChild);
		int right = height(subTreeRoot->rightChild);

		if (left > right)
			return left + 1;
		else
			return right + 1;
	}

	return 0;

}

int BinaryTree::height()
{
	return height(m_root);
}

int BinaryTree::countNodes(Node* subTreeRoot)
{
	int count = 0;

	if (subTreeRoot)
	{	
		count++;
		count += countNodes(subTreeRoot->leftChild);
		count += countNodes(subTreeRoot->rightChild);
		return count;
		
	}

	return 0;

	
}

int BinaryTree::countNodes()
{
	return countNodes(m_root);
}

void BinaryTree::printHorizontal()
{
	printHorizontal(m_root);
}

void BinaryTree::printHorizontal(Node* startNode, const int level)
{
	if (startNode == nullptr)
	{	
		if (startNode == m_root)
		{
			cout << "Tree is empty" << endl;
		}
		
		return;
	}

	printHorizontal(startNode->rightChild, level + 1);
	for (int i = 0; i < level; i++)
		cout << "    ";
	cout << startNode->key << endl;
	printHorizontal(startNode->leftChild, level + 1);


}

void BinaryTree::printLevel(const int level)
{
	printLevel(m_root, level, 0);
}

void BinaryTree::printLevel(Node* startNode, const int level, const int currentLevel)
{

	if (startNode == nullptr)
	{
		if (startNode == m_root)
		{
			cout << "Tree is empty" << endl;
		}

		return;
	}

	if (currentLevel == level)
	{
		cout << startNode->key << "    ";
	}
	else if (currentLevel < level)
	{
		printLevel(startNode->leftChild, level, currentLevel + 1);
		printLevel(startNode->rightChild, level, currentLevel + 1);
	}
}
