//
// Created by C1921 on 2025/11/11.
//

#ifndef DATASTRUCTURE_BITHRTREE_H
#define DATASTRUCTURE_BITHRTREE_H

typedef char TElemType;
typedef struct BiThrNode{
    TElemType data;
    struct BiThrNode *lchild,*rchild;
    int ltag,rtag;
}BiThrNode,*BiThrTree;

BiThrNode* pre;

void CreateInThread(BiThrTree root);
void InThreading(BiThrTree root);
void visit(BiThrTree root);


#endif //DATASTRUCTURE_BITHRTREE_H
