using namespace std;
#include <iostream>
#include <stdlib.h>
# define null 0

typedef char ElemType; /* �ַ�������*/
typedef struct LNode
{
	ElemType data;
	LNode *next;
}LNode, *LinkList;

void InitList(LinkList &L);
int ListLength(LinkList L);
ElemType GetElem(LinkList L,int i);
void InsertList(LinkList &L,ElemType x,int i);
int DeleteElem(LinkList &L,int i);
void DisplayList(LinkList L);
LinkList LA;

int main(){
	LA = NULL;
	ElemType cs;
	int len=0;
	InitList(LA);
	InsertList(LA, 'a', 1);
	InsertList(LA, 'B', 2);		
	InsertList(LA, 'C', 2);
	cs=GetElem(LA, 3);

	cout << cs << endl;
	cout << ListLength(LA) << endl;
	DisplayList(LA);

	InsertList(LA, 'd', 1);

	cout << ListLength(LA) << endl;
	DisplayList(LA);

	system("pause");
	return 0;
}

void InitList(LinkList &L){
	LNode *s = new LNode;
	s->next = NULL;
	L = s;

	cout << "inti" << endl;
}

int ListLength (LinkList L){
	int n = 1;//counter
	LNode *q = L->next;

	if (!q)
	{
		cout << "empty list" << endl;
	}else
	{
		while (q)
		{
			n++;
			q = q->next;
		}
	}

	return n - 1;
}

ElemType GetElem(LinkList L,int i){
	int j = 1;//counter
	LNode *q = L;

	while (j < i - 1 && q)
	{
		q = q->next;
		j++;
	}

	if (!q)
	{
		cout << "wrong index" <<endl;
	}

	return q->data;
}

int LocateElem(LinkList L,ElemType x){
	int i = 1;//counter
	LNode *q = L;

	while(q->next->data != x)
	{
		i++;
		q = q->next;
	}
	if(!q)
	{
		return -1;
	}else
	{
		return i;
	}


}

void InsertList(LinkList &L,ElemType x,int i){
	int j = 1;//counter
	
	LNode *s = new LNode;
	s->data = x;
	s->next = null;

	LNode *q = L;
	
	while (j < i && q)
	{
		j++;
		q = q->next;
	}

	if (j == i && q)
	{
		s->next = q->next;
		q->next = s;
	}else
	{
		cout << "wrong index" << endl;
	}

	cout << "insert" << endl;

}

void DisplayList(LinkList L){	
	LNode *q = L->next;

	cout << "item: ";

	if (q->data == null)
	{
		cout << "empty" << endl;
	}

	while (q)
	{
		cout << q->data << " ";
		q = q->next;
	}
	

	cout << "." << endl;
}

