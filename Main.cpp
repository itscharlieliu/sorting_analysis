#include "UserInput.h"
#include "Sort.h"
#include <iostream>
#include <stdlib.h>
#include <chrono>

using namespace std;


int main(int argc, char const *argv[])
{
  if (argc <= 1)
  {
    cout << "Please provide a text file as an argument" << endl;
    return 0;
  }


  bool printArray = true;
  if (argc >= 3 && argv[2] == string("n"))
  {
    cout << "Not printing arrays..." << endl;
    printArray = false;
  }


  UserInput in(argv[1]);
  string in_str = in.getString();
  int arrSize;

  cout << endl;

  string temp = "";
  int numItemsIdx = 0;
  do
  {
    temp += in_str[numItemsIdx];
    numItemsIdx++;
  } while(in_str[numItemsIdx] != '\n');
  arrSize = atoi(temp.c_str());
  ++numItemsIdx;

  //setting four arrays with the input from the file
  double *arr[4];
  for (int i = 0; i < 4; ++i)
  {
    arr[i] = new double [arrSize];
    temp = "";
    int idx = 0;
    for (int j = numItemsIdx; j < in_str.size() && idx < arrSize; ++j)
    {
      if (in_str[j] != '\n')
      {
        temp += in_str[j];
      }
      else
      {
        arr[i][idx++] = atof(temp.c_str());
        temp = "";
      }
    }
  }

  chrono::duration<double> et[4];



  //Sorting array 0 with insertionSort
  {
    auto t1 = chrono::high_resolution_clock::now();
    Sort::insertionSort(arr[0], arrSize);
    auto t2 = chrono::high_resolution_clock::now();
    et[0] = t2 - t1;

    for (int i = 0; i < arrSize && printArray; ++i)
    {
      cout << arr[0][i] << ' ';
    }
    cout << "Insertion Sort elapsed time: " << et[0].count() << " seconds" << endl;
    cout << "Press enter to continue...";
    string t;
    getline(cin, t);

    cout << endl << endl;
  }

  //array 1 bubble sort
  {
    auto t1 = chrono::high_resolution_clock::now();
    Sort::bubbleSort(arr[1], arrSize);
    auto t2 = chrono::high_resolution_clock::now();
    et[1] = t2 - t1;
    for (int i = 0; i < arrSize && printArray; ++i)
    {
      cout << arr[0][i] << ' ';
    }
    cout << "Bubble Sort elapsed time: " << et[1].count() << " seconds"  << endl;

    cout << "Press enter to continue...";
    string t;
    getline(cin, t);
    cout << endl << endl;
  }

  //array 2 selection sort
  {
    auto t1 = chrono::high_resolution_clock::now();
    Sort::selectionSort(arr[2], arrSize);
    auto t2 = chrono::high_resolution_clock::now();
    et[2] = t2 - t1;
    for (int i = 0; i < arrSize && printArray; ++i)
    {
      cout << arr[0][i] << ' ';
    }
    cout << "Selection Sort elapsed time: " << et[2].count() << " seconds"  << endl;
    cout << "Press enter to continue...";
    string t;
    getline(cin, t);
    cout << endl << endl;
  }

  //array 3 quickSort
  {
    auto t1 = chrono::high_resolution_clock::now();
    Sort::quickSort(arr[3], arrSize);
    auto t2 = chrono::high_resolution_clock::now();
    et[3] = t2 - t1;
    for (int i = 0; i < arrSize && printArray; ++i)
    {
      cout << arr[0][i] << ' ';
    }
    cout << "Quick Sort elapsed time: " << et[3].count() << " seconds"  << endl;
    cout << "Press enter to continue...";
    string t;
    getline(cin, t);
    cout << endl << endl;
  }





  return 0;
}
