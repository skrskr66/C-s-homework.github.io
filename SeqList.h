#pragma once
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
//#include "StdAfx.h"
//数据结构是抽象类型
//数据本身不仅仅是数字
#define MAX_SIZE (100)

typedef int DataType;//为现有类型创建别名，并且用DataType来代替int，例如DataType num = 1；即为int = 1；

typedef struct SeqList   //结构体名
{
	DataType array[MAX_SIZE];//类型说明符号 成员名；//成员列表
	int size;    //1.保存顺序表里已经存了的数据个数
				 //2.size = 5;array[5].当前可用下标
}SeqList;		//变量名；这里前往要注意啊！！！

//接口（函数） 围绕顺序表相关的操作
//初始化/销毁
//增/删/查/改

//初始化(函数设计)

void SeqListInit(SeqList *pSeq)
{
	//初始化 size
	//可能需要去吧容器空间清空下
	
	assert(pSeq != NULL);
	pSeq->size = 0;
	memset(pSeq->array, 0, MAX_SIZE * sizeof(DataType));
}
//销毁
void SeqListDestroy(SeqList *pSeq)
{
	assert(pSeq);
	pSeq->size = 0;
}

//增
//尾插
void SeqListPushBack(SeqList *pSeq,DataType data)
{
	assert(pSeq);
	//特殊情况（满了）
	if (pSeq->size >= MAX_SIZE){
		printf("满了\n");
		assert(0);
		return;
	}
	pSeq->array[pSeq->size] = data;
	pSeq->size++;
}
//头插
//循环的边界 1.从后往前般，否则会覆盖 2.循环的区间 将所有位置的数值进行后移 位置:[size,0)for(i=size;i>0;i--)
												  //数据：先搬后再搬前[size-1,0] for(i=size-1;i>=0;i++)
												 //
void SeqListPushTop(SeqList *pSeq, DataType data){
	assert(pSeq);
	//特殊情况（满了）
	if (pSeq->size >= MAX_SIZE){
		printf("满了\n");
		assert(0);
		return;
	}
	//i代表位置
	for (int i = pSeq->size; i > 0; i--){
		pSeq->array[i] = pSeq->array[i - 1];
	}
	////i代表数据
	//for (int i = size - 1; i >= 0; i++){
	//	pSeq->array[i + 1] = pSeq->array[i];
	//}

	//插入
	pSeq->array[0] = data;
	pSeq->size++;
}
//中间插入
//根据下标来做加入。pos的取值范围[0,size]
void SeqListInsert(SeqList *pSeq, int pos, DataType data){
	
	
	assert(pSeq);
	//特殊情况（满了）
	assert(pos >= 0 && pos <= pSeq->size);
	if (pSeq->size >= MAX_SIZE){
		printf("满了\n");
		assert(0);
		return;
	}
	//1.数据搬移                                //知其然知其所以然
	for (int i = pSeq->size; i >= pos; i--){
		pSeq->array[i] = pSeq->array[i-1];
	}
	////i取数据[size-1,pos]
	//for (int i = pSeq->size - 1; i >= pos; i--){
	//	pSeq->array[i] = pSeq->array[i + 1];
	//}

	//2.插入
	pSeq->array[pos] = data;
	pSeq->size++;

}

//头删           
// i 位置/数据 位置为[0,size-1)或者[0,size-2]  数据的搬运为[1,size-1)或者[1,size)
// 判断循环边界，循环的次数
void SeqlistPushFont(SeqList *pSeq){
	assert(pSeq);
	if (pSeq->size < 0){
		printf("空了\n");
		assert(0);
		return;
	}
	for (int i = 0; i < pSeq->size - 1; i++){
		//前位置后数据
		pSeq->array[i] = pSeq->array[i + 1];
	}
	pSeq->size--;
}
//尾删

void SeqListPushPop(SeqList *pSeq)
{
	assert(pSeq);
	if (pSeq->size < 0){
		printf("空了\n");
		assert(0);
		return;
	}
	pSeq->size--;
}
//中间删                       //pos的取值范围[0,size)
void SeqListErase(SeqList *pSeq, int pos){
	
	assert(pSeq);
	assert(pos >= 0 && pos < pSeq->size);
	if (pSeq->size < 0){
		printf("空了\n");
		assert(0);
		return;
	}
	//数据搬移，从前往后般  i取位置
	for (int i = pos; i <= pSeq->size - 2/*i<pSeq->size-1*/; i++){
		pSeq->array[i] = pSeq->array[i + 1];
	}

	pSeq->size--;

}

//传指针是为了减少空间，不改变值
void SeqListPrint(const SeqList *pSeq){
	assert(pSeq != NULL);
	for (int i = 0; i < pSeq->size; i++){
		printf("%d", pSeq->array[i]);
	}
	printf("\n");
}
void Swap(DataType *a, DataType *b){
	DataType t = *a;
	*a = *b;
	*b = t;
}
void SeqListBubbleSort(SeqList *pSeq){
	int i, j;
	int isSorted;
	for (i = 0; i < pSeq->size - 1; i++){
		isSorted = 1;
		//1为真，0为假
		for (j = 0; j < pSeq->size - 1 - i; j++){
			if (pSeq->array[i] > pSeq->array[j + i]){
				Swap(pSeq->array + i, pSeq->array + j + 1);

			}
						isSorted = 0;
		}

		if (isSorted){
			break;
		}
	}
}
//使用场景
void Test()
{
	//1.
	SeqList seqList;
	SeqListInit(&seqList);

	//2.
	//SeqList *pSeqList;
	//pSeqList = SeqListInit();



	SeqListPushTop(&seqList, 1);
	SeqListPushTop(&seqList, 2);
	SeqListPushTop(&seqList, 3);
	SeqListPushTop(&seqList, 4);

	
	SeqListPrint(&seqList);
	SeqListBubbleSort(&seqList);
	SeqListPrint(&seqList);
}

//查找     找到第一个遇到的数的下标，没找到返回 -1（更理想的返回类型ssize_t）
//size_t无符号类型

int SeqListFind(SeqList *pSeq, DataType data)
{
	//二分查找（前提是有序）
	//顺序遍历查找
	for (int i = 0; i < pSeq->size; i++){
		if (data = pSeq->array[i]){
			return 1;
		}
		return -1;
	}
}

//删除第二种形态（接口） 根据数据删除
//1.删除第一个遇到的形式
void SeqListRemove(SeqList *pSeq, DataType data)
{
	int pos = SeqListFind(pSeq, data);  //Erase pos=1
	if (pos == -1){
		//找到删除           
		return;
	}	
	SeqListErase(pSeq, pos);
}
//2.删除遇到的所有数据
void SeqListRemoveALL(SeqList *pSeq, DataType data)
{
	//第一种方式
	//慢
	//while ((pos = SeqListFind(pSeq, data)) != -1){
	//	SeqListErase(pSeq, pos);
	//}
#if 0
	//第二种方式
	//好处：一次遍历删除，时间快，坏处：开辟了新空间，空间大小和size有关系
	//开辟一个新的空间，遍历原来的数组，
	//if array[i] != data, 
	//	new[j++] = array[i++]
	//else:
	//	i++
	//把数据在搬回来
	//还剩的数据个数j个
	DataType *newArray = (DataType *)malloc(sizeof(DataType)*pSeq->size);
	int  i, j;
	for (i = 0, j = 0; i < pSeq->size; i++){
		if (data != pSeq->array[i]){
			newArray[j] = pSeq->array[i];
			j++;
		}
	}

	for (i = 0; i < j; i++){
		pSeq->array[i] = newArray[i];
	}
	pSeq->size = j;
	free(newArray);
#endif
	//第三种方式
	int  i, j;
	for (i = 0, j = 0; i < pSeq->size; i++){
		if (data != pSeq->array[i]){
			pSeq->array[j] = pSeq->array[i];
			j++;
		}
	}
	pSeq->size = j;
}

int SeqListSize(SeqList *pSeq){
	return pSeq->size;
}

int SeqListFull(SeqList *pSeq){
	return pSeq->size == MAX_SIZE;
}

int SeqListEmpty(SeqList *pSeq){
	return pSeq->size == 0;
}

//void Swap(DataType *a,DataType *b){
//	DataType t = *a;
//	*a = *b;
//	*b = t;
//}

//不属于顺序表的接口
//1.冒泡排序
//void SeqListBubbleSort(SeqList *pSeq){
//	int i, j;
//	int isSorted;
//	for (i = 0; i < pSeq->size - 1; i++){
//		isSorted = 1;
//		//1为真，0为假
//		for (j = 0; j < pSeq->size - 1 - i; j++){
//			if (pSeq->array[j] > pSeq->array[j + i]){
//				Swap(pSeq->array + j, pSeq->array + j + 1);
//			}
//
//			isSorted = 0;
//		}
//
//		if (isSorted){
//			break;
//		}
//	}
//}
//有一个选择排序自己思考