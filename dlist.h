#ifndef __DLIST_H
#define __DLIST_H 

typedef 	int 			ElementType;
struct 		Node_t;
typedef 	struct Node_t*  	PtrToNode;
typedef		PtrToNode		Position;


/*定义节点类型*/  
struct Node_t
{
	ElementType element;	/*数据域*/  
	Position next;			/*指向前驱*/  
	Position previous;		/*指向后继*/  
};
typedef  struct 	Node_t Node;
/*定义链表类型*/  
typedef     struct 	
{
	PtrToNode head;
	PtrToNode tail;
	int size;
}DList;    

/*判断链表是否为空*/
int  isEmpty(DList* l);
/*判断节点p是否为链表最后一个元素*/
int  isLast(Position p);
/*判断节点p是否为链表第一个元素*/
int  isFirst(Position p);
/*为e创建一个节点，并返回节点的地址*/
Position makeNode(ElementType e);
/*释放p所指的节点*/
void freeNode(Position p);
/*创建一个空的双向链表*/
DList* initList(void);
/*销毁一个双向链表*/
void destroyDlist(DList* l);
 /*将一个链表清空,释放原链表节点空间*/
DList* clearDList(DList* l);
/*返回头节点地址*/
Position getHead(DList* l);
/*返回尾节点地址*/
Position getTail(DList* l);
/*返回链表的大小*/
int getSize(DList* l);
/*返回p的直接后继位置*/
Position getNext(Position p);
/*返回P的直接前驱位置*/
Position getPrevious(Position p);
/*将p所指节点插入第一个节点之前*/
PtrToNode insertFisrt(DList* l, PtrToNode p);

/*将链表的第一个元素删除并还会其地址*/
PtrToNode delFirst(DList* p);
/*获得节点的数据项*/
ElementType getElement(Position p);
/*设置节点的数据项并返回其地址*/
Position setElement(Position p, ElementType e);
/*删除链表中的尾节点并返回其地址,并修改链表尾指针*/
PtrToNode removeTail(DList* l);
/*在链表中p位置之前插入新节点S*/
PtrToNode InsertBefore(DList* l,Position p,PtrToNode s);
/*在链表中p位置之后插入新节点s*/ 
PtrToNode InsertAfter(DList* l,Position p,PtrToNode s);
/*返回在链表中第i个节点的位置*/ 
PtrToNode localPos(DList* l,int i);

void traverseDList(DList* l, void (*visit)(void));

#endif
