#include "stdafx.h"
int search(int* arr, int left, int right, int input)
{
	int mid = (left + right) / 2;
	if (*(arr + mid) == input)
	{
		return mid+1;
	}
	if (*(arr + mid) > input)
	{
		return search(arr, left, mid - 1, input);
	}
	if (*(arr + mid) < input)
	{
		return search(arr, mid+1,right, input);
	}
	if (left >= right)
	{
		return -1;
	}
}
void search_print(int search)
{
	if (search == -1)
	{
		printf("ã�°��� ����.");
	}
	else
	{
		printf("ã�� ���� %d�� �ִ�.", search);
	}
}