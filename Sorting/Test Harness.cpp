// Sorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include "Timer.h"
#include "Sorts.h"
#include <vector>
#include <algorithm>

using namespace std;

//Used for STL quick sort
int comp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	const int MAX_VAL = 10000;

	srand(static_cast<unsigned int>(time(NULL)));


	//Create three big arrays
	cout << "Creating three arrays of size "<< MAX_VAL<<" to sort." << endl;
	int quickArray[MAX_VAL];
	int mergeArray[MAX_VAL];
	int heapArray[MAX_VAL];
	int bubbleArray[MAX_VAL];
	int stlQuickArray[MAX_VAL];
	std::vector<int> heapVector;

	{
		Timer myTimer("FILL VALUES");
		cout << "Filling arrays with random values." << endl;
		for (int i = 0; i < MAX_VAL; i++)
		{
			quickArray[i] = rand() % MAX_VAL;	//MAX_VAL - i;
			mergeArray[i] = quickArray[i];
			heapArray[i] = quickArray[i];
			bubbleArray[i] = quickArray[i];
			heapVector.push_back(quickArray[i]);
			stlQuickArray[i] = quickArray[i];
		}
	}


	//perform bubble sort
	{
		cout << "Executing bubble sort." << endl;
		Timer myTimer("BUBBLE SORT");
		Sorts::bubbleSort(bubbleArray, MAX_VAL);
	}

	//perform heap sort
	{
		cout << "Executing heap sort." << endl;

		//copy elements into vector
		Timer myTimer("HEAP SORT");
		
		Sorts::heapSort(heapArray, MAX_VAL);
	}

	//perform merge sort
	{
		cout << "Executing merge sort." << endl;
		Timer myTimer("MERGE SORT");
		Sorts::mergeSort(mergeArray, 0, MAX_VAL-1);
	}

	//perform quick sort
	{
		cout << "Executing quick sort." << endl;
		Timer myTimer("QUICK SORT");
		Sorts::quickSort(quickArray, 0, MAX_VAL - 1);
	}

	//perform STL heap sort
	{
		cout << "Executing STL heap sort." << endl;

		//copy elements into vector
		Timer myTimer("STL HEAP SORT");
		std::make_heap(heapVector.begin(), heapVector.end());
		std::sort_heap(heapVector.begin(), heapVector.end());
	}
	//perform STL quick sort
	{
		cout << "Executing STL quick sort." << endl;
		Timer myTimer("STL QUICK SORT");
		std::qsort(stlQuickArray, MAX_VAL, sizeof(int), comp);
	}

	system("pause");
    return 0;
}

