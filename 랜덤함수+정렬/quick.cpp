#include "stdafx.h"
void swap(int*, int*);
void sort(int* arr, int left, int right)
{
	static int count = 0;
	int low = left, high = right, pivot = *(arr + left);
	if (left < right) 
	{
		while (low < high) {
			do
			{
				count++;
				low++;
			} while (*(arr + low) < pivot);
			while (*(arr + high) > pivot)
			{
				count++;
				high--;
			}
			if (low < high)
			{
				swap((arr + high), (arr + low));
			}
		}
		swap((arr+left), (arr + high));
		sort(arr, left, high-1);
		sort(arr, low, right);
	}
	printf("count : %d\n", count);
}