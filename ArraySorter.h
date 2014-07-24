//Email: bryan.clark@email.wsu.edu
//Phone: (509)294-4161

#include <iostream>
#include <math.h>
using namespace std;
#pragma once

class ArraySorter
{
private:
	// Add private helper functions here

public:
	ArraySorter(void);

	void InsertionSort(int* arr, int n, int startIndex, int gap);
	void InsertionSort(int* arr, int n);
	void MergeSort(int* arr, int n);
	void QuickSort(int* arr, int n);
	void ShellSort(int* arr, int n, int* gapVals, int gapValsCount);
	void Combine(int* arr, int n, int p, int q);
	void MyMergeSort(int* arr, int p, int n);
	void QuickSorter( int* arr, int left, int right);
	// Utility function that's implemented for you to verify that an 
	// array is in correct sorted order.
	static bool IsSorted(int* arr, int n);
	bool HeapSort(int* arr, int n);
	void MakeHeap(int* arr, int Low, int High);
	void MakeValidHeap(int* arr, int Low, int High);

	void Swap(int& a, int &b)
	{
		int temp = a;
		a = b;
		b = temp;
	};
};
