#pragma once
#include<stdlib.h>
#include<assert.h>
typedef int DataType;

typedef struct ListNode{
	DataType data;				//整个结构体仅仅定义了一个结点
	struct ListNode *next;   //ListNode *p = NULL;空链表
}ListNode;

//初始化/销毁
void ListInit(ListNode **ppFirst){

	assert(ppFirst != NULL);
	*ppFirst = NULL;
}

void ListDestory(ListNode **ppFirst){
	*ppFirst = NULL;
}
//封装一个函数，因为总是使用去开辟新地址
static ListNode * CreatNode(DataType data){
	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	assert(newNode);
	newNode->data = data;
	newNode->next = NULL;

	return newNode;

}
//增/删/查/改 
void ListPushFront(ListNode **ppFirst,DataType data){//一个p一级指针，两个p二级指针

	assert(ppFirst != NULL);
	//考虑一下特殊情况，链表为空 *ppFirst = NULL
	//正常情况
	//1.从堆上申请空间
	ListNode *newNode = CreatNode(data);
	newNode->data = data;
	newNode->next = *ppFirst;

	*ppFirst = newNode;
}
//尾插 
void ListPushBack(ListNode **ppFirst, DataType data){
	ListNode *newNode = CreatNode(data);

	//特殊情况，处理链表为空的情况 找倒数第一个-> 至少有一个
	if (*ppFirst == NULL){
		*ppFirst = newNode;
		return;
	}
	//通常情况
	ListNode *cur = *ppFirst;
	while (cur->next != NULL){
		cur = cur->next;
	}
	//cur就是最后一个结点   cur{data,next}
	cur->next = newNode;
}
//删除//头删
void ListPopFront(ListNode **ppFirst){

	assert(ppFirst != NULL);//变量地址不为NULL
	assert(*ppFirst != NULL);//不能是空链表

	ListNode *del = *ppFirst;
	*ppFirst = (*ppFirst)->next;

	free(del);//指向下一个之后，需要将前一个也删除，即释放掉
}
//尾删
void ListPopBack(ListNode **ppFirst){
	//特殊情况
	assert(ppFirst != NULL);//变量地址不为NULL
	assert(*ppFirst != NULL);//不能是空链表
	//链表中只有一个结点
	if ((*ppFirst)->next = NULL){
		free(*ppFirst);
		*ppFirst = NULL;
		return;
	}
	
	//正常情况
	ListNode *del;
	ListNode *cur = *ppFirst;

	while (cur->next->next != NULL){
		cur = cur->next;
	}
	del = cur->next;
	cur->next = NULL;
	free(del);
}

void Tset(){
	ListNode *first;
	ListInit(&first);//传值：1.first 传地址：2.&first
	//初始化之后链表是一条空链表，first=NULL
	//first会变化
	ListPushBack(&first, 1);

	//以后first 不变了
	ListPushFront(&first, 1);
	ListPushFront(&first, 2);
	ListPushFront(&first, 3);
	ListPushFront(&first, 4);
	ListPushFront(&first, 5);
}