#include <iostream>
#include <fstream>
#include <time.h>
#include <stdio.h>

using namespace std;

bool isFileContainsSortedArray(const std::string& fileName)
{
	ifstream File(fileName);
	if (!File.is_open())
	{
		cout << "Error: file is not open!" << endl;
		return 0;
	}

	int x, y;

	File >> x;
	while (!File.eof())
	{
		File >> y;
		if (x > y)
			return 0;

		x = y;

	}

	File.close();
	return 1;

}

bool createFileWithRandomNumbers(const std::string& fileName, const int numbersCount, const int maxNumberValue)
{
	ofstream File(fileName);

	if (!File.is_open())
	{
		cout << "Error: file is not open!" << endl;
		return 0;
	}

	for (int i = 0; i < numbersCount; i++)
	{
		File << rand() % (maxNumberValue + 1) << ' ';
	}
	return 1;

}


int main()
{

}