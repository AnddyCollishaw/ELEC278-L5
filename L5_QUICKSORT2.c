// Collishaw, Andy 20282214
// Kung, Matthew 20259215

#include <stdio.h>
//#include "L5_TESTSORT.c"

//Much of this code is taken from other parts of the lab 



// void printarrowatposition2 (int posn)
// // Prints a V - a down arrow - where the pivot value will be
// {
// 	int	i;
// 	for (i=0; i<posn; i++)		printf ("     ");
// 	printf ("   V\n");
// }//printarrowatposition2()

int counter = 0; 

int partution2 (int  *a,  int left, int right)
// Using locations a[left..right], partution2 fragment by picking a[left] as
// separator value, then working through bottom and top halves of the array,
// arranging - by swapping values if necessary - that all values smaller than
// the separator value are in the bottom part and all values larger are in
// the top part.
{
	int	ll, rr, pivotval;
	ll = left+1;
	rr = right;
	// choose pivot to be leftmost location
	pivotval = a[left];
	if (verbose)
		printf ("partution2 around value in position %d - %d\n", left, a[left]);
    while (ll < rr)	{
		// if one on left less than pivot, leave it alone
		if(a[ll] <= pivotval)	{ ll++; continue;}
		// if one on right greater than pivot, leave it
        if(a[rr] > pivotval)	{ rr--; continue;}
		// both left and right on wrong side - swap them
		swap(a, ll, rr);
       	}//endwhile
	// we stop when rr and ll collide. Place pivot value such that everything
	// to left is less and everything to right is same or greater.
	if (a[ll] < pivotval)	{
		swap(a, ll, left);
	} else	{
		swap(a, --ll, left);
		}
	return ll;
}//partution2()


// int quicksort2 (int *a,  int left, int right)
// {
	
// 	if (verbose)
// 		printf ("\nQuicksort: left = %d   right = %d\n", left, right);
// 	if (left < right)    {
// 		int  pivotndx = partution2 (a, left, right);
// 		if (verbose)	{
// 			printf ("    Completed partution2, pivot at: %d\n", pivotndx);
// 			// printarrowatposition2 (pivotndx);
// 			printarray (NULL, a, 0, 19, 1000);
// 			}
// 		quicksort2 (a, left, pivotndx-1);
// 		quicksort2 (a, pivotndx+1, right);
// 		}
	

	
// 	return swaps;
// }//quicksort()

int insertionsort2 (int *a, int min, int max)
// Work through array of numbers, placing each one in the correct place. Note
// that insertion sort differs from bubblesort in that with insertion sort, one
// value is moved to its relative place. In bubble sort, the largest value is
// found as the checking keeps choosing the larger of two values to keep
// moving.
{
	int		i, j;
	int		rslt = -1;

	// Check for errors
	if (a == NULL || (min > max))	{
		error ("insertionsort() called with invalid parameters");
	} else	{
		// initialize swaps so we know how many exchanges take place
		

		// Outer for loop works through values from min to max. Effectively,
		// we start by making the data in position relative 0 a sorted array containing
		// one element, then adding the rest of the array, one by one, to the
		// sorted part
		for (i = min; i <=max; i++) {
			// Now, i indicates which new element in the array is going to be
			// inserted into its correct position. At the end of each loop, one
			// more value is moved, and all of the bottom is ordered.
			for (j = i; j > min && (a[j - 1] > a[j]); j--) {
				swap(a, j, j - 1);
				}//endfor
			}//endfor
		rslt = swaps;
		}//endif
	return rslt;
}//insertionsort()

//quicksort hybrid function to determine wether quicksort or  insertion sort should be used 
int quicksorthybrid(int *arr, int Left, int Right)
{
 

int rslt = -1; 
  
  //while the partition is still open 
  while (Left < Right)
    {
		
		
	//if there are fewer than 32 datapoints in the partition apply insertion sort 
    if (Right-Left + 1 < 30 )
      {
        insertionsort2(arr, Left, Right);
      break;
    }
 
    else
       
        {
        int pivot = partution2(arr, Left, Right) ;
 
        
	    //use quicksort if the partition is above the threshold
	  	//if left side is less than ride side sort left first 
        if (pivot-Left<Right-pivot)
        {
            quicksorthybrid(arr, Left, pivot - 1);
            Left = pivot + 1;
        }
        else
        {
 
        
        //if right side of the pivot is less sort that first 
        quicksorthybrid(arr, pivot + 1, Right);
        Right = pivot-1;
        }
 
     }
 
   }
   
   //return the number of swaps 
   rslt = swaps; 
   return rslt; 
}
