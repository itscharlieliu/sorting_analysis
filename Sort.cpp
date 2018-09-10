#include "Sort.h"
#include <iostream>

using namespace std;

void Sort::insertionSort(double *arr, int size)
{
  int j;
  for (int i = 0; i < size; ++i)
  {
    double key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;

    }
    arr[j + 1] = key;
  }

}

void Sort::bubbleSort(double *arr, int size)
{
	for (int i = 0 ; i < size; ++i)
	{
		double temp = 0;
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (arr[j] > arr[j+1])
			{
        //cout << arr[j] << " is bigger than " << arr[j+1] << endl;
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void Sort::selectionSort(double *arr, int size)
{
	for (int i = 0; i < size-1; ++i)
	{
		int minIndex = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (arr[j] < arr[minIndex])
			{
        //cout << arr[j] << " is less than " << arr[minIndex] << endl;
				minIndex = j;
			}
		}
    if (minIndex != i)
    {
      //cout << "swap" << endl;
      double tmp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = tmp;
    }
	}
}


void Sort::quickSort(double *arr, int size)
{
  quickSort(arr, 0, size - 1);
}

void Sort::quickSort(double *arr, int low, int high)
{
  if (low < high)
  {
    //partitioning index
    int pi = partition(arr, low, high);

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int Sort::partition(double *arr, int low, int high)
{
  double pivot = arr[high];
  double tmp;

  int i = (low - 1);

  for (int j = low; j <= high - 1; ++j)
  {
    if (arr[j] <= pivot)
    {
      ++i;
      tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;
    }
  }
  tmp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = tmp;

  return (i + 1);
}
