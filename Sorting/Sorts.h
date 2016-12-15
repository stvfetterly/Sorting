#pragma once

class Sorts
{
public:
	static void bubbleSort(int arrayToSort[], const int& length);
	static void heapSort(int arrayToSort[], const int& length);
	static void quickSort(int arrayToSort[], const int& lo, const int& hi);
	static void mergeSort(int arrayToSort[], const int& lo, const int& hi);
private:
	static void swap(int& firstVal, int& secondVal);
	static void merge(int arrayToSort[], const int& lo, const int& mid, const int& hi);
	static int partition(int arrayToSort[], const int& lo, const int& hi);
	static void bubbleUp(int arrayToSort[], const int& childIndex);
	static void bubbleDown(int arrayToSort[], const int& parentIndex, const int& length);
};