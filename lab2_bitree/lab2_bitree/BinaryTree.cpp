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

Node* BinaryTree::findParentByKey(Node* subTreeRoot, const int key)
{
	if (m_root->key == key && m_root)
	{
		return nullptr;
	}

	if (subTreeRoot)
	{
		if (subTreeRoot->leftChild || subTreeRoot->rightChild)
		{
			if ((subTreeRoot->leftChild && subTreeRoot->leftChild->getKey() == key) || (subTreeRoot->rightChild && subTreeRoot->rightChild->getKey()) == key)
			{
				return subTreeRoot;
			}
			else
			{
				Node* left = findParentByKey(subTreeRoot->leftChild, key);
				Node* right = findParentByKey(subTreeRoot->rightChild, key);

				if (left)
					return left;

				if (right)
					return right;


			}
		}
	}



	return nullptr;
}

Node* BinaryTree::findParentByKey(const int key)
{
	return findParentByKey(m_root, key);
}

Node* BinaryTree::findNodeByKey(Node* subTreeRoot, const int key)
{
	if (subTreeRoot)
	{
		if (subTreeRoot->getKey() == key)
		{
			return subTreeRoot;
		}

		else
		{
			Node* left = findNodeByKey(subTreeRoot->leftChild, key);
			Node* right = findNodeByKey(subTreeRoot->rightChild, key);

			if (left && left->getKey() == key)
			{
				return left;
			}

			if (right && right->getKey() == key)
			{
				return right;
			}

			return nullptr;
		}
	}

	return nullptr;
}

Node* BinaryTree::findNodeByKey(const int key)
{
	return findNodeByKey(m_root, key);
}

Node* BinaryTree::emptyNodeChild(Node* subTreeRoot)
{
	if (subTreeRoot == nullptr)
	{
		cerr << "error: Tree is empty";
	}

	if (subTreeRoot->leftChild == nullptr || subTreeRoot->rightChild == nullptr)
	{
		return subTreeRoot;
	}

	else
	{
		int heightLeft = height(subTreeRoot->leftChild);
		int heightRight = height(subTreeRoot->rightChild);

		if (heightLeft < heightRight)
		{
			return emptyNodeChild(subTreeRoot->leftChild);
		}

		else if (heightLeft > heightRight)
		{
			return emptyNodeChild(subTreeRoot->rightChild);
		}

		else
		{
			int countLeft = countNodes(subTreeRoot->leftChild);
			int countRight = countNodes(subTreeRoot->rightChild);
			if (countLeft < countRight)
			{
				return emptyNodeChild(subTreeRoot->leftChild);
			}
			else
			{
				return emptyNodeChild(subTreeRoot->rightChild);
			}
		}
	}
}

bool BinaryTree::deleteNode(Node* nodeToDelete)
{	

	if (nodeToDelete == nullptr)
	{
		cerr << "error: empty node" << endl;
		return false;
	}


	if (nodeToDelete->leftChild == nullptr && nodeToDelete->rightChild == nullptr)
	{
		Node* parent = findParentByKey(nodeToDelete->getKey());

		if (parent)
		{
			if (parent->leftChild == nodeToDelete)
			{
				parent->leftChild == nullptr;
			}
			if (parent->rightChild == nodeToDelete)
			{
				parent->rightChild == nullptr;
			}
		}
		else
		{
			m_root == nullptr;
		}

		delete nodeToDelete;

		return true;

	}

	if (nodeToDelete->leftChild == nullptr && nodeToDelete->rightChild != nullptr)
	{
		Node* parent = findParentByKey(nodeToDelete->getKey());

		if (parent)
		{
			if (parent->leftChild == nodeToDelete)
				parent->leftChild = nodeToDelete->rightChild;

			if (parent->rightChild == nodeToDelete)
				parent->rightChild = nodeToDelete->rightChild;
		}

		else
		{
			m_root = nodeToDelete->rightChild;
		}

		delete nodeToDelete;

		return true;
	}

	if (nodeToDelete->leftChild != nullptr && nodeToDelete->rightChild == nullptr)
	{
		Node* parent = findParentByKey(nodeToDelete->getKey());

		if (parent)
		{
			if (parent->leftChild == nodeToDelete)
				parent->leftChild = nodeToDelete->leftChild;

			if (parent->rightChild == nodeToDelete)
				parent->rightChild = nodeToDelete->leftChild;
		}

		else
		{
			m_root = nodeToDelete->leftChild;
		}

		delete nodeToDelete;

		return true;
	}

	if (nodeToDelete->leftChild != nullptr && nodeToDelete->rightChild != nullptr)
	{
		Node* parent = findParentByKey(nodeToDelete->getKey());

		if (parent)
		{
			if (parent->leftChild == nodeToDelete)
			{
				parent->leftChild = nodeToDelete->leftChild;
				Node* nodeWithEmptyChild = emptyNodeChild(parent);

				if (nodeWithEmptyChild->rightChild == nullptr)
				{
					nodeWithEmptyChild->rightChild = nodeToDelete->rightChild;
				}
				else
				{
					nodeWithEmptyChild->leftChild = nodeToDelete->rightChild;
				}

			}

			if (parent->rightChild == nodeToDelete)
			{
				parent->rightChild = nodeToDelete->rightChild;
				Node* nodeWithEmptyChild = emptyNodeChild(parent);

				if (nodeWithEmptyChild->leftChild == nullptr)
				{
					nodeWithEmptyChild->leftChild = nodeToDelete->leftChild;
				}
				else
				{
					nodeWithEmptyChild->rightChild = nodeToDelete->leftChild;
				}
			}
		}
		else
		{
			m_root = nodeToDelete->leftChild;
			Node* nodeWithEmptyChild = emptyNodeChild(m_root);

			if (nodeWithEmptyChild->rightChild == nullptr)
			{
				nodeWithEmptyChild->rightChild = nodeToDelete->rightChild;
			}

			else
			{
				nodeWithEmptyChild->leftChild = nodeToDelete->rightChild;
			}
		}

		delete nodeToDelete;

		return true;
	}
	return false;
}

bool BinaryTree::deleteNodeByKey(Node* subTreeRoot,const int key)
{
	Node* toDelete = findNodeByKey(subTreeRoot, key);
	return deleteNode(toDelete);
}

bool BinaryTree::deleteNodeByKey(const int key)
{
	return deleteNodeByKey(m_root, key);
}

Node* BinaryTree::indexNode(Node* subTreeRoot, int nodeIndex)
{
	if (nodeIndex == 0)
	{
		return subTreeRoot;
	}

	else if (subTreeRoot == nullptr)
	{
		return nullptr;
	}

	std::vector<Node*> currentLevelNodes;
	currentLevelNodes.push_back(subTreeRoot);

	while (currentLevelNodes.size() != 0 && nodeIndex >= currentLevelNodes.size())
	{
		std::vector<Node*> nextLevelNodes;
		nextLevelNodes.reserve(currentLevelNodes.size() * 2);

		for (Node* node : currentLevelNodes)
		{
			if (node->leftChild)
			{
				nextLevelNodes.push_back(node->leftChild);
			}

			if (node->rightChild)
			{
				nextLevelNodes.push_back(node->rightChild);
			}
		}

		nodeIndex -= currentLevelNodes.size();
		currentLevelNodes.swap(nextLevelNodes);
	}

	if (currentLevelNodes.size() == 0)
	{
		return nullptr;
	}
	else
	{
		return currentLevelNodes[nodeIndex];
	}
}

Node* BinaryTree::indexNode(const int nodeIndex)
{
	return indexNode(m_root, nodeIndex);
}

vector<int> BinaryTree::getAllKeys(Node* subTreeRoot)
{
	if (subTreeRoot == nullptr)
		return std::vector<int>();

	vector<int> keys;
	vector<Node*> currentLevelNodes;
	currentLevelNodes.push_back(subTreeRoot);
	keys.push_back(subTreeRoot->getKey());

	while (currentLevelNodes.size() != 0)
	{
		vector<Node*> nextLevelNodes;
		nextLevelNodes.reserve(currentLevelNodes.size() * 2);

		for (Node* node : currentLevelNodes)
		{
			if (node->leftChild)
			{
				nextLevelNodes.push_back(node->leftChild);
				keys.push_back(node->leftChild->getKey());
			}

			if (node->rightChild)
			{
				nextLevelNodes.push_back(node->rightChild);
				keys.push_back(node->rightChild->getKey());
			}
		}

		currentLevelNodes.swap(nextLevelNodes);
	}

	return keys;
}

vector<int> BinaryTree::getAllKeys()
{
	return getAllKeys(m_root);
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

void BinaryTree::printVertical(Node* subTreeRoot)
{
	if (subTreeRoot == nullptr)
	{
		std::cout << "error printVertical: Tree is empty" << std::endl;
		return;
	}

	std::vector<Node*> currentLevelNodes;
	currentLevelNodes.push_back(subTreeRoot);
	int significant = 1;
	int level = 1;
	int h = height(subTreeRoot);

	while (significant != 0)
	{
		for (int i = 0; i < currentLevelNodes.size(); i++)
		{
			if (i == 0)
				for (int j = 0; j < pow(2, h - level); j++)
					std::cout << " ";
			else
				for (int j = 0; j < pow(2, h - level) + pow(2, h - level) - 1; j++)
					std::cout << " ";

			if (currentLevelNodes[i])
				std::cout << currentLevelNodes[i]->getKey();
			else
				std::cout << "X";
		}
		std::cout << std::endl;

		significant = 0;
		std::vector<Node*> nextLevelNodes;
		nextLevelNodes.reserve(currentLevelNodes.size() * 2);

		for (Node* node : currentLevelNodes) {
			if (node)
			{
				if (node->leftChild)
					significant++;
				if (node->rightChild)
					significant++;

				nextLevelNodes.push_back(node->leftChild);
				nextLevelNodes.push_back(node->rightChild);
			}
			else
			{
				nextLevelNodes.push_back(nullptr);
				nextLevelNodes.push_back(nullptr);
			}
		}

		currentLevelNodes.swap(nextLevelNodes);
		level++;
	}
}

void BinaryTree::printVertical()
{
	printVertical(m_root);
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
		else
		{
			cout << "X" << "   ";
		}
		return;
	}

	if (startNode == nullptr)
	{
		cout << "X" << "    ";
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
