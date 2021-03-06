#include "stdafx.h"
#define AS true
#define DE false

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

void insert(int sorttype) {
	int newdata;
	Node* befpoint = NULL;
	Node* point = head;
	
	printf("삽입할 데이터: ");
	scanf("%d", &newdata);
	if (sorttype == AS) {
		while (point&&point->data < newdata) {
			befpoint = point;
			point = point->r_link;
		}
	}
	else if(sorttype == DE)
	{
		while (point&&point->data > newdata) {
			befpoint = point;
			point = point->r_link;
		}
	}
	if (point&&point->data == newdata)
	{
		printf("\n중복\n");
		return;
	}
	if (!befpoint)
	{
		Node* newnode = (Node*)malloc(sizeof(Node));
		newnode->r_link = head;
		newnode->data = newdata;
		head = newnode;
	}
	else
	{
		Node* newnode = (Node*)malloc(sizeof(Node));
		newnode->r_link = befpoint->r_link;
		newnode->data = newdata;
		befpoint->r_link = newnode;
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

void upsidedown(bool* sorttype)
{
	*sorttype = !(*sorttype);
	Node* f = head;
	Node* s = NULL;
	Node* t = NULL;
	while (f != NULL)
	{
		t = s;
		s = f;
		f = f->r_link;
		if (s != NULL)
		{
			s->r_link = t;
		}
	}
	head = s;
	print();
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
	bool sorttype = AS;
	int select;
	while (1)
	{
		printf("\n1:삽입\n2:삭제\n3:프린트\n4:검색\n5:역순\n6:종료\n\n");
		scanf("%d", &select);
		switch (select) {
		case 1: insert(sorttype);
		case 3: {print(); break; }
		case 2: {del(); break; }
		case 4: {printf("%d번째 데이터에 있습니다.\n", search() + 1); break; }
		case 5: {upsidedown(&sorttype); break; }
		case 6: {return 0; }
		default: break;
		}
	}
	return 0;
}

