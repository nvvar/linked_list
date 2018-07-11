#include "stdafx.h"
void process(int input_x, int input_y)
{
	int* arr = (int*)malloc(sizeof(int)*input_x*input_y);
	int x = 0, y = input_y - 1, count = 0, temx = x, temy = y;
	printf("\n\n%d %d %d %d %d\n\n", x, y, count, temx, temy);
	for (; count < input_x*input_y; count++)
	{
		*(arr + x + (y*input_x)) = count + 1;
		printf("x,y: %d, %d\n", x, y);
		y++;
		x++;
		if (x >= input_x || y >= input_y)
		{
			if (temy <= 0)
			{
				temx++;
			}
			else 
			{
				temy--;
			}
			x = temx;
			y = temy;
		}
	}
	for (int i = 0; i < input_y; i++)
	{
		for (int j = 0; j < input_x; j++)
		{
			printf("%04d ", *(arr + (i*input_x) + j));
		}
		printf("\n\n");
	}
}