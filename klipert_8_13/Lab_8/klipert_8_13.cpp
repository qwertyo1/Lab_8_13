#include "SampleClass.h"
#include <conio.h>
#include <windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "[������������ char �������]" << endl;
	char* test = new char;
	cout << "������� ������: ";
	cin >> test;
	SampleClass <char> testarr(test, strlen(test));
	testarr.process();
	testarr.output();
	cout << "�������� ������ � �������: " << endl;
	int index = 0;
	cin >> index;
	try
	{
		testarr[index] = ' ';
		testarr.output();
	}
	catch (...)
	{
		cout << "�� �����" << endl;
	}
	system("pause");

	cout << "[������������ int �������]" << endl;
	cout << "������� ���������� ��������� �������������� �������: ";
	int size = 0;
	cin >> size;
	int* testint = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "������� ��� ������� " << i << ": ";
		cin >> testint[i];
	}
	SampleClass <int> testarrint(testint, size);
	testarrint.process();
	testarrint.output();

	system("pause");
	return 0;
}

