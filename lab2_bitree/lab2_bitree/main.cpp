#include <iostream>
#include <fstream>
#include <time.h>
#include <stdio.h>
#include "BinaryTree.h"

using namespace std;

int main()
{

	BinaryTree bt;
	for (int i = 0; i < 10; i++)
	{
		bt.addNode(bt.getRoot(), i);
	}
	bt.printHorizontal();

	cout << endl << endl << endl;

	for (int i = 0; i < 10; i++)
	{
		bt.printLevel(i);
		cout << endl;
	}

	cout << endl << endl << endl;
	
	bt.deleteNode(bt.indexNode(2));
	bt.printHorizontal();

	std::vector<int> keys(bt.getAllKeys());
	for (int key : keys)
	{
		std::cout << key << " ";
	}
	
}