//Programmer: Bryan K Clark
//Email: bryan.clark@email.wsu.edu
//Phone: (509)294-4161

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "ArraySorter.h"

int* genArr(int count);

int myatoi(char* str)
{
	int output = 0;
	int i=0;
	while( 48 <= str[i] && str[i] <=57 ){
		output = output*10 + (str[i] - 48) ;
		i++;
	}
	
	return output;
}

void sortTimer(clock_t time) {
	// Stop the timer
	time = clock() - time;
	cout << "Sorted in " << ((double)time / CLOCKS_PER_SEC) << " seconds!" <<endl;
}