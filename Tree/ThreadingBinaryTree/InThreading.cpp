//
// Created by C1921 on 2025/11/11.
//
#include <iostream>

//以结点root为根的子树中序线索化

#include "BiThrTree.h"



void CreateInThread(BiThrTree root){
    pre = nullptr;
    if(root){
        InThreading(root);
        if(!pre->rchild) pre->rtag = 1;
    }
}
void InThreading(BiThrTree root){
    if(root){
        InThreading(root->lchild);
        visit(root);
        InThreading(root->rchild);
    }
}

void visit(BiThrTree root){
    if(!root->lchild){
        root->lchild == pre;
        root->ltag = 1;
    }

    if(pre && !pre->rchild){
        pre->rchild = root;
        pre->rtag = 1;
    }

    pre = root;
}