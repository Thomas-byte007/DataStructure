//
// Created by C1921 on 2025/9/22.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


typedef int ElemType;
typedef struct ListNode{
  int data;
  struct ListNode* next;
}ListNode;

typedef struct {
  ListNode* head;
  int length;
}LinkedList;

void InitLinkedList(LinkedList &l);
void DestroyLinkedList(LinkedList &l);
int IsLinkedListEmpty(LinkedList &l);
ElemType GetLinkedListElement(LinkedList &l, int i);
int LinkedListLocation(LinkedList &l, ElemType x);
int LinkedListPrior(LinkedList &l, ElemType x);
int LinkedListNext(LinkedList &l, ElemType x);
void InsertLinkedList(LinkedList &l, int i, ElemType x);
void DeleteLinkedList(LinkedList &l, int i);
void SortLinkedList(LinkedList &l);
void PrintLinkedList(LinkedList &l);



#endif //LINKEDLIST_H
