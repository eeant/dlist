#include "dlist.h"
#include <stdio.h>
#include <stdlib.h>
/* 
int  isEmpty(DList* l)
参数 
l 要判断的链表
返回值 
1 链表为空
0 链表非空
功能 
判断链表是否为空 
*/
int  isEmpty(DList* l)
{
	return getSize(l)==0;
}
/* 
int  isLast(Position p)
参数 
p 要判断的位置
返回值 
1 p为最后一个元素
0 p不是最后一个元素
功能 
判断p是否为最后一个元素
*/
int  isLast(Position p)
{
	return p->next == NULL;
}
/* 
int  isFirst(Position p)
参数 
p 要判断的位置
返回值 
1 p为第一个元素
0 p不是第一个元素
功能 
判断p是否为第一个元素
*/
int  isFirst(Position p)
{
	return p->previous == NULL;
}
/* 
Position makeNode(ElementType e)
参数 
e 带创建节点的元素
返回值 
! NULL成功创建节点的地址
NULL  失败
功能 
为元素e创建一个节点，并返回其地址
*/
Position makeNode(ElementType e)
{
	PtrToNode p = NULL;
	p = (PtrToNode)malloc(sizeof(Node));
	if (p!=NULL)
	{
		p->element = e;
		p->next = NULL;
		p->previous = NULL;
	}
	return p;
}
/* 
void freeNode(Position p)
参数 
p 待释放的节点位置
返回值 
无
功能 
释放节点p所指的位置
*/
void freeNode(Position p)
{
	free(p);
}

/* 
DList* initList(void)
参数 
无
返回值 
创建空的双向链表的指针
功能 
创建一个空的双向链表
*/
DList* initList(void)
{
	DList *list = (DList *)malloc(sizeof(DList));
	if (list != NULL)
	{
		list->head = NULL;
		list->tail = NULL;
		list->size = 0;
	}

	return list;
}

/* 
void destroyDlist(DList* l)
参数 
待销毁的链表
返回值 
无
功能 
销毁一个双向链表
*/
void destroyDlist(DList* l)
{
	clearDList(l);
	free(l);
}


 /* 
DList* clearDList(DList* l)
参数 
待销毁的链表
返回值 
无
功能 
将一个链表清空,释放原链表节点空间
*/
DList* clearDList(DList* l)
{
	PtrToNode p,tmp;
	p = l->head;
	while(p != NULL)
	{
		tmp = p->next;
		tmp->previous = NULL;
		l->head = tmp;
		l->size--;
		freeNode(p);
		p = tmp;
	}
}

/* 
Position getHead(DList* l)
参数 
链表指针
无
功能 
返回头节点地址
*/
Position getHead(DList* l)
{
	return l->head;
}

/* 
Position getTail(DList* l)
参数 
链表指针
返回值 
尾节点地址
功能 
返回尾节点地址
*/
Position getTail(DList* l)
{
	return l->tail;
}
/*/
/* 
int getSize(DList* l)
参数
链表指针 
返回值 
尾节点地址
功能 
*返回链表的大小
*/
int getSize(DList* l)
{
	return l->size;
}
/* 
Position getNext(Position p)
参数
链表指针 
返回值 
p的直接后继位置
功能 
返回p的直接后继位置
*/
Position getNext(Position p)
{
	return p->next;
}
/* 
Position getPrevious(Position p)
参数
链表指针 
返回值 
p的直接前驱位置
功能 
返回p的直接前驱位置
*/
Position getPrevious(Position p)
{
	return p->previous;
}
/*将p所指节点插入第一个节点之前*/
PtrToNode insertFisrt(DList* l, PtrToNode p)
{
	Position head;
	head = getHead(l);

	if (!isEmpty(l))
	{
		l->head = p;
		l->size++;
		p->previous = NULL;
		p->next = head;
		head->previous = p;
	}
	else
	{
		l->head = l->tail = p;
		l->size = 1;
		p->previous = p->next = NULL;
	}
	
	return p;
}
/*将链表的第一个元素删除并还会其地址*/
PtrToNode delFirst(DList* l)
{
	PtrToNode node;

	node = NULL;
	if (!isEmpty(l))
	{
		node = l->head;
		l->head = node->next;
		if (l->head == NULL)
		{
			l->tail = NULL;
		}
		l->size--;
	}
	return node;
}
/*获得节点的数据项*/
ElementType getElement(Position p)
{
	return p->element;
}
/*设置节点的数据项并返回其地址*/
Position setElement(Position p, ElementType e)
{
	p->element = e;
	return p;
}
/*删除链表中的尾节点并返回其地址,并修改链表尾指针*/
PtrToNode removeTail(DList* l)
{
	PtrToNode node;

	node = NULL;
	if (!isEmpty(l))
	{
		node = l->tail;
		l->tail = node->previous;
		if (l->tail == NULL)
		{
			l->head = NULL;
		}
		l->size--;
	}
	return node;
}
/*在链表中p位置之前插入新节点S*/
PtrToNode InsertBefore(DList* l,Position p,PtrToNode s)
{
	Position tmp;
	tmp = p->previous;

	if (!isFirst(p))
		tmp->next = s;
	else
		l->head = s;

	s->previous = tmp;
	s->next = p;
	p->previous = s;

	l->size++;
	return s;
}
/*在链表中p位置之后插入新节点s*/ 
PtrToNode InsertAfter(DList* l,Position p,PtrToNode s)
{
	Position tmp;
	tmp = p->next;
	if (!isLast(p))
		tmp->previous = s;
	else
		l->tail = s;

	p->next = s;
	s->previous = p;
	s->next = tmp;
}
/*返回在链表中第i个节点的位置*/ 
PtrToNode localPos(DList* l,int i)
{
	int cnt;
	Position p;
	
	p = NULL;
	if (i>0 && i<getSize(l))
	{
		cnt = 0;
		p = getHead(l);

		while(++cnt <= i)
		{
			p = p->next;
		}
	}
	
	return p;
}

void traverseDList(DList* l, void (*visit)())
{

}
