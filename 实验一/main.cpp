using namespace std;
#include <iostream>
#include <stdlib.h>
# define null 0

typedef char ElemType; /* 字符型数据*/
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

int ListLength(LinkList L);
ElemType GetElem(LinkList L, int i);
void InsertList(LinkList &L, ElemType x, int i);
int DeleteElem(LinkList &L, int i);
int LocateElem(LinkList L, ElemType x);
void DisplayList(LinkList L);

LinkList LA;

int main()
{
	LA = NULL;
	//ElemType cs;
	int len = 0;
	InsertList(LA, 'a', 1);
	InsertList(LA, 'B', 2);
	InsertList(LA, 'C', 2);

	len = ListLength(LA);
	cout << "the length is " << len << endl;

	InsertList(LA, 'e', 3);
	InsertList(LA, 'd', 4);

	len = ListLength(LA);
	cout << "the length is " << len << endl;

	cout << "GetElem:" << GetElem(LA, 3) << endl;
	
	cout << "Locate:" << LocateElem(LA, 'C') << endl;
	
	DisplayList(LA);
	
	return 0;
}

int ListLength(LinkList L) {
	int n = 0;
	struct LNode *q = L;
	if (!L)
		cout << "链表为空" << endl;
	while (q)
	{
		n++;
		q = q->next;
	}
	return n;
}

ElemType GetElem(LinkList L, int i) {
	int j = 1;
	struct LNode *q = L;

	while (q && j < i)
	{
		j++;
		q = q->next;
	}

	if (q)
		return(q->data);
	else
		cout << "位置参数不正确!" << endl;
	return 0;
}

int LocateElem(LinkList L, ElemType x) {
	int n = 1;
	struct LNode *q = L;
	while ((q->next)->data != x)//()
	{
		n++;
		q = q->next;
	}
	if (!q)
		return(-1);
	else
		return(n + 1);
}

void InsertList(LinkList &L, ElemType x, int i) {
	int j = 1;//位置计数器

	struct LNode *s, *q;
	s = new LNode;

	s->data = x;
	s->next = null;

	q = L;
	//i为1时，首地址L需要改变
	if (i == 1) {
		//s->next = q;
		//L -> next = s->next;
		L = s;
		cout << "the node is " << x << endl;
	}//否则判断是否位置参数在范围内
	else {
		while (j < i - 1 && (q)) {
			j++;
			q = q->next;
		}
		if (j == i - 1 && q)
		{
			s->next = q->next;
			q->next = s;
			cout << "the node is " << x << endl;
		}
		else
			cout << "位置参数不正确!" << endl;
	}
}

int DeleteElem(LinkList &L, int i) {
	int j = 1;
	struct LNode *q = L, *t;
	t = q;
	if (i == 1) {
		L->next = q->next;
		//q->next = t->next;
	}
	else {
		while (j < i - 1 && q->next) {
			q = q->next;
		}
		if (q->next && j == i - 1) {
			t = q;
			q = q->next;
		}
		else
			cout << "位置参数不正确!" << endl;;
	}
	if (t)
		delete t;
	return 0;
}

void DisplayList(LinkList L) {
	struct LNode *q;
	q = L;
	cout << "链表元素： ";
	if (!q)
		cout << "链表为空" << endl;
	else if (!q->next)
		cout << q->data << ".";
	else
	{
		while (q && q->next)
		{
			cout << q->data << ", ";
			q = q->next;
		}
		cout << q->data << ". ";
	}
	cout << endl;
}
