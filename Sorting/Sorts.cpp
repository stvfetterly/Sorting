#include "stdafx.h"
#include "Sorts.h"
#include <queue>

void Sorts::bubbleSort(int arrayToSort[], const int& length)
{
	for (int i = 0; i < length; i++)
	{
		bool swapMade = false;

		for (int j = 0; j < length - 1; j++)
		{
			if (arrayToSort[j] > arrayToSort[j + 1])
			{
				swap(arrayToSort[j], arrayToSort[j + 1]);
				swapMade = true;
			}
		}

		//If we've completed a whole pass without any swaps, then we are done sorting
		if (swapMade == false)
		{
			return;
		}
	}
}
//Swaps values input
void Sorts::swap(int& firstVal, int& secondVal)
{
	int tmp = firstVal;
	firstVal = secondVal;
	secondVal = tmp;
}


// Merge sort takes in: 
// arrayToSort - the array that you're sorting
// lo - should be zero when calling
// hi - the max index of the array when calling
void Sorts::mergeSort(int arrayToSort[], const int& lo, const int& hi)
{
	if (lo < hi)
	{
		//find the mid point:
		int mid = (hi + lo) / 2;

		//recursively sort the upper and lower halves
		mergeSort(arrayToSort, lo, mid);
		mergeSort(arrayToSort, mid+1, hi);

		//merge the results back together
		merge(arrayToSort, lo, mid+1, hi);
	}
}
//merges parts of the array - from lo to mid - 1, and from mid to hi
void Sorts::merge(int arrayToSort[], const int& lo, const int& mid, const int& hi)
{
	std::queue<int> loBuffer;
	std::queue<int> hiBuffer;

	//fill the buffers up
	for (int i = lo; i < mid; i++)
	{
		loBuffer.push(arrayToSort[i]);
	}

	for (int i = mid; i <= hi; i++)
	{
		hiBuffer.push(arrayToSort[i]);
	}

	int index = lo;

	//merge the buffers until we run out of data for one of them
	while (loBuffer.size() > 0 && hiBuffer.size() > 0)
	{
		if (loBuffer.front() <= hiBuffer.front())
		{
			arrayToSort[index] = loBuffer.front();
			loBuffer.pop();
		}
		else
		{
			arrayToSort[index] = hiBuffer.front();
			hiBuffer.pop();
		}

		index++;
	}

	//add in any final data that's remaining
	while (loBuffer.size() > 0)
	{
		arrayToSort[index] = loBuffer.front();
		loBuffer.pop();
		index++;
	}
	while (hiBuffer.size() > 0)
	{
		arrayToSort[index] = hiBuffer.front();
		hiBuffer.pop();
		index++;
	}
}

// Quick sort takes in: 
// arrayToSort - the array that you're sorting
// lo - should be zero when calling
// hi - the max index of the array when calling
void Sorts::quickSort(int arrayToSort[], const int& lo, const int& hi)
{
	//Only sort there's something valid to sort
	if (lo < hi)
	{
		//Get the pivot index and sort
		int pivotElement = partition(arrayToSort, lo, hi);

		//Sort below the pivot, then above the pivot
		quickSort(arrayToSort, lo, pivotElement - 1);
		quickSort(arrayToSort, pivotElement + 1, hi);
	}
}

int Sorts::partition(int arrayToSort[], const int& lo, const int& hi)
{
	int pivot = lo;
	int pivotElement = arrayToSort[lo];

	for (int i = lo + 1; i <= hi; i++)
	{
		/* If you want to sort the list in the other order, change "<=" to ">" */
		if (arrayToSort[i] <= pivotElement)
		{
			pivot++;
			swap(arrayToSort[i], arrayToSort[pivot]);
		}
	}

	swap(arrayToSort[pivot], arrayToSort[lo]);

	return pivot;
}

void Sorts::heapSort(int arrayToSort[], const int& length)
{
	int max_index = length - 1;
	int finalIndex = 0;
	
	//create a heap by bubbling up each element of the supplied array
	for (int i = max_index; i >= 0; i--)
	{
		bubbleUp(arrayToSort, i);
	}

	//then we pop each value off and save it at the end of the array
	for (int i = 0; i < length; i++)
	{
		//save the biggest value in the MAX heap
		int temp = arrayToSort[0];
		finalIndex = max_index - i;

		//copy the last value in the max heap to the head
		arrayToSort[0] = arrayToSort[finalIndex];

		//save the biggest remaining value in the final index
		arrayToSort[finalIndex] = temp;

		//bubble down only for the remaining heap
		bubbleDown(arrayToSort, 0, finalIndex);
	}
}

void Sorts::bubbleUp(int arrayToSort[], const int& childIndex)
{
	int parentIndex = (childIndex - 1) / 2;

	//First we convert the array into a heap

	//the parent should always be bigger than child in a MAX heap
	if (arrayToSort[childIndex] > arrayToSort[parentIndex])
	{
		swap(arrayToSort[childIndex], arrayToSort[parentIndex]);

		//if we've swapped, call the parent
		bubbleUp(arrayToSort, parentIndex);
	}
}

void Sorts::bubbleDown(int arrayToSort[], const int& parentIndex, const int& length)
{
	int lChildIndex = 2 * parentIndex + 1;
	int rChildIndex = 2 * parentIndex + 2;

	//if the left and right child are in the array, compare the parent to each.
	//if the parent is larger, then swap it with the biggest child and then run bubble down for
	//the child index

	//Case where left and right child exist in the array
	if (lChildIndex < length && rChildIndex < length)
	{
		if (arrayToSort[lChildIndex] > arrayToSort[rChildIndex])
		{
			if (arrayToSort[parentIndex] < arrayToSort[lChildIndex])
			{
				//swap, recurse
				swap(arrayToSort[parentIndex], arrayToSort[lChildIndex]);
				bubbleDown(arrayToSort, lChildIndex, length);
			}
		}
		else
		{
			if (arrayToSort[parentIndex] < arrayToSort[rChildIndex])
			{
				//swap, recurse
				swap(arrayToSort[parentIndex], arrayToSort[rChildIndex]);
				bubbleDown(arrayToSort, rChildIndex, length);
			}
		}
	}
	//case where only the left child exists in the array
	else if (lChildIndex < length)
	{
		if (arrayToSort[parentIndex] < arrayToSort[lChildIndex])
		{
			//swap, recurse
			swap(arrayToSort[parentIndex], arrayToSort[lChildIndex]);
			bubbleDown(arrayToSort, lChildIndex, length);
		}
	}
}