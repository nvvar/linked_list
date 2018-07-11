#include "stdafx.h"
int search(int* arr, int left, int right, int input)
{
	int mid = (left + right) / 2;
	if (*(arr + mid) < input)
	{
		return search(arr, mid + 1, right, input);
	}
	if (*(arr + mid) >= input)
	{
		if (*(arr + (mid - 1)) < input)
		{
			return mid+1;
		}
		else if (mid == right)
		{
			return -1;
		}
		return search(arr, left, mid - 1, input);
	}
}
void search_print(int search)
{
	if (search == -1)
	{
		printf("찾는값이 없다.");
	}
	else
	{
		printf("찾는 값은 %d에 있다.", search);
	}
}