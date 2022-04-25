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
	~BinaryTree();								   //����������

	Node* getRoot();							   //������� ������ ������
	Node* addNode(Node *startNode, const int key); //���������� ���� � ������
	void deleteSubTree(Node *subTreeRoot);		   //�������� ���������
	void clearingTree();						   //������� ������
	bool isEmpty();								   //�������� �� ������� ������
	int height(Node* subTreeRoot);				   //������ ���������
	int height();								   //������ ������
	int countNodes(Node* subTreeRoot);			   //���������� �����
	int countNodes();							   //���������� �����
	
	bool deleteOnKey();                            //�������� ���� �� �����
		
	void printHorizontal();
	void printHorizontal(Node* startNode, const int level = 0);

	void printLevel(const int level);
	void printLevel(Node* startNode, const int level, const int currentLevel = 0);



};

