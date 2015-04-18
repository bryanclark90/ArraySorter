//Programmer: Bryan K Clark
//Email: bryan.clark@email.wsu.edu
//Phone: (509)294-4161


#include "main.h"

using namespace std;

// Generates an array with random numbers in the range [0,1000]
int* genArr(int count) {
	int* arr = new int[count];
	for (int i = 0; i < count; i++) {
		arr[i] = rand() % 1001;
	}
	return arr;
}

int main(int argc, char* argv[])
{
	// Seed the random number generator
	srand(time(NULL));
	
	int count = 10000;
	int* nums = genArr(count);

	// Create the sorter object
	ArraySorter sorter;

	while (true)
	{
		// Ask for an action
		cout << "-------------------------------------------------" << endl;
		cout << "--------------- Array Sorter Menu ---------------" << endl;
		cout << "Choose option from below:" << endl;
		cout << "  1 = Display array contents (may be VERY long)" << endl;
		cout << "  2 = Sort with insertion sort (may be slow)" << endl;
		cout << "  3 = Sort with shell sort (gap 5 then gap 1)" << endl;
		cout << "  4 = Sort with shell sort (gap 12, then gap 7, then 3, then 1)" << endl;
		cout << "  5 = Sort with mergesort" << endl;
		cout << "  6 = Sort with quicksort" << endl;
		cout << "  7 = Sort with Heap Sort" << endl;
		cout << "  8 = Generate a new array?" << endl;
		cout << "  9 = Programmer Info" << endl;
		cout << "  10 = quit" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "-------------------------------------------------" << endl; 
		cout << "? ";
		char input[10];
		cin >> input;
		int opt = myatoi(input);

		clock_t time = clock();
		int gaps[2] = {5, 1};
		int gap[4] = {12, 7, 3, 1};
		switch(opt) {
			case 1:
				// Show the contents
				displayArr(nums, count, sorter.isSorted(nums, count));
				break;
			case 2:
				sorter.insertionSort(nums, count, 0 ,1);
				if(sorter.isSorted(nums, count)) {
					sortTimer(time);
				}
				break;
			case 3:
				sorter.shellSort(nums, count, gaps, 2);
				if(sorter.isSorted(nums, count)) {
					sortTimer(time);
				}
				break;
			case 4:
				sorter.shellSort(nums, count, gap, 4);
				if(sorter.isSorted(nums, count)) {
					sortTimer(time);
				}
				break;
			case 5:
				sorter.mergeSort(nums, count);
				if(sorter.isSorted(nums, count)) {
					sortTimer(time);
				}
				break;
			case 6:
				sorter.quickSort(nums, count);
				if(sorter.isSorted(nums, count)) {
					sortTimer(time);
				}
				break;
			case 7:
				sorter.heapSort(nums, count);
				if(sorter.isSorted(nums, count)) {
					sortTimer(time);
				}
				break;
			case 8:
				cout << "Array is currently "<< count <<" elements!" << endl;
				cout << "How many elements would you like to sort?" << endl;
				cout << "WARNING: large numbers make take a while:" <<endl;
				cin >> input;
				count = myatoi(input);
				if(count < 0) {
					cout << "ERROR! Array cannot be less than 1!" << endl;
				}
				else {
					nums = genArr(count);
				}
				break;
			case 9:
				cout << endl;
				cout << "=================================================" << endl;
				cout << "============== My Contact Info ==================" << endl;
				cout << "Programmer:			Bryan Kieth Clark" << endl;
				cout << "Email:			bryan.clark@email.wsu.edu" << endl;
				cout << "Phone:			            (509)294-4161" << endl;
				cout << "=================================================" << endl;
				cout << "=================================================" << endl;
				cout << endl;
				break;
			case 10:
				delete [] nums;
				cout << "Goodbye!" <<endl;
				return 0;
			//display my personal info	
			default:
				{cout << "Invalid option!" << endl << endl;}
				break;
		}
		cout << endl << endl;
		cout << "Enter 'C' to Continue:" << endl;
		char temp = 'x';
		while(toupper(temp) != 'C')
			cin.get(temp);
	}
}
