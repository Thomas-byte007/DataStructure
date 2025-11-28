#include <stdio.h>
#include  <stdlib.h>
#define MAX_SIZE 100

typedef struct{
    int vertices[MAX_SIZE];
    int adjMat[MAX_SIZE][MAX_SIZE];
    int size;
}GraphAdjMat;


//构造函数（初始化）
GraphAdjMat *newGraphAdjMat(){
    GraphAdjMat *graph = (GraphAdjMat *)malloc(sizeof(GraphAdjMat));
    graph->size = 0;
    for(int i = 0; i<MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            graph->adjMat[i][j] = 0;
        }
    }
    return graph;
}

//添加顶点
void AddVertex(GraphAdjMat *graph,int val){
    if(graph->size == MAX_SIZE){
        printf("图的顶点数量已达到最大值");
        return;
    }
    //添加第n个顶点，并将第n行和列置零
    int n = graph->size;
    graph->vertices[n] = val;
    for(int i = 0; i<=n; i++){
        graph->adjMat[n][i] = graph->adjMat[i][n] = 0;
    }
    graph->size++;
}

//删除顶点
void removeVertex(GraphAdjMat *graph,int index){
    if(index<0 || index>=graph->size){
        printf("顶点索引越界");
        return;
    }
    //在顶点列表中移除索引为index的顶点
    for(int i = 0; i<graph->size; i++){
        graph->vertices[i] = graph->vertices[i+1];
    }
    //在邻接矩阵中删除索引为index的行
    for(int i = index; i<graph->size; i++){
        for(int j = 0; j<graph->size-1; j++){
            graph->adjMat[i][j] = graph->adjMat[i+1][j];
        }
    }
    //在邻接矩阵中删除索引为index的列
    for(int i=0; i<graph->size; i++){
        for(int j=index; i<graph->size-1; j++){
            graph->adjMat[i][j] = graph->adjMat[i][j+1];
        }
    }
    graph->size--;
}

//添加边
void addEdge(GraphAdjMat *graph,int i,int j){
    if(i<0 || j<0 || i>=graph->size || j>=graph->size || i==j){
        printf("边索引越界或相等");
        return;
    }
    graph->adjMat[i][j] = 1;
    graph->adjMat[j][i] = 1;
    printf("添加成功");
}

//删除边
void removeEdge(GraphAdjMat *graph,int i,int j){
    if(i<0 || j<0 || i>=graph->size || j>=graph->size || i==j){
        printf("边索引越界或相等");
        return;
    }
    graph->adjMat[i][j] = 0;
    graph->adjMat[j][i] = 0;
    printf("删除成功");
}

//打印邻接矩阵
void printGraphAdjMat(GraphAdjMat *graph){
    printf("顶点列表 = ");
    for(int i=0; i<graph->size; i++){
        printf("%d ",graph->vertices[i]);
    }
    printf("\n");
    printf("邻接矩阵 = ");
    for(int i=0; i<graph->size; i++){
        for(int j=0; j<graph->size; j++){
            printf("%d ",graph->adjMat[i][j]);
        }
        printf("\n");
    }
}