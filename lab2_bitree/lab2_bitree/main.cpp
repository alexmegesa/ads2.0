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
	
}