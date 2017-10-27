#include <stdio.h>
#include <cstring>
#include <sstream>
#include <iostream>

using namespace std;

void read(double *array, unsigned int size) 
{
	string stroka;
	getline(cin, stroka);
	istringstream stream(stroka);
	for (unsigned int i = 0; i<size; ++i)
	{
		stream >> array[i];
	}
}

void swap(double *xp, double *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(double *arr, int n)
{
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
				swap(&arr[min_idx], &arr[i]);
			}
	}
}

void printArray(double arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i];
}

int main()
{
	unsigned int size;	
	cin >> size;
	cin.get();
	double *arr = new double[size];
	read(arr, size);
	selectionSort(arr, size);
	printf("Sorted array: \n");
	printArray(arr, size);
	return 0;
}
