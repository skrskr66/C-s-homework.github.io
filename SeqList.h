#pragma once
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
//#include "StdAfx.h"
//���ݽṹ�ǳ�������
//���ݱ�������������
#define MAX_SIZE (100)

typedef int DataType;//Ϊ�������ʹ���������������DataType������int������DataType num = 1����Ϊint = 1��

typedef struct SeqList   //�ṹ����
{
	DataType array[MAX_SIZE];//����˵������ ��Ա����//��Ա�б�
	int size;    //1.����˳������Ѿ����˵����ݸ���
				 //2.size = 5;array[5].��ǰ�����±�
}SeqList;		//������������ǰ��Ҫע�Ⱑ������

//�ӿڣ������� Χ��˳�����صĲ���
//��ʼ��/����
//��/ɾ/��/��

//��ʼ��(�������)

void SeqListInit(SeqList *pSeq)
{
	//��ʼ�� size
	//������Ҫȥ�������ռ������
	
	assert(pSeq != NULL);
	pSeq->size = 0;
	memset(pSeq->array, 0, MAX_SIZE * sizeof(DataType));
}
//����
void SeqListDestroy(SeqList *pSeq)
{
	assert(pSeq);
	pSeq->size = 0;
}

//��
//β��
void SeqListPushBack(SeqList *pSeq,DataType data)
{
	assert(pSeq);
	//������������ˣ�
	if (pSeq->size >= MAX_SIZE){
		printf("����\n");
		assert(0);
		return;
	}
	pSeq->array[pSeq->size] = data;
	pSeq->size++;
}
//ͷ��
//ѭ���ı߽� 1.�Ӻ���ǰ�㣬����Ḳ�� 2.ѭ�������� ������λ�õ���ֵ���к��� λ��:[size,0)for(i=size;i>0;i--)
												  //���ݣ��Ȱ���ٰ�ǰ[size-1,0] for(i=size-1;i>=0;i++)
												 //
void SeqListPushTop(SeqList *pSeq, DataType data){
	assert(pSeq);
	//������������ˣ�
	if (pSeq->size >= MAX_SIZE){
		printf("����\n");
		assert(0);
		return;
	}
	//i����λ��
	for (int i = pSeq->size; i > 0; i--){
		pSeq->array[i] = pSeq->array[i - 1];
	}
	////i��������
	//for (int i = size - 1; i >= 0; i++){
	//	pSeq->array[i + 1] = pSeq->array[i];
	//}

	//����
	pSeq->array[0] = data;
	pSeq->size++;
}
//�м����
//�����±��������롣pos��ȡֵ��Χ[0,size]
void SeqListInsert(SeqList *pSeq, int pos, DataType data){
	
	
	assert(pSeq);
	//������������ˣ�
	assert(pos >= 0 && pos <= pSeq->size);
	if (pSeq->size >= MAX_SIZE){
		printf("����\n");
		assert(0);
		return;
	}
	//1.���ݰ���                                //֪��Ȼ֪������Ȼ
	for (int i = pSeq->size; i >= pos; i--){
		pSeq->array[i] = pSeq->array[i-1];
	}
	////iȡ����[size-1,pos]
	//for (int i = pSeq->size - 1; i >= pos; i--){
	//	pSeq->array[i] = pSeq->array[i + 1];
	//}

	//2.����
	pSeq->array[pos] = data;
	pSeq->size++;

}

//ͷɾ           
// i λ��/���� λ��Ϊ[0,size-1)����[0,size-2]  ���ݵİ���Ϊ[1,size-1)����[1,size)
// �ж�ѭ���߽磬ѭ���Ĵ���
void SeqlistPushFont(SeqList *pSeq){
	assert(pSeq);
	if (pSeq->size < 0){
		printf("����\n");
		assert(0);
		return;
	}
	for (int i = 0; i < pSeq->size - 1; i++){
		//ǰλ�ú�����
		pSeq->array[i] = pSeq->array[i + 1];
	}
	pSeq->size--;
}
//βɾ

void SeqListPushPop(SeqList *pSeq)
{
	assert(pSeq);
	if (pSeq->size < 0){
		printf("����\n");
		assert(0);
		return;
	}
	pSeq->size--;
}
//�м�ɾ                       //pos��ȡֵ��Χ[0,size)
void SeqListErase(SeqList *pSeq, int pos){
	
	assert(pSeq);
	assert(pos >= 0 && pos < pSeq->size);
	if (pSeq->size < 0){
		printf("����\n");
		assert(0);
		return;
	}
	//���ݰ��ƣ���ǰ�����  iȡλ��
	for (int i = pos; i <= pSeq->size - 2/*i<pSeq->size-1*/; i++){
		pSeq->array[i] = pSeq->array[i + 1];
	}

	pSeq->size--;

}

//��ָ����Ϊ�˼��ٿռ䣬���ı�ֵ
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
		//1Ϊ�棬0Ϊ��
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
//ʹ�ó���
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

//����     �ҵ���һ�������������±꣬û�ҵ����� -1��������ķ�������ssize_t��
//size_t�޷�������

int SeqListFind(SeqList *pSeq, DataType data)
{
	//���ֲ��ң�ǰ��������
	//˳���������
	for (int i = 0; i < pSeq->size; i++){
		if (data = pSeq->array[i]){
			return 1;
		}
		return -1;
	}
}

//ɾ���ڶ�����̬���ӿڣ� ��������ɾ��
//1.ɾ����һ����������ʽ
void SeqListRemove(SeqList *pSeq, DataType data)
{
	int pos = SeqListFind(pSeq, data);  //Erase pos=1
	if (pos == -1){
		//�ҵ�ɾ��           
		return;
	}	
	SeqListErase(pSeq, pos);
}
//2.ɾ����������������
void SeqListRemoveALL(SeqList *pSeq, DataType data)
{
	//��һ�ַ�ʽ
	//��
	//while ((pos = SeqListFind(pSeq, data)) != -1){
	//	SeqListErase(pSeq, pos);
	//}
#if 0
	//�ڶ��ַ�ʽ
	//�ô���һ�α���ɾ����ʱ��죬�������������¿ռ䣬�ռ��С��size�й�ϵ
	//����һ���µĿռ䣬����ԭ�������飬
	//if array[i] != data, 
	//	new[j++] = array[i++]
	//else:
	//	i++
	//�������ڰ����
	//��ʣ�����ݸ���j��
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
	//�����ַ�ʽ
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

//������˳���Ľӿ�
//1.ð������
//void SeqListBubbleSort(SeqList *pSeq){
//	int i, j;
//	int isSorted;
//	for (i = 0; i < pSeq->size - 1; i++){
//		isSorted = 1;
//		//1Ϊ�棬0Ϊ��
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
//��һ��ѡ�������Լ�˼��