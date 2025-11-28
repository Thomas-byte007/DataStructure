//
// Created by C1921 on 2025/9/14.
//

#ifndef SQLIST_H
#define SQLIST_H

#define LISTINITSIZE 100
#define LISTINCREAMENT 10
typedef int ElemType;
typedef struct{
  ElemType *elem;
  int length;
  int listsize;
}SqList;

void InitSqList(SqList &l);
void DestroySqList(SqList &l);
int IsSqListEmpty(SqList &l);
int IsSqListFull(SqList &l);
ElemType GetSqListElement(SqList &l,int i);
int SqListLocation(SqList &l,ElemType x);
int SqListPrior(SqList &l,ElemType x);
int SqListNext(SqList &l,ElemType x);
void InsertSqList(SqList &l,int i,ElemType x);
void DeleteSqList(SqList &l,int i);
void SortSqList(SqList &l);
void PrintSqList(SqList &l);






#endif //SQLIST_H
