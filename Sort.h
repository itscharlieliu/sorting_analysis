#ifndef SORT_H
#define SORT_H

class Sort
{
private:
  static void quickSort(double *arr, int low, int high);
  static int partition(double *arr, int low, int high);
public:
  static void quickSort(double *arr, int size);
  static void insertionSort(double *arr, int size);
  static void bubbleSort(double *arr, int size);
  static void selectionSort(double *arr, int size);
};




#endif
