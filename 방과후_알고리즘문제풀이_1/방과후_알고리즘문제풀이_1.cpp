// 방과후_알고리즘문제풀이_1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

int main()
{
	int input_x, input_y;
	scanf("%d %d", &input_y, &input_x);
	int* arr = (int*)malloc(sizeof(int)*input_x*input_y);
	int count = 0, x=0, y=0;
	int temx=0, temy=0;
	for (; count < input_x*input_y; count++)
	{
		*(arr + x + (y*input_x)) = count+1;
		x--;
		y++;
		if (y >= input_y|| x<0)
		{
			temx++;
			if (temx >= input_x)
			{
				temx--;
				temy++;
			}
			x = temx;
			y = temy;
		}
	}
	for (int i = 0; i < input_y; i++)
	{
		for (int j = 0; j < input_x; j++)
		{
			printf("%3d", *(arr + (i*input_x) + j));
		}
		printf("\n");
	}
    return 0;
}

