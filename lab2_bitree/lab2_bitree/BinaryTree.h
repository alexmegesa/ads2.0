#pragma once

#include <iostream>
using namespace std;

struct Node
{
	Node(const int key = -1, Node* leftChild = nullptr, Node* rightChild = nullptr)
	{
		this->key = key;
		this->leftChild = leftChild;
		this->rightChild = rightChild;
	}

	int key;
	Node *leftChild = nullptr;
	Node *rightChild = nullptr;
};

class BinaryTree
{
private:
	Node *m_root = nullptr;

public:
	BinaryTree() = default;						   //����������� �� ��������� (������� ��� �����)

	Node* getRoot();							   //������� ������ ������
	Node* addNode(Node *startNode, const int key); //���������� ���� � ������

	void printHorizontal();
	void printHorizontal(Node* startNode, const int level = 0);

	void printLevel(const int level);
	void printLevel(Node* startNode, const int level, const int currentLevel = 0);
};

