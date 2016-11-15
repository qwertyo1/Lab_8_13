#include "SampleClass.h"
#include <conio.h>
#include <windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "[Тестирование char массива]" << endl;
	char* test = new char;
	cout << "Введите строку: ";
	cin >> test;
	SampleClass <char> testarr(test, strlen(test));
	testarr.process();
	testarr.output();
	cout << "Записать пробел в элемент: " << endl;
	int index = 0;
	cin >> index;
	try
	{
		testarr[index] = ' ';
		testarr.output();
	}
	catch (...)
	{
		cout << "Не вышло" << endl;
	}
	system("pause");

	cout << "[Тестирование int массива]" << endl;
	cout << "Введите количество элементов целочисленного массива: ";
	int size = 0;
	cin >> size;
	int* testint = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Элемент под номером " << i << ": ";
		cin >> testint[i];
	}
	SampleClass <int> testarrint(testint, size);
	testarrint.process();
	testarrint.output();

	system("pause");
	return 0;
}

