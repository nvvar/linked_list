// 랜덤함수+정렬.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


void subst(int*);
void sort(int*, int, int);
void print(int*);
int search(int*, int, int, int);
void search_print(int);


int main()
{
	int arr[ARR_MAX] = { 0 };
	int input;

	subst(arr);
	sort(arr, 0, ARR_MAX-1);
	print(arr);
	scanf_s("%d", &input);
	search_print(search(arr, 0, ARR_MAX-1, input));

    return 0;
}

