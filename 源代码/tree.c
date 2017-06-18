#include <stdio.h>
#include <stdlib.h>
#include "include/tree.h"
#define MAX_TREE_SIZE 100
#define QUEUE_INIT_SIZE 100


struct BiTNode//二叉树
{
    int data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
};
//typedef BiTNode* BiTree;
typedef struct Queue{
    struct BiTNode *base;
    int front;
    int rear;
    int QueueSize;
}Queue;

extern Queue L;
extern struct BiTree T,q,c;

int initQueue()//初始化队列
{
    (*Q).base=(BiTree *)malloc(QUEUE_INIT_SIZE*sizeof(BiTree));
    if(!(*Q).base)   {exit(-1);}
    (*Q).front=0;
    (*Q).rear=0;
    (*Q).QueueSize=QUEUE_INIT_SIZE;
    return 1;
}

int queueEmpty()//检验是否队列空，空返回1
{
    if((*Q).rear%(*Q).QueueSize==(*Q).front)
        return 1;
    else
        return 0;
}

int enqueue(BiTree *p)//进队列
{
    (*Q).base[(*Q).rear]=*p;
    (*Q).rear=((*Q).rear+1)%(*Q).QueueSize;
    return 1;
}

int outqueue(struct BiTree *p)//出队列
{
    if(QueueEmpty(Q)==0)
    {
        *p=(*Q).base[(*Q).front];
        (*Q).front++;
        return 1;
    }
    else
    {
        return 0;
    }
}

void InitBiTree()
{
    (*T)=(BiTNode *)malloc(sizeof(BiTNode));
    (*T)->data=0;
    (*T)->lchild=NULL;
    (*T)->rchild=NULL;
}

int print(int e)//打印函数
{
    printf("%d ",e);
    return 1;
}

int createBiTree()//创建一个二叉树（先序递归）输入-1表示NULL
{
    int ch;
    scanf("%d",&ch);
    if(ch==-1)  (*T)=NULL;
    else
    {
        if(!((*T)=(BiTNode *)malloc(sizeof(BiTNode))))   exit(-1);
        (*T)->data=ch;
        createBiTree(&((*T)->lchild));
        createBiTree(&((*T)->rchild));
    }
    
    return 1;
}


int DestoryBiTree()
{
    if(T)  {free(T);printf("Destroy success!\n");return 1;}
    else   {printf("Destroy fail!\n");return 0;}
}

int BiTreeEmpty()//检验树空
{
    if(*T==NULL)
        return 1;
    else
        return 0;
}

int LevelOrderTraverse()//层序遍历
{
    BiTNode *p;
    Queue Q;initQueue();
    p=*T;
    if(p)   {enqueue();}
    else    {return 0;}
    while(!queueEmpty())
    {
        outqueue();
        printf("%d ",p->data);
        if(p->lchild)  {enqueue(&(p->lchild));}
        if(p->rchild)  {enqueue(&(p->rchild));}
    }
    return 1;
}

BiTree Parent()//返回q的父节点
{
    if(*q==*T)  return NULL;
    BiTNode *p;
    Queue Q;initQueue();
    p=*T;
    if(p)   {enqueue(&p);}
    else    {return 0;}
    while(!queueEmpty())
    {
        outqueue(&p);
        if(p->lchild)
        {
            if(p->lchild==*q)  {return  p;}
            enqueue(&(p->lchild));
        }
        if(p->rchild)
        {
            if(p->rchild==*q)  {return  p;}
            enqueue(&(p->rchild));
        }
    }
}

BiTree LeftSibling()//返回q的左兄弟
{
    BiTNode* p=Parent(q);
    if(*q==p->lchild)  return NULL;
    else    return (p->lchild);
}

BiTree RightSibling()//返回q的右兄弟
{
    BiTNode* p=Parent(q);
    if(*q==p->rchild)  return NULL;
    else    return (p->rchild);
}

BiTree LeftChild(BiTree *p)//返回q的左儿子
{
    return ((*p)->lchild);
}

BiTree RightChild(BiTree *p)//返回q的右儿子
{
    return ((*p)->rchild);
}

int Value(BiTree p)//返回p的值
{
    int a;
    if(p)   {a=(p)->data;return (p)->data;}
    else return -1;
}

int Assign(BiTree *p,int e)//给p赋值e
{
    (*p)->data=e;
    return 1;
}

void InsertChild(int LR)//根据LR的值将c插入到p的左右结点中，p原本的左右结点为c的右儿子
{
    BiTree q;
    if(LR==0)
    {
        q=(*p)->lchild;
        (*p)->lchild=c;
        c->rchild=q;
    }
    else
    {
        q=(*p)->rchild;
        (*p)->rchild=c;
        c->rchild=q;
    }
}

void DeleteChild(int LR)//根据LR的值选择删除p的左或右结点
{
    if(LR==0)
    {
        (*p)->lchild=NULL;
    }
    else
    {
        (*p)->rchild=NULL;
    }
}

void PreOrderTraverse_1(BiTree T)//先序递归
{
    if(T)
    {
        printf("%d",T->data);
        PreOrderTraverse_1(T->lchild);
        PreOrderTraverse_1(T->rchild);  

    }
}

int InOrderTraverse_1(BiTree T,int(* visit)(int e))//中序递归
{
    if(T)
    {
        if(InOrderTraverse_1(T->lchild,visit))
            if(visit(T->data))
                 if(InOrderTraverse_1(T->rchild,visit))  return 1;
        return 0;
    }else   return 1;
}

int PostOrderTraverse_1(BiTree T,int(* visit)(int e))//后序递归
{
    if(T)
    {
        if(PostOrderTraverse_1(T->lchild,visit))
            if(PostOrderTraverse_1(T->rchild,visit))
                if(visit(T->data)) return 1;
        return 0;
    }else   return 1;
}
}
