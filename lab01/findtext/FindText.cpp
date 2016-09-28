// FindText.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	if (argc != 3)
	{
		cout << "������������ ����������. ������ ������� ������: <���������� �����> <������ ��� ������>" << "\n";
		return 1;
	}
	ifstream file(argv[1]);
	if (!file.is_open())
	{
		cout << "���������� ������� ����. ��������� ������������ �������� ������ ��� ��������� � ������� ������� �����." << "\n";
		return 1;
	}
	string strToFind = argv[2];
	if (strToFind.empty())
	{
		cout << "������ ������ �������� ��� ��������� ������ ��� ������." << "\n";
		return 1;
	}
	bool strFinded = false;
	int currentLine = 1;
	string line;
	cout << "� ������ ����� ����� �������� ������ ����� �������� ����� (1 ��������), ������� �������� ������� ��� ������ ������ (2 ��������)" << "\n";
	while (getline(file, line))
	{
		if (line.find(strToFind) != string::npos)
		{
			cout << currentLine << "\n";
			strFinded = true;
		}
		++currentLine;
	};
	if (!strFinded)
	{
		cout << "Text not found" << "\n";
	}
	return 0;
}

