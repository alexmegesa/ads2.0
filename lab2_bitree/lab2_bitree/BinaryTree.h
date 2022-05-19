#pragma once

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	Node(const int key = -1, Node* leftChild = nullptr, Node* rightChild = nullptr)
	{
		this->key = key;
		this->leftChild = leftChild;
		this->rightChild = rightChild;
	}

	int getKey() { return key; };

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
	


	Node* findParentByKey(Node* subTreeRoot, const int key); //����� �������� �� ����� ����
	Node* findParentByKey(const int key);					 //����� �������� �� ����� ����
	Node* findNodeByKey(Node* subTreeRoot, const int key);
	Node* findNodeByKey(const int key);
	Node* emptyNodeChild(Node* subTreeRoot);			     //����� ���� � ������ ��������

	bool deleteNode(Node* nodeToDelete);                     //�������� ���� �� �����
	bool deleteNodeByKey(Node* subTreeRoot, const int key);
	bool deleteNodeByKey(const int key);

	Node* indexNode(Node* subTreeRoot, int nodeIndex);		 //����� ���� �� �������
	Node* indexNode(const int nodeIndex);					 //����� ���� �� �������

	vector<int> getAllKeys(Node* subTreeRoot);
	vector<int> getAllKeys();
		
	void printHorizontal();
	void printHorizontal(Node* startNode, const int level = 0);

	void printVertical(Node* subTreeRoot);
	void printVertical();

	void printLevel(const int level);
	void printLevel(Node* startNode, const int level, const int currentLevel = 0);
	


};

