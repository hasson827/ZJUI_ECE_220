// Program to find maximum sum subarray in a given 2D array
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

 
// Implementation of Kadane's algorithm for 1D array. The function returns the
// maximum sum and stores starting and ending indexes of the maximum sum subarray
// at addresses pointed by start and finish pointers respectively.
int find_maxSum(int* arr, int* start, int* finish, int n)
{
      // initialize sum, maxSum
    int sum = 0, maxSum =0;
    *start = 0; // Initialize starting index
    *finish = -1; // Initialize ending index
    int local_start = 0; // Initialize local starting index
    for (int i = 0; i < n; i++) {
        sum += arr[i]; // Add current element to sum

        // If current sum is greater than maxSum, update maxSum and finish index
        if (sum > maxSum) {
            maxSum = sum;
            *start = local_start; // Update start index
            *finish = i; // Update finish index
        }

        // If current sum becomes negative, reset it and update local starting index
        if (sum < 0) {
            sum = 0;
            local_start = i + 1; // Move local start to next index
        }
    }
    // If maxSum is still 0, it means all elements are negative
    if (maxSum == 0) {
        *start = 0; // Set start to first index
        *finish = n - 1; // Set finish to last index
        maxSum = arr[0]; // Set maxSum to the first element
        for (int i = 1; i < n; i++) {
            if (arr[i] > maxSum) {
                maxSum = arr[i]; // Find the maximum single element
                *start = i; // Update start index
                *finish = i; // Update finish index
            }
        }
    }
    return maxSum; // Return the maximum sum found 
}
 
int main(int argc, char **argv)
{   int i, n, start, finish, maxSum;
//check for input file   
    FILE * in;
    if(argv[1]== NULL) {
        printf("You need a input file.\n");
        return -1;
    }
    in = fopen(argv[1], "r");
    if(in == NULL) {
        return -1;
    }
//read in the size of the array	
    fscanf(in, "%d", &n);

//read the array 
    int * arr=(int *)malloc(n*sizeof(int));
    for(i=0; i<n ;i++)
        fscanf(in, "%d", &arr[i]);
    
    maxSum=find_maxSum(arr, &start, &finish, n);

    printf("the subarry with max summation starts at %d, and ends at %d; the max summation is %d.\n", start, finish, maxSum);

    return 0;}
