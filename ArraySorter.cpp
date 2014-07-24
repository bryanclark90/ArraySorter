//Programmer: Bryan K Clark
//Email: bryan.clark@email.wsu.edu
//Phone: (509)294-4161


#include "ArraySorter.h"


ArraySorter::ArraySorter(void)
{
}

void ArraySorter::InsertionSort(int* arr, int n)
{
	InsertionSort(arr, n, 0, 1);
}

void ArraySorter::InsertionSort(int* arr, int n, int startIndex, int gap)
{
	
	// take in an array
	// n is the placement in the array at the end
	// starindex = beginning of the index
	// gap is distance between comparison functions
	int j = startIndex;

	for (int p = gap; p<=(n-1); p++) // while the gap is still available in the array increment by gap
	{
		int temp = arr[p]; // sets temp to place in array
		for( j = p; ((j  >= gap) && (arr[j-gap] > temp)); j -= gap) //while place j is not of gap size and (j - gap) is smaller than temp
		{
			arr[j] = arr[j-gap]; // replace
		}
		arr[j] = temp;
	}

}

// Checks to see if the array is in sorted order
bool ArraySorter::IsSorted(int* arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		// If an item is less than the one before it, then we're not sorted
		if (arr[i] < arr[i - 1])
		{
			return false;
		}
	}

	return true;
}

void ArraySorter::MergeSort(int* arr, int n)
{
	int p = 0;
	MyMergeSort(arr, p,n); // calls the helper function 
}

//Merge sort helper function!
void ArraySorter::MyMergeSort(int* arr, int p, int n)
{
	if(p < n-1)
	{
		int q = (p+n)/2;
		MyMergeSort(arr, p, q); //recursion 
		MyMergeSort(arr, q, n);
		Combine(arr, n, p, q); // build a sorted array 
	}	
}

void ArraySorter::Combine(int* arr, int n, int p, int q)
{
	
	int* temp =new int[n-p]; // creates temp variable of full array size
	int fromLeft = p; // start value
	int fromMid = q; // mid array value

	for(int k = 0; k < (n-p); k++) // while k is less than array size
	{
		if ((fromMid >= n)||((fromLeft < q)&&((arr[fromLeft]<=arr[fromMid])))) // decidesif temp value should be from left
		{
			temp[k] = arr[fromLeft];
			fromLeft++;
		}
		else // or right side
		{
			temp[k] = arr[fromMid];
			fromMid++;
		}
	}
	for( int k = p; k < n; k++)
	{
		arr[k] = temp[k-p]; // rebuild sorted array
	}
	
}


void ArraySorter::QuickSort(int* arr, int n)
{
	int left = 0;
	int right = n-1;
	QuickSorter( arr, left, right); // helper funtion for Quick sort
}

// QUICK SORT HELPER
void ArraySorter::QuickSorter( int* arr, int left, int right)
{
	if(left == right)
	{
		return;
	}

	int i = left;  // sets i to left: smallest value 
	int  j = right; // sets j to right: "largest" value
	int pivot = arr[((right-left)*(2/3)+left)]; // two thirds of right value
	
	  // SORTING ALGORITHIM
	  while (i <= j) 
	  {
		  
			while (arr[i] < pivot) // while value of array is less than the pivot value
			{
				  i++; //increment the "left" array
			}
			while (arr[j] > pivot) // while value of array is greater than the pivot value
			{ 
				j--; // deincrement the "right" array
			}
			if (i <= j) 
			{
				// Swap(arr[i], arr[j]); // swaps the array values at i and j positions
				 int temp = arr[i];
				 arr[i] = arr[j];
				 arr[j] = temp;  
				  i++;
				  j--;
			}
	  }
			// RECURSIVELY MINIMIZE THE OBJECTS BEING SORTED
			if (left < j)
			{
				QuickSorter(arr, left, j);
			}
			if (i < right)
			{
				QuickSorter(arr, i, right);
			}
	}


void ArraySorter::ShellSort(int* arr, int n, int* gapVals, int gapValsCount)
{
	// Do an insertion sort pass for each of the gap values
	int i;
	for (i = 0; i < gapValsCount; i++)
	{
		for (int j = 0; j < gapVals[i]; j++)
		{
			InsertionSort(arr, n, j, gapVals[i]);
		}
	}

}

bool ArraySorter::HeapSort(int* arr, int n)
{
	if(arr == NULL)
	{
		cout << "ARRAY IS EMPTY" << endl;
		return false;
	}
	//get size of array
	int size = n;  
	//max location that is not NULL character
	int high = size-1;
	//build a heap
	MakeHeap(arr, 0, high);
	while(high > 0)
	{

		//Swamp max element with the high index
		int temp = arr[high];
		arr[high] = arr[0];
		arr[0] = temp;
		--high;
		//check heap
		MakeValidHeap(arr, 0, high);
	}
	
		
}

void ArraySorter::MakeHeap(int* arr, int Low, int High)
{
	//begin with middle element
	int Middle = (High - Low - 1)/2;
	while(Middle >= 0)
	{
		MakeValidHeap(arr, Middle, High);
		--Middle;
	}
	return;
}

void ArraySorter::MakeValidHeap(int* arr, int Low, int High)
{
	//beginning index
	int root = Low;

	while((root*2)+1 <= High)
	{
		//get children of current node
		//located at 2n+1(L) and 2n+2(R)
		int LeftSide = (root * 2) + 1;
		int RightSide = LeftSide + 1;
		int SwapIndex = root;
		//check if root is less than left child
		if( arr[SwapIndex] < arr[LeftSide])
		{
			SwapIndex = LeftSide;
		}
		//check if right child exists and less than current node
		if((RightSide <= High)&&(arr[SwapIndex] < arr[RightSide]))
		{
			SwapIndex = RightSide;
		}
		if(SwapIndex != root)
		{
			//switch the two index locations if they aren't equal
			int temp = arr[root];
			arr[root] = arr[SwapIndex];
			arr[SwapIndex] = temp;
			// set new root
			root = SwapIndex;
		}
		else
		{
			break;
		}
	}

	return;

}


