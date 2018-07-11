#include "stdafx.h"
void print(int* arr)
{
	for (int i = 0; i < ARR_MAX; i++)
	{
		printf("%d ", *(arr + i));
	}
	putchar('\n');
}