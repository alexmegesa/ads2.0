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

void splitting(const string& fileName1, const string& fileName2, const string& fileName3, int p)
{
	ifstream f1(fileName1);
	ofstream f2(fileName2);
	ofstream f3(fileName3);


	int n = 0, i, x;
	

	f1 >> x;
	while (!f1.eof())
	{
		i = 0;
		while (!f1.eof() && i < p)
		{
			if (n == 0)
			{
				f2 << x << ' ';
			}
			else
			{
				f3 << x << ' ';
			}

			f1 >> x;
			i++;
		}

		n = 1 - n;
	}
}

int main()
{		
	int numbersCount, maxNumberValue;
	cout << "enter count of numbers:	";
	cin >> numbersCount;
	cout << "\nenter max number value:	";
	cin >> maxNumberValue;


	createFileWithRandomNumbers("file.txt", numbersCount, maxNumberValue);
	
	splitting("file.txt", "file1.txt", "file2.txt", 2);

	

}