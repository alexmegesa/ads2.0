#include <iostream>
#include <fstream>
#include <time.h>
#include <stdio.h>

using namespace std;



void PrintFile(const std::string& fileName)
{
	ifstream file(fileName);
	int value;

	cout << "file content: ";

	while (!file.eof())
	{
		file >> value;
		cout << value << ' ';
	}
}

bool isFileContainsSortedArray(const std::string& fileName)
{
	ifstream File(fileName);
	if (!File.is_open())
	{
		cerr << "Error: file is not open!" << endl;
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
		cerr << "Error: file is not open!" << endl;
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

	if (!f1.is_open() || !f2.is_open() || !f3.is_open())
	{
		cerr << "Error: file is not open!" << endl;
		return;
	}

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

	f1.close(); f2.close(); f3.close();
}

void merge(const string& fileName1, const string& fileName2, const string& fileName3, const string& fileName4, int p)
{
	int x, y;
	int i, j;

	ofstream f1(fileName1);
	ofstream f2(fileName2);
	ifstream f3(fileName3);
	ifstream f4(fileName4);

	if (!f1.is_open() || !f2.is_open() || !f3.is_open() || !f4.is_open())
	{
		cerr << "Error: file is not open!" << endl;
		return;
	}

	f3 >> x;
	f4 >> y;

	int n = 0;
	while (!f3.eof() && !f4.eof())
	{
		i = j = 0;
		while (!f3.eof() && !f4.eof() && i < p && j < p)
		{
			if (x < y)
			{
				if (n == 0)
				{
					f1 << x << ' ';
				}
				else
					f2 << x << ' ';

				f3 >> x;
				i++;
			}

			else
			{
				if (n == 0)
				{
					f1 << y << ' ';
				}
				else
					f2 << y << ' ';

				f4 >> y;
				j++;
			}
		}

		while (!f3.eof() && i < p)
		{
			if (n == 0)
			{
				f1 << x << ' ';
			}
			else
				f2 << x << ' ';

			f3 >> x;
			i++;
		}

		while (!f4.eof() && j < p)
		{
			if (n == 0)
			{
				f1 << y << ' ';
			}
			else
				f2 << y << ' ';

			f4 >> y;
			j++;
		}

		n = 1 - n;
	}

	while (!f3.eof())
	{
		if (n == 0)
		{
			f1 << x << ' ';
		}
		else
			f2 << x << ' ';

		f3 >> x;
	}

	while (!f4.eof())
	{
		if (n == 0)
		{
			f1 << y << ' ';
		}
		else
			f2 << y << ' ';

		f4 >> y;
	}

	f1.close();
	f2.close();
	f3.close();
	f4.close();

}

void SortFile(const string& fileName)
{
	
	ifstream f(fileName);
	ofstream f1("file1.txt");
	ofstream f2("file2.txt");
	ofstream f3("file3.txt");
	ofstream f4("file4.txt");

	if (!f1.is_open() || !f2.is_open() || !f3.is_open() || !f4.is_open())
	{
		cerr << "Error: file is not open!" << endl;
		return;
	}


	int p = 1;
	splitting(fileName, "file1.txt", "file2.txt", p);

	f.close();
	f1.close();
	f2.close();
	f3.close();
	f4.close();

	while (true)
	{
		ifstream f2("file2.txt");

		if (f2.peek() == EOF)
		{
			f2.close();
			break;
		}
		f2.close();

		merge("file3.txt", "file4.txt", "file1.txt", "file2.txt", p);

		p = 2 * p;

		merge("file1.txt", "file2.txt", "file3.txt", "file4.txt", p);

		p = 2 * p;

		
	}
	
	
	
	ifstream newFile("file1.txt");
	ofstream newFile1(fileName);

	if (!newFile.is_open() || !newFile1.is_open())
	{
		cerr << "Error: file is not open!" << endl;
		return;
	}
	
	int number;
	while (!newFile.eof())
	{
		newFile >> number;
		newFile1 << number << ' ';
	}
	

}

int createAndSortFile(const std::string& fileName, const int numbersCount, const int maxNumberValue)
{
	if (!createFileWithRandomNumbers(fileName, numbersCount, maxNumberValue)) {
		return -1;
	}

	SortFile(fileName); 

	if (!isFileContainsSortedArray(fileName)) {
		return -2;
	}

	return 1;
}

int main()
{	
	srand(time(0));
	std::string fileName = "file.txt";
	const int numbersCount = 1000000;
	const int maxNumberValue = 100000;

	for (int i = 0; i < 10; i++)
	{
		switch (createAndSortFile(fileName, numbersCount, maxNumberValue))
		{
		case 1:
			std::cout << "Test passed." << std::endl;
			break;

		case -1:
			std::cout << "Test failed: can't create file." << std::endl;
			break;

		case -2:
			std::cout << "Test failed: file isn't sorted." << std::endl;
			break;
		}

	}
	return 0;
}