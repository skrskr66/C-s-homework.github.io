#pragma once
#include<stdlib.h>
#include<assert.h>
typedef int DataType;

typedef struct ListNode{
	DataType data;				//�����ṹ�����������һ�����
	struct ListNode *next;   //ListNode *p = NULL;������
}ListNode;

//��ʼ��/����
void ListInit(ListNode **ppFirst){

	assert(ppFirst != NULL);
	*ppFirst = NULL;
}

void ListDestory(ListNode **ppFirst){
	*ppFirst = NULL;
}
//��װһ����������Ϊ����ʹ��ȥ�����µ�ַ
static ListNode * CreatNode(DataType data){
	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	assert(newNode);
	newNode->data = data;
	newNode->next = NULL;

	return newNode;

}
//��/ɾ/��/�� 
void ListPushFront(ListNode **ppFirst,DataType data){//һ��pһ��ָ�룬����p����ָ��

	assert(ppFirst != NULL);
	//����һ���������������Ϊ�� *ppFirst = NULL
	//�������
	//1.�Ӷ�������ռ�
	ListNode *newNode = CreatNode(data);
	newNode->data = data;
	newNode->next = *ppFirst;

	*ppFirst = newNode;
}
//β�� 
void ListPushBack(ListNode **ppFirst, DataType data){
	ListNode *newNode = CreatNode(data);

	//�����������������Ϊ�յ���� �ҵ�����һ��-> ������һ��
	if (*ppFirst == NULL){
		*ppFirst = newNode;
		return;
	}
	//ͨ�����
	ListNode *cur = *ppFirst;
	while (cur->next != NULL){
		cur = cur->next;
	}
	//cur�������һ�����   cur{data,next}
	cur->next = newNode;
}
//ɾ��//ͷɾ
void ListPopFront(ListNode **ppFirst){

	assert(ppFirst != NULL);//������ַ��ΪNULL
	assert(*ppFirst != NULL);//�����ǿ�����

	ListNode *del = *ppFirst;
	*ppFirst = (*ppFirst)->next;

	free(del);//ָ����һ��֮����Ҫ��ǰһ��Ҳɾ�������ͷŵ�
}
//βɾ
void ListPopBack(ListNode **ppFirst){
	//�������
	assert(ppFirst != NULL);//������ַ��ΪNULL
	assert(*ppFirst != NULL);//�����ǿ�����
	//������ֻ��һ�����
	if ((*ppFirst)->next = NULL){
		free(*ppFirst);
		*ppFirst = NULL;
		return;
	}
	
	//�������
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
	ListInit(&first);//��ֵ��1.first ����ַ��2.&first
	//��ʼ��֮��������һ��������first=NULL
	//first��仯
	ListPushBack(&first, 1);

	//�Ժ�first ������
	ListPushFront(&first, 1);
	ListPushFront(&first, 2);
	ListPushFront(&first, 3);
	ListPushFront(&first, 4);
	ListPushFront(&first, 5);
}