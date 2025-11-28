#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef int status;
typedef char ElemType;
typedef struct BinaryTreeNode{
	ElemType data;
	struct BinaryTreeNode *lchild,*rchild;
}BinaryTreeNode,*BinaryTree;


void  CreateBinaryTree(BinaryTree &t);//创建
void  PreOrder(BinaryTree t);//先序
void  InOrder(BinaryTree t);//中序
void  PostOrder(BinaryTree t);//后序
void  levelOrder(BinaryTree t);//层次


int TreeNodeCount(BinaryTree t);//求结点总数
int TreeDepth(BinaryTree t);//求深度
int leafNode(BinaryTree t);//求叶子结点总数




