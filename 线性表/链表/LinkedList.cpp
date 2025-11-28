//
// Created by C1921 on 2025/9/22.
//

#include "LinkedList.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void InitLinkedList(LinkedList &l){
    l.head = nullptr;
    l.length = 0;
}

void DestroyLinkedList(LinkedList &l){
    ListNode* p;
    while (l.head) {
        p = l.head;
        l.head = l.head->next;
        free(p);
    }
    l.length = 0;
}

int IsLinkedListEmpty(LinkedList &l){
    return l.head==NULL;
}

ElemType GetLinkedListElement(LinkedList &l, int i) {
    if (i<1 || i>l.length) {
        cout << "位置错误" << endl;
    }
    ListNode* p = l.head;
    int j = i;
    while (j--) {
        p = p->next;
    }
    return p->data;
}

int LinkedListLocation(LinkedList &l, ElemType x) {
    ListNode* cur = l.head;
    int pos = 1;
    while (cur) {
        if (cur->data==x) return pos;
        cur = cur->next;
        pos++;
    }
    return 0;
}

int LinkedListPrior(LinkedList &l, ElemType x) {
    ListNode* cur = l.head;
    while (cur->next) {
        if (cur->next->data==x) return cur->data;
        cur = cur->next;
    }
    return 0;
}

int LinkedListNext(LinkedList &l, ElemType x) {
    ListNode* cur = l.head;
    while (cur) {
        if (cur->data==x && cur->next) return cur->next->data;
        cur = cur->next;
    }
    return 0;
}

void InsertLinkedList(LinkedList &l, int i, ElemType x) {
    if (i<1 || i>l.length+1) {
        cout << "插入位置错误" << endl;
        exit(1);
    }
    ListNode* node = new ListNode();
    node->data = x;
    if (i==1) {
        node->next = l.head;
        l.head = node;
    }else {
        ListNode* cur = l.head;
        for (int j=0; j<i-1; j++) {
            cur = cur->next;
        }
        node->next = cur->next;
        cur->next = node;
    }
    l.length++;
}

void DeleteLinkedList(LinkedList &l, int i) {
    if (i<1 || i>l.length) {
        cout << "位置错误" << endl;
        exit(1);
    }
    ListNode* cur = l.head;
    for (int j=1; j<i; j++) {
        cur = cur->next;
    }
    delete(cur);
}

void SortLinkedList(LinkedList &l) {
    if (l.length <= 1) return;

    for (int i = 0; i < l.length - 1; i++) {
        ListNode* p = l.head;
        for (int j = 0; j < l.length - 1 - i; j++) {
            if (p->data > p->next->data) {
                ElemType temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
            }
            p = p->next;
        }
    }
}

void PrintLinkedList(LinkedList &l) {
    ListNode* p = l.head;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}






