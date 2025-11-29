#include "malloc.h"
#define MAX_SIZE 100

//节点队列结构体
typedef struct {
    int *data[MAX_SIZE];
    int front,rear,size;
}Queue;

//构造函数
Queue *newQueue(){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = q->size = 0;
    return q;
}

//判断队列是否为空
bool isEmpty(Queue *q){
    return q->size==0;
}

//入队操作
void enQueue(Queue *q,int *point){
    q->data[q->rear] = point;
    q->rear = (q->rear+1) % MAX_SIZE;
    q->size++;
}

//出队操作
int *deQueue(Queue *q){
    int *point = q->data[q->front];
    q->front = (q->front+1) % MAX_SIZE;
    q->size--;
    return point;
}