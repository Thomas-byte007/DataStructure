//
// Created by C1921 on 2025/11/11.
//
//遍历中序线索二叉树

#include "BiThrTree.h"
#include <iostream>

//找到以p为根的子树中，第一个被中序遍历的结点
BiThrTree FirstNode(BiThrTree p){
    while(p->ltag==0)
        p = p->lchild;
    return p;
}

//在中序线索二叉树中找到结点p的后继节点
BiThrTree NextNode(BiThrTree p){
    if(p->rtag==0)
        return FirstNode(p->rchild);
    else
        return p->rchild;
}

//对中序线索二叉树进行中序遍历（利用线索实现的非递归算法）
void Inorder(BiThrTree T){
    for(BiThrTree p=FirstNode(T); p!=nullptr; p=NextNode(p))
        visit(p);
}
