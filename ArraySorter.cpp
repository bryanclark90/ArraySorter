///Programmer: Bryan K Clark
//Email: bryan.clark@email.wsu.edu
//Phone: (509)294-4161
//Below is the beautiful implementation of the array sorter  function.
//For more info see main.cpp

#include "ArraySorter.h"


ArraySorter::ArraySorter(void)
{
}

/*
 * @function   isSorted(int* arr, int n)
 *
 * @param      int* arr         the array of elements to work with
 * @param      int n            length of array
 *
 * @returns    true if a sorted list, false otherwise
 *
 */
bool ArraySorter::isSorted(int* arr, int n)
{
	for (int i = 1; i < n; i++) {
		// If an item is less than the one before it, then we're not sorted
		if (arr[i] < arr[i - 1]) {
			return false;
		}
	}
	return true;
}

/*
 * @function   insertionSort(int* arr, int n, int startIndex, int gap)
 *
 * @param      int* arr         the array of elements to work with
 * @param      int startIndex   starting point
 * @param      int gap          gap to do work on
 *
 * @returns    a sorted list
 *
 *             buils an array one element at a time yb comparison        
 */
void ArraySorter::insertionSort(int* arr, int n, int startIndex, int gap)
{
	
	// take in an array
	// n is the placement in the array at the end
	// starindex = beginning of the index
	// gap is distance between comparison functions
	int j = startIndex;

	// while the gap is still available in the array increment by gap
	for (int p = gap; p<=(n-1); p++) {
		int temp = arr[p];
		// while place j is not of gap size and (j - gap) is smaller than temp
		for( j = p; ((j  >= gap) && (arr[j-gap] > temp)); j -= gap) 
		{
			arr[j] = arr[j-gap]; // replace
		}
		arr[j] = temp;
	}

}

void ArraySorter::mergeSort(int* arr, int n)
{
	int p = 0;
	myMergeSort(arr, p,n); // calls the helper function 
}

/*
 * @function   myMergeSort(int* arr, int p, int n)
 *
 * @param      int* arr         the array of elements to work with
 * @param      int p            left side start of array
 * @param      int n            right side start of array
 *
 * @returns    a sorted list
 *
 *             does a divide and conquer sorting that divides an array
 *			   in half until down to a size of 1 then comparitvely rebuilds
 *             a sorted array. Is stable but not in place.            
 */
void ArraySorter::myMergeSort(int* arr, int p, int n)
{
	//recursively divide into sub arrays
	if(p < n-1) {
		int q = (p+n)/2;
		myMergeSort(arr, p, q);
		myMergeSort(arr, q, n);
		//combine two previous subarrays
		combine(arr, n, p, q);  
	}	
}

/*
 * @function   combine(int* arr, int n, int p, int q)
 *
 * @param      int* arr         the array of elements to work with
 * @param      int n            length of full array
 * @param      int p            length of right side of array
 * @param      int q            the start of right side array
 *
 * @returns    a recmobination of subarrays
 *            
 */
 void ArraySorter::combine(int* arr, int n, int p, int q)
{
	
	int* temp = new int[n-p]; 
	//get left side array
	int fromLeft = p; 
	//get right side array
	int fromMid = q; 

	// while k is less than array size
	for(int k = 0; k < (n-p); k++) {
		if ((fromMid >= n)||((fromLeft < q)
		    &&((arr[fromLeft]<=arr[fromMid])))) {
			temp[k] = arr[fromLeft];
			fromLeft++;
		}
		// or right side
		else {
			temp[k] = arr[fromMid];
			fromMid++;
		}
	}
	for( int k = p; k < n; k++) {
		arr[k] = temp[k-p]; // rebuild sorted array
	}
	
}


void ArraySorter::quickSort(int* arr, int n)
{
	quickSorter( arr, 0, n-1); // helper funtion for Quick sort
}

/*
 * @function   shellSort(int* arr, int n)
 *
 * @param      int* arr         the array of elements to work with
 * @param      int left         length of left side array
 * @param      int right        length of right side of array
 *
 * @returns    a sorted list
 *
 *             does an unstable, not inplace comparison sort, using divide and conquer             
 */
void ArraySorter::quickSorter( int* arr, int left, int right)
{
	if(left == right)
		return;
	//set to smallest value
	int i = left; 
	//set to largest
	int  j = right;
	//set pivot to two/thirds
	int pivot = arr[((right-left)*(2/3)+left)]; 
	// SORTING ALGORITHIM
	while (i <= j) {
	  	// while value of array is less than the pivot value
	 	//increment the "left" array
		while (arr[i] < pivot) {
			  i++; 
		}
		// while value of array is greater than the pivot value
		// deincrement the "right" array 
		while (arr[j] > pivot) {
			j--; 
		}
		if (i <= j) {
			swap(arr, i, j); 
			 i++;
			 j--;
		}
	}
	// Recursively minimize
	if (left < j) {
		quickSorter(arr, left, j);
	}
	if (i < right) {
		quickSorter(arr, i, right);
	}
}


/*
 * @function   shellSort(int* arr, int n)
 *
 * @param      int* arr         the array of elements to work with
 * @param      int n            the length of the array
 * @param      int* gapVals     the list of gaps to work with
 * @param      int gapValsCount the number of gaps to sort with
 *
  * @returns    a sorted list
 *
 *             does an inplace comparison sort sort, sorts far elements then closer based on gaps             
 */
 void ArraySorter::shellSort(int* arr, int n, int* gapVals, int gapValsCount)
{
	// Do an insertion sort pass for each of the gap values
	int i;
	for (i = 0; i < gapValsCount; i++) {
		for (int j = 0; j < gapVals[i]; j++) {
			insertionSort(arr, n, j, gapVals[i]);
		}
	}

}

/*
 * @function   heapSort(int* arr, int n)
 *
 * @param      int* arr      the array of elements to work with
 * @param      int n         the length of the array
 *
 * @returns    a sorted list
 *
 *             does heap sort             
 */
bool ArraySorter::heapSort(int* arr, int n)
{
	if(arr == NULL) {
		cout << "ARRAY IS EMPTY" << endl;
		return false;
	}
	//max location that is not NULL character
	int high = n-1;
	//build a heap
	makeHeap(arr, 0, high);
	while(high > 0) {
		//Swamp max element with the high index
		swap(arr, high, 0);
		--high;
		//check heap
		makeValidHeap(arr, 0, high);
	}
	return true;	
}

/*
 * @function   makeHeap(int* arr, int root, int high)
 *
 * @param      int* arr      the array of elements to work with
 * @param      int low       the location to start the heap
 * @param      int high      the highest element in the heap
 *
 * @returns    a valid heap
 *
 *             creates a heap             
 */
void ArraySorter::makeHeap(int* arr, int low, int high)
{
	//begin with middle element
	int middle = (high - low - 1)/2;
	while(middle >= 0) {
		makeValidHeap(arr, middle, high);
		--middle;
	}
	return;
}

/*
 * @function   makeValidHeap(int* arr, int root, int high)
 *
 * @param      int* arr      the array of elements to work with
 * @param      int root      the location to make the heap valid from
 * @param      int high      the highest element in the heap
 *
 * @returns    a valid heap
 *
 *             takes in a heap and does action on it to make valid             
 */
void ArraySorter::makeValidHeap(int* arr, int root, int high)
{
	while((root*2)+1 <= high) {
		//get children of current node
		//located at 2n+1(L) and 2n+2(R)
		int leftSide = (root * 2) + 1;
		int rightSide = leftSide + 1;
		int swapIndex = root;
		//check if root is less than left child
		if( arr[swapIndex] < arr[leftSide]) {
			swapIndex = leftSide;
		}
		//check if right child exists and less than current node
		if((rightSide <= high)&&(arr[swapIndex] < arr[rightSide])) {
			swapIndex = rightSide;
		}	
		//swap the two index locations if they aren't equal
		if(swapIndex != root) {
			swap(arr, root, swapIndex);
			root = swapIndex;
		}
		else {
			break;
		}
	}
	return;
}

/*
 * @function   displayArr(int* arr, int count, bool isSorted)
 *
 * @param      int arr       the array of elements to work with
 * @param      int count     the number of elements in the arr
 * @param      bool isSorted true if arr is sorted, false otherwise
 *
 * @returns    nothing
 *
 *             displays all the elements in the array             
 */
void displayArr(int* arr, int count, bool isSorted) 
{
	if(isSorted) {
		// Show the contents
		cout << " Sorted Array contents (" << count << " items):";
		for (int i = 0; i < count; i++) {
			cout << " " << arr[i];
		}
	}
	else {
		// Show the contents
		cout << "Unsorted Array contents (" << count << " items):";
		for (int i = 0; i < count; i++) {
			cout << " " << arr[i];
		}
	}
	cout << endl << endl;
}
