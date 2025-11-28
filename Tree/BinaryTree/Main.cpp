//
// Created by C1921 on 2025/11/10.
//
#include "LinkBinaryTree.h"
int main(){
    BinaryTree root = nullptr;
    cout << "请输入前序序列（用#表示空）：" << endl;
    CreateBinaryTree(root);

    cout << "先序遍历："; PreOrder(root); cout << endl;
    cout << "中序遍历："; InOrder(root); cout << endl;
    cout << "后序遍历："; PostOrder(root); cout << endl;
    cout << "层次遍历："; levelOrder(root); cout << endl;

    cout << "结点总数：" << TreeNodeCount(root) << endl;
    cout << "树的深度：" << TreeDepth(root) << endl;
    cout << "叶子结点数：" << leafNode(root) << endl;

    return 0;
}