#include "stdafx.h"
void subst(int* arr) {
	srand((unsigned)time(NULL));
	int twice[1000] = { 0 };
	for (int i = 0; i < ARR_MAX; i++)
	{
		*(arr + i) = (rand() % 1000)+1;
		printf("%d\n", *(arr + i));
		if (twice[*(arr + i) - 1]==1)
		{
			i--;
			continue;
		}
		twice[*(arr + i) - 1] = 1;
	}
}