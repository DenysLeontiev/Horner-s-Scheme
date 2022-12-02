#include<iostream>
#include<time.h>

using namespace std;

double setValue(const char[]);
double* generateArray(int);
double getPolynom(double* generatedArr, int arraySize, double x);
double getDeritative(double* arr, int size, double x);
void outputArray(double* arr, int size);


int main()
{
	double x = setValue("x");
	int arraySize = 0;
	while (arraySize < 1)
	{
		arraySize = (int)setValue("degree of polynom");
	}

	double* generatedArray = generateArray(arraySize);

	double polynom = getPolynom(generatedArray, arraySize, x);
	double deritative = getDeritative(generatedArray, arraySize, x);

	cout << endl;

	cout << "polynom = " << polynom << endl;
	cout << "deritative = " << deritative << endl << endl;

	outputArray(generatedArray, arraySize + 1);

	delete[] generatedArray;

	system("pause");
	return 0;
}

double setValue(const char v[])
{
	/*srand(time(NULL));*/

	int error;
	double value;
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

double* generateArray(int arrSize)
{
	double* array = new double[arrSize + 1];

	for (int i = 0; i <= arrSize; i++)
	{
		cout << "Enter " << "N." << (i + 1) << " element = ";
		/*int value = 0;
		cin >> value;*/
		array[i] = setValue("element");
	}

	return array;
}

double getPolynom(double* generatedArr, int arraySize, double x)
{
	double result = generatedArr[0];

	for (int i = 1; i <= arraySize; i++)
	{
		result *= x;
		result += generatedArr[i];
	}

	return result;
}

double getDeritative(double* arr, int size, double x)
{
	double res = arr[0] * size;

	for (int i = 1; i < size; i++)
	{
		res = res * x + arr[i] * (size - i);
	}

	return res;
}

void outputArray(double* arr, int size)
{

	for (int i = 0; i < size; i++)
	{
		cout << "#" << (i + 1) << " = " << arr[i] << "  ";
	}

	cout << endl;
}