//Programmer: Bryan K Clark
//Email: bryan.clark@email.wsu.edu
//Phone: (509)294-4161


#include "main.h"

using namespace std;

// Generates an array with random numbers in the range [0,1000]
int* GenArr(int count)
{
	int* arr = new int[count];
	for (int i = 0; i < count; i++)
	{
		arr[i] = rand() % 1001;
	}
	return arr;
}

int main(int argc, char* argv[])
{
	// Seed the random number generator
	srand(time(NULL));
	
	int count = 10000;
	int* numsOriginal = GenArr(count);

	// Create the sorter object
	ArraySorter sorter;

	while (true)
	{
		// Ask for an action
		cout << "Choose option:" << endl;
		cout << "  1 = Display array contents (may be VERY long)" << endl;
		cout << "  2 = Sort with insertion sort (may be slow)" << endl;
		cout << "  3 = Sort with shell sort (gap 5 then gap 1)" << endl;
		cout << "  4 = Sort with shell sort (gap 12, then gap 7, then 3, then 1)" << endl;
		cout << "  5 = Sort with mergesort" << endl;
		cout << "  6 = Sort with quicksort" << endl;
		cout << "  7 = Sort with Heap Sort" << endl;
		cout << "  (anything else) = quit" << endl;
		cout << "? ";
		int opt = -1;
		cin >> opt;

		// Make a copy of the number array
		int* nums = new int[count];
		for (int i = 0; i < count; i++)
		{
			nums[i] = numsOriginal[i];
		}

		clock_t time = clock();

		bool didSort = true;
		if (1 == opt)
		{
			// Show the contents
			cout << "Array contents (" << count << " items):";
			for (int i = 0; i < count; i++)
			{
				cout << " " << nums[i];
			}
			cout << endl << endl;
			didSort = false;
		}
		else if (2 == opt)
		{
			sorter.InsertionSort(nums, count);
		}
		else if (3 == opt)
		{
			int gaps[2] = {5, 1};
			sorter.ShellSort(nums, count, gaps, 2);
		}
		else if (4 == opt)
		{
			int gaps[4] = {12, 7, 3, 1};
			sorter.ShellSort(nums, count, gaps, 4);
		}
		else if (5 == opt)
		{
			sorter.MergeSort(nums, count);
		}
		else if (6 == opt)
		{
			sorter.QuickSort(nums, count);
		}
		else if (7 == opt)
		{
			sorter.HeapSort(nums, count);
		}
		else
		{
			delete [] nums;
			break;
		}

		if (didSort)
		{
			// Stop the timer
			time = clock() - time;
			
			// Verify
			if (!ArraySorter::IsSorted(nums, count))
			{
				cout << endl << "ERROR: Array is NOT correctly sorted!" << endl << endl;
			}
			else
			{
				cout << "Array contents verified as correctly sorted!" << endl;
				cout << "Sorted in " << ((double)time / CLOCKS_PER_SEC) << " seconds!" <<endl;
				cout << endl;
				cout << "Press 1 to compare the two array contents" << endl;
				int opt = -1;
				cin >> opt;
				if(opt == 1)
				{
						cout << "Original Array: ";
						for(int i = 0; i < count; i++)
						{
							cout << numsOriginal[i] << " ";
						}
						cout << endl;
						cout << endl;
						cout << "Sorted Array:   ";
						for(int i = 0; i < count; i++)
						{
							cout << nums[i] << " ";
						}
						cout << endl;
						cout << endl;
				}
			}

			cout << "New Array will be generated to do sorting on!" << endl;
			//GENERATE A NEW ARRAY AFTER PREVIOUS ARRAY IS SORTED
			numsOriginal = GenArr(count);
		}

		cout << endl << endl;

		// Free the copy (it will be rebuilt in the next loop iteration)
		delete [] nums;
	}

	delete [] numsOriginal;
}
