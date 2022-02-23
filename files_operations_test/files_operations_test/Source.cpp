#include <iostream>
#include <fstream>

#include <stdio.h>

bool stdioFileReadWtire()
{
	FILE* file;
	fopen_s(&file, "test.txt", "w");

	if (file == nullptr)
	{
		std::cout << "can't create file 'test'" << std::endl;
		return true;
	}

	fprintf(file, "%s", "test");
	fclose(file);

	fopen_s(&file, "test2.txt", "r");

	if (file == nullptr)
	{
		std::cout << "can't create file 'test2'" << std::endl;
		fopen_s(&file, "test.txt", "r");
	}

	std::cout << "file.txt content:	" << std::endl;
	int size = 5;
	char* filecontent = new char[size];
	fscanf_s(file, "%s", filecontent, size);
	std::cout << filecontent << std::endl;
	fclose(file);

	return false;
}

bool fstreamFileWriteRead()
{
	std::ifstream  file("text.txt");

	std::ofstream writer("test.txt");
	std::istream reader();

	if (file.is_open())
	{
		std::cout << "'test.txt' is oened" << std::endl;
		file.close();
	}
	
	writer << "test.txt";
	writer.close();

	


}

int main()
{
	fstreamFileWriteRead();
	return 0;


}
