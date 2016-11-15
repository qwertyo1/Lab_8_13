#pragma once

#include <iostream>
using namespace std;

template <typename T>
class SampleClass
{
private:
	T* arr;
	int size;
public:
	SampleClass();
	SampleClass(const T*, const int);
	SampleClass(SampleClass&);
	~SampleClass();
	void add(const T);
	void del(const int);
	void output();
	void process();
	T& operator [] (int& i);
};

template <typename T>
SampleClass<T>::SampleClass()
{
	arr = new T;
	size = 0;
}

template <typename T>
SampleClass<T>::SampleClass(const T* newArr, const int newSize)
{
	for (int i = 0; i < newSize; i++)
	{
		add(newArr[i]);
	}
}

template <typename T>
SampleClass<T>::SampleClass(SampleClass& source)
{
	arr = new T[source.size + 1];
	T* temp = source.arr;
	for (int i = 0; i < source.size; i++)
	{
		add(source.arr[i]);
	}
}

template <typename T>
SampleClass<T>::~SampleClass()
{
	delete[] arr;
}

template <typename T>
void SampleClass<T>::output()
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i];
	}
	cout << endl;
}

template <typename T>
void SampleClass<T>::add(const T newElem)
{
	size++;
	arr = (T*)realloc(arr, (size + 1) * sizeof(T));
	arr[size - 1] = newElem;
}

template <typename T>
void SampleClass<T>::del(const int pos)
{
	try
	{
		if ((pos > -1) && (pos < size))
		{
			size--;
			arr = (T *)realloc(arr, (size + 1) * sizeof(T));
			for (int i = pos; i <= size; i++)
			{
				arr[i] = arr[i + 1];
			}
		}
		else
			throw;
	}
	catch(...)
	{
		cout << "Ошибка при удалении элемента массива" << endl;
	}
}

template <typename T>
void SampleClass<T>::process()
{
	cout << "Это не строка, поэтому я ничего делать не буду" << endl;
}

void SampleClass<char>::process()
{
	for (int i = 0; i < size; i++)
	{
		if (tolower(arr[i]) != arr[i])
		{
			del(i);
			i--;
		}
	}
}

template <typename T>
T& SampleClass<T>::operator [] (int& i)
{
	try
	{
		if ((i >= 0) && (i < size))
		{
			return *(arr + i * sizeof(T));
		}
		else throw 1;
	}
	catch (...)
	{
		cout << "Ошибка. Неверно указан индекс при обращении к массиву" << endl;
		throw;
	}
}

