#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/queue.h"
typedef struct QNode//队列结构
{
    int data;
    struct QNode* next;
}QNode,*Queueptr;
typedef struct
{
    Queueptr front;
    Queueptr rear;
}LinkQueue;
extern LinkQueue Q;

void InitQueue()//队列初始化
{
    Q.front=(Queueptr)malloc(sizeof(QNode));
    Q.rear=Q.front;
    Q.front->data=0;
    Q.front->next=NULL;
    if(!Q.front)
        exit(0);
    Q.front->next=NULL;
}
void DestroyQueue()//销毁队列
{
    while(Q.front)
    {
        Q.rear=Q.front->next;
        free(Q.front);
        Q.front=Q.rear;
    }
}
void ClearQueue()//清除队列元素
{
    Q.rear=Q.front;
}
void QueueEmpty()//判断队列是否为空
{
    if (Q.front==Q.rear)
        printf("队列为空");
    else
        printf("队列不空");
}
void QueueLength()//判断队列的长度
{
    Queueptr a;
    int i;
    i=Q.rear-Q.front->next;
    printf("length=%d",i/2+1);
    return ;
}
void GetHead()//返回队列头元素
{
    int a;
    Queueptr p;
    p=Q.front;
    p=p->next;
    a=p->data;
    printf("%d",a);
}
void EnQueue(int e)//入队列
{
    Queueptr p;
    p=(Queueptr)malloc(sizeof(QNode));
    if(!p)
        exit(0);
    p->data=e;
    p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
}
void DeQueue()//出队列
{
    int e;
    Queueptr p;
    if(Q.front==Q.rear)
    {
        printf("栈为空");
        return;
    }
    p=Q.front->next;
    e=p->data;
    Q.front->next=p->next;
    if(Q.rear==p)
        Q.rear=Q.front;
    free(p);
    return ;
}
void QueueTraverse()//返回队列所有元素
{
    Queueptr p;
    p=Q.front;
    p=p->next;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}



