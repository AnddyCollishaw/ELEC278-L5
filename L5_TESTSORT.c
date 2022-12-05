#include <stdio.h>
#include <time.h>




// Array containing initial data
		// how much actual data
int data [100]	= {
	44, 22,  3, 71, 16, 82,  1,  9, 99, 10,
	32, 18, 77, 28,  9, 17, 52, 61, 38, 12 };

// "Global" variables
int					verbose = 0;
long unsigned int	swaps = 0;			// may be lots of swaps

#include "L5_UTILITYCODE.c"

#include "L5_QUICKSORT2.c"

#define MAXINDEX   =   19;

int main (void)
{
	int			rslt, max, rslt1;
	clock_t		start, mid, end;
	int			*pa, *pa1;			// pointer to array;
	int			size, size1;

	// Fetch data
	size = read_int_file ("RANDOM.TXT", &pa);
	size1 = read_int_file("RANDOM.TXT", &pa1);
	//size = read_int_file ("ASCENDING.TXT", &pa);
	//size = read_int_file ("DESCENDING.TXT", &pa);
	//return 0;

	if (verbose)
		printarray ("Array before any work done:", pa, 0, size-1, 10);
	printf ("==Check array before sort\n");
	if (array_sorted(NULL, pa, 0, size-1, 1))	{
		printf ("Warning: Array is initially sorted\n");
	} else	{
		printf ("    Array is unsorted\n");
		}
	swaps = 0;
	
	start = clock();
	//printf ("Bubble Sort\n");		rslt = bubblesort (pa, 0, size-1);           //OK
	//printf ("Insertion Sort\n");	rslt = insertionsort (pa, 0, size-1);        //OK
	//printf ("Heap Sort\n");		rslt = heapsort (pa, size);      //2B tested
	//printf ("Merge Sort\n");		rslt = mergesort (pa, 0, size-1);            //OK
	printf ("Quicksort\n");		 rslt1 = quicksort2 (pa1, 0, size-1);
	mid = clock(); 
	printf ("Quicksort2\n");		 rslt = quicksorthybrid (pa, 0, size-1);    
	
	
	// Note: Radix sort does not need to be included in the comparisons
	//printf ("Radix sort\n");		rslt = radixsort (pa, size);			 	 //OK
	//printf ("Selection Sort (Iterative)\n");	rslt = selsortI (pa, 0, size-1); //OK
	//printf ("Selection Sort (Recursive)\n");  rslt = selsortR (pa, 0, size-1); //OK
	//printf ("Shell Sort\n");		rslt = ShellSort (pa, 0, size-1);            //OK
	end = clock();
	
	// printf ("End time: %ld  Start time:  %ld  Diff: %ld\n",
	// 			end, start, end-start);
	// if (verbose || 1)
	// 	printarray ("Final array:", pa, 0, size-1, 8);
	// if (array_sorted(NULL, pa, 0, size-1, 1))
	// 	printf ("==After sort, array is sorted\n");
	// else	{
	// 	printf ("Sort failed - array is not sorted\n");
	// 	//printarray ("Sort error: ", pa, 0, size-1, 8);
	// 	}
	// printf ("Swaps:  %ld  CPU time:  %ld\n", rslt, end-start);




//create pointer for file 
FILE *fp; 

	//creaet//open file and set it to the pointer 
    fp = fopen("LAB5_PART3.TXT", "w");

	//check that the file was oppened properly 
    if(fp == NULL){
        printf("\nCouldn't Open File\n");
        return -1;
	}

	//Print the data into the file 
	fprintf(fp,"Collishaw, Andy - Kung, Matthew  Size of Dataset: %d\n", size);
	fprintf(fp,"                   Elapsed Time      Number of Swaps\n"); 
	fprintf(fp,"Original Quicksort: %d               %d\n", mid-start, rslt1);
	fprintf(fp,"Hyprid Quicksort:   %d               %d", end-mid, rslt);

	 
	return 0;
}//main()


