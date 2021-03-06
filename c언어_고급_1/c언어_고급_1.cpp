// c언어_고급_1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

struct node {
	int data;
	struct node* r_link;
};
typedef struct node Node;
Node* head = NULL;

int search()
{
	Node* point = head;
	int searvalue;
	printf("검색할 데이터: ");
	scanf("%d", &searvalue);
	for (int i = 0; point != NULL; i++)
	{
		if (searvalue == point->data)
		{
			return i;
		}
		point = point->r_link;
	}
	return -1;
}

void insert() {
	int newdata;
	printf("삽입할 데이터: ");
	scanf("%d", &newdata);
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->r_link = head;
	newnode->data = newdata;
	head = newnode;
}

void print()
{
	Node* p = head;
	printf("\n");
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->r_link;
	}
	printf("\n출력완료\n\n");
}

void del()
{
	if (head == NULL)
	{
		printf("삭제할 노드가 없습니다.");
	}
	else{
	Node* p = head->r_link;
	free(head);
	head = p;
	}
}

int main()
{
	int select;
	while (1)
	{
		printf("\n1:삽입\n2:삭제\n3:프린트\n4:검색\n5:종료\n\n");
		scanf("%d", &select);
		switch (select) {
		case 1: insert();
		case 3: {print(); break; }
		case 2: {del(); break; }
		case 4: {printf("%d번째 데이터에 있습니다.\n",search()+1); break; }
		case 5: {return 0; }
		default: break;
		}
	}
    return 0;
}

