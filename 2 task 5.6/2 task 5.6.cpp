#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() 
{
	setlocale(LC_ALL, "ru");

	cout << "Введите текст для записи в файл:" << endl;

	ofstream inputfile("input_file.txt");

	string line;
	getline(cin, line);
	inputfile << line;
	inputfile.close();

	ifstream ifile("input_file.txt");
	if (!ifile.is_open())
	{
		cout << "Не удалось открыть файл для чтения." << endl;
		return 1;
	}

	ofstream ofile("output_file.txt");
	if (!ofile.is_open())
	{
		cout << "Не удалось открыть файл для записи." << endl;
		ifile.close();
		return 1;
	}

	vector<string> words;
	string word;
	while (ifile >> word)
	{
		words.push_back(word);
	}

	for (int i = words.size() - 1; i >= 0; i--)
	{
		ofile << words[i] << " ";
	}
	ofile << endl;

	ifile.close();
	ofile.close();

	ifstream outputfile("output_file.txt");
	if (outputfile.is_open())
	{
		string l;
		while (getline(outputfile, l))
		{
			cout << l << endl;
		}
		outputfile.close();
	}
	else
	{
		cout << "Не удалось открыть файл для чтения." << endl;
	}

	return 0;
}