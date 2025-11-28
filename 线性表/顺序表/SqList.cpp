//
// Created by C1921 on 2025/9/14.
//

#include "SqList.h"
#include <iostream>
using namespace std;

void InitSqList(SqList &l) {
  l.elem = new ElemType[LISTINITSIZE];
  l.listsize = LISTINITSIZE;
  l.length = 0;
}

void DestroySqList(SqList &l) {
  if (l.elem!=nullptr) {
    delete[] l.elem;
    l.elem = nullptr;
  }
  l.length = 0;
  l.listsize = 0;
}

int IsSqListEmpty(SqList &l) {
  return l.length==0 ? 1 : 0;
}

int IsSqListFull(SqList &l) {
  return l.length==l.listsize ? 1 : 0;
}

ElemType GetSqListElement(SqList &l, int i) {
  if (i < 1 || i > l.length) return 0;
  return l.elem[i-1];
}

int SqListLocation(SqList &l, ElemType x) {
  for (int j=0; j<l.length; j++) {
    if (l.elem[j]==x) return j+1;
  }
  return 0;
}

int SqListPrior(SqList &l, ElemType x) {
  for (int j=1; j<l.length; j++) {
    if (l.elem[j]==x) return l.elem[j-1];
  }
  return 0;
}

int SqListNext(SqList &l, ElemType x) {
  for (int j=0; j<l.length-1; j++) {
    if (l.elem[j]==x) return l.elem[j+1];
  }
  return 0;
}

void InsertSqList(SqList &l,int i,ElemType x) {
  if (l.length >= l.listsize) return;
  if (i<1 || i>l.length+1) return;
  for (int j=l.length; j>i-1; j--) {
    l.elem[j] = l.elem[j-1];
  }
  l.elem[i-1] = x;
  l.length++;
}

void DeleteSqList(SqList &l,int i) {
  if (i<1 || i>l.length) return;
  for (int j=i-1; j<l.length-1; j++) {
    l.elem[j] = l.elem[j+1];
  }
}

void SortSqList(SqList &l) {
  for (int i=0; i<l.length-1; i++) {
    bool flag = false;
    for (int j=0; j<l.length-1-i; j++) {
      if (l.elem[j]>l.elem[j+1]) {
        int temp = l.elem[j];
        l.elem[j] = l.elem[j+1];
        l.elem[j+1] = temp;
        flag = true;
      }
    }
    if (!flag) break;
  }
}

void PrintSqList(SqList &l) {
  for (int i = 0; i < l.length; i++) {
    cout << l.elem[i] << " ";
  }
  cout << endl;
}



int main(){
  SqList l;
  PrintSqList(l);
  return 0;
}
