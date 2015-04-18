//Email: bryan.clark@email.wsu.edu
//Phone: (509)294-4161

#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

#pragma once


class ArraySorter
{
private:
	// Add private helper functions here
	void quickSorter( int* arr, int left, int right);
	void myMergeSort(int* arr, int p, int n);
	void combine(int* arr, int n, int p, int q);
	void makeHeap(int* arr, int low, int high);
	void makeValidHeap(int* arr, int root, int high);
	
	void swap(int* arr, int a, int b)
	{
		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	};

public:
	ArraySorter(void);
	void insertionSort(int* arr, int n, int startIndex, int gap);
	void mergeSort(int* arr, int n);
	void quickSort(int* arr, int n);
	void shellSort(int* arr, int n, int* gapVals, int gapValsCount);
	bool heapSort(int* arr, int n);

	//utiity function
	static bool isSorted(int* arr, int n);
};
	
void displayArr(int* arr, int count, bool isSorted);
