#include<iostream>
#include<time.h>

using namespace std;

int setValue(const char[]);
int* generateArray(int);
int getPolynom(int* generatedArr, int arraySize, int x);
int getDeritative(int* arr, int size, double x);

void main()
{
	int x = setValue("x");
	int arraySize = setValue("size of array");

	int* generatedArray = generateArray(arraySize);

	int polynom = getPolynom(generatedArray, arraySize, x);
	int deritative = getDeritative(generatedArray, arraySize, x);


	cout << "polynom = "<< polynom << endl;
	cout << "deritative = " << deritative << endl;

	system("pause");
}

int setValue(const char v[])
{
	srand(time(NULL));

	int error;
	int value;
	do
	{
		error = 0;
		cout << "Please enter " << v << " = ";
		cin >> value;
		if (cin.fail())
		{
			cout.clear();
			cout << "Please enter a valid number" << endl;
			error = 1;
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (error == 1);

	return value;
}

int* generateArray(int arrSize)
{
	int* array = new int[arrSize];

	for (int i = 0; i < arrSize; i++)
	{
		cout << "Enter " << "N." << (i + 1) << " element = ";
		int value = 0;
		cin >> value;
		array[i] = value;
	}

	return array;
}

int getPolynom(int* generatedArr, int arraySize, int x)
{
	int result = generatedArr[0];

	for (int i = 0; i < arraySize; i++)
	{
		result *= x;
		result += generatedArr[i];
	}

	return result;
}

int getDeritative(int* arr, int size, double x)
{
	int res = 1;

	for (int i = 1; i < size; i++)
	{
		res = res * x * (size - i) * arr[i];
	}

	return res;
}