#include "stdafx.h"

struct node {
	int data;
	struct node* link;
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
		point = point->link;
	}
	return -1;
}

void insert() {
	int newdata;
	Node* befpoint = NULL;
	Node* point = head;

	printf("삽입할 데이터: ");
	scanf("%d", &newdata);
	
	while (point&&point->data < newdata) {
		befpoint = point;
		point = point->link;
	}
	
	if (!befpoint)
	{
		Node* newnode = (Node*)malloc(sizeof(Node));
		newnode->link = head;
		newnode->data = newdata;
		head = newnode;
	}
	else
	{
		Node* newnode = (Node*)malloc(sizeof(Node));
		newnode->link = befpoint->link;
		newnode->data = newdata;
		befpoint->link = newnode;
	}
}

void print()
{
	Node* p = head;
	if (!head)
	{
		printf("데이터가 없습니다.");
		return;
	}
	printf("\n");
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->link;
	}
	printf("\n출력완료\n\n");
}

void del()
{
	if (head == NULL)
	{
		printf("삭제할 노드가 없습니다.");
	}
	else {
		Node* p = head->link;
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
		case 4: {printf("%d번째 데이터에 있습니다.\n", search() + 1); break; }
		case 5: {return 0; }
		default: break;
		}
	}
	return 0;
}

