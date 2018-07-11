#include "stdafx.h"
void subst(int* arr) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < ARR_MAX; i++)
	{
		*(arr + i) = (rand() % 6) + 1;
		printf("%d\n", *(arr + i));
	}
}