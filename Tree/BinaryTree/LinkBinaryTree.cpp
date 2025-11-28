//
// Created by C1921 on 2025/11/10.
//

#include "LinkBinaryTree.h"
#include <queue>
#include <iostream>
using namespace std;

typedef int status;
typedef char ElemType;

void CreateBinaryTree(BinaryTree &t){
    char ch;
    cin >> ch;
    if(ch == '#'){
        t = nullptr;
    }else{
        t = new BinaryTreeNode;
        t->data = ch;
        CreateBinaryTree(t->lchild);
        CreateBinaryTree(t->rchild);
    }

}

void  PreOrder(BinaryTree t){
    if (t) {
        if (t) cout << t->data << " ";
        PreOrder(t->lchild);
        PreOrder(t->rchild);
    }
};//先序
void  InOrder(BinaryTree t){
    if (t) {
        InOrder(t->lchild);
        cout << t->data << " ";
        InOrder(t->rchild);
    }

};//中序
void  PostOrder(BinaryTree t){
    if(t){
        PostOrder(t->lchild);
        PostOrder(t->rchild);
        cout << t->data << " ";
    }
};//后序
void  levelOrder(BinaryTree t){
    if(!t) return;
    queue<BinaryTree> q;
    q.push(t);
    while(!q.empty()){
        BinaryTree node = q.front();
        q.pop();
        if(t->lchild) q.push(node->lchild);
        if(t->rchild) q.push(node->rchild);
    }
};//层次


int TreeNodeCount(BinaryTree t){
    if(!t) return 0;
    return 1 + TreeNodeCount(t->lchild) + TreeNodeCount(t->rchild);
};//求结点总数

int TreeDepth(BinaryTree t){
    if(!t) return 0;
    return 1 + max(TreeDepth(t->lchild), TreeDepth(t->rchild));
};//求深度

int leafNode(BinaryTree t){
    if(!t) return 0;
    if(!t->lchild && !t->rchild) return 1;
    return leafNode(t->lchild) + leafNode(t->rchild);
};//求叶子结点总数


