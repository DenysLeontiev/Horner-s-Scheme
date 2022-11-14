#include<iostream>
#include<time.h>

using namespace std;

int setValue(const char[]);
int* generateArray(int);

void main()
{
    int x = setValue("x");
    int arraySize = setValue("size of array");

    int* generatedArray = generateArray(arraySize);

    int result = generatedArray[0] * x + generatedArray[1];

    for (int i = 2; i < arraySize; i++)
    {
        result *= x;
        result += generatedArray[i];
    }

    
    cout << result;
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
    int* array = new int [arrSize];

    for (int i = 0; i < arrSize; i++)
    {
        cout << "Enter " << "N." << (i + 1) << " element = ";
        int value = 0;
        cin >> value;
        array[i] = value;
    }

    return array;
}