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
	BinaryTree() = default;						   //конструктор по умолчанию (нулевой птр корня)
	~BinaryTree();								   //деструктор

	Node* getRoot();							   //вернуть корень дерева
	Node* addNode(Node *startNode, const int key); //добавление узла в дерево
	void deleteSubTree(Node *subTreeRoot);		   //удаление поддерева
	void clearingTree();						   //очистка дерева
	bool isEmpty();								   //проверка на пустоту дерева
	int height(Node* subTreeRoot);				   //высота поддерева
	int height();								   //высота дерева
	int countNodes(Node* subTreeRoot);			   //количество узлов
	int countNodes();							   //количество узлов
	
	bool deleteOnKey();                            //удаление узла по ключу
		
	void printHorizontal();
	void printHorizontal(Node* startNode, const int level = 0);

	void printLevel(const int level);
	void printLevel(Node* startNode, const int level, const int currentLevel = 0);



};

