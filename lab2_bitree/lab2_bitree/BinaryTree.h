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
	


	Node* findParentByKey(Node* subTreeRoot, const int key); //поиск родителя по ключу узла
	Node* findParentByKey(const int key);					 //поиск родителя по ключу узла
	Node* findNodeByKey(Node* subTreeRoot, const int key);
	Node* findNodeByKey(const int key);
	Node* emptyNodeChild(Node* subTreeRoot);			     //поиск узла с пустым ребенком

	bool deleteNode(Node* nodeToDelete);                     //удаление узла по ключу
	bool deleteNodeByKey(Node* subTreeRoot, const int key);
	bool deleteNodeByKey(const int key);

	Node* indexNode(Node* subTreeRoot, int nodeIndex);		 //поиск узла по индексу
	Node* indexNode(const int nodeIndex);					 //поиск узла по индексу

	vector<int> getAllKeys(Node* subTreeRoot);
	vector<int> getAllKeys();
		
	void printHorizontal();
	void printHorizontal(Node* startNode, const int level = 0);

	void printVertical(Node* subTreeRoot);
	void printVertical();

	void printLevel(const int level);
	void printLevel(Node* startNode, const int level, const int currentLevel = 0);
	


};

