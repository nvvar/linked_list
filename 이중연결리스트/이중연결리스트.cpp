#include "stdafx.h"
#define AS true
#define DE false

struct node {
	int data;
	struct node* l_link;
	struct node* r_link;
};
typedef struct node Node;
Node* head = NULL;
Node* tail = NULL;

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
	Node* point = head;

	printf("삽입할 데이터: ");
	scanf("%d", &newdata);
	
	while (point&&point->data < newdata) {
		point = point->r_link;
	}
	if (point&&point->data == newdata)
	{
		printf("\n중복\n");
		return;
	}
	if (!point)
	{
		Node* newnode = (Node*)malloc(sizeof(Node));
		newnode->r_link = NULL;
		newnode->l_link = tail;
		newnode->data = newdata;
		if (!head) {
			head = newnode;
		}
		else
		{
			newnode->l_link->r_link = newnode;
		}
		tail = newnode;
	}
	else
	{
		Node* newnode = (Node*)malloc(sizeof(Node));
		if (!point->l_link) {
			head = newnode;
		}
		else
		{
			point->l_link->r_link = newnode;
		}
		newnode->l_link = point->l_link;
		point->l_link = newnode;
		newnode->r_link = point;
		newnode->data = newdata;
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
		p = p->r_link;
	}
	printf("\n출력완료\n\n");
}

void upsidedown()
{
	Node* p = tail;
	if (!tail)
	{
		printf("데이터가 없습니다.");
		return;
	}
	printf("\n");
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->l_link;
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
		printf("\n1:삽입\n2:삭제\n3:프린트(오름차순)\n4:프린트(내림차순)\n5:검색\n6:종료\n\n");
		scanf("%d", &select);
		switch (select) {
		case 1: insert();
		case 3: {print(); break; }
		case 2: {del(); break; }
		case 4: {upsidedown(); break; }
		case 5: {printf("%d번째 데이터에 있습니다.\n", search() + 1); break; }
		case 6: {return 0; }
		default: break;
		}
	}
	return 0;
}

