#ifndef _TREE_H
#define _TREE_H

#define MAX_TREE_SIZE 100
#define QUEUE_INIT_SIZE 100

struct BiTNode//二叉树
{
    int data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
};
//typedef BiTNode *BiTree;

typedef struct Queue{
   struct BiTNode *base;
    int front;
    int rear;
    int QueueSize;
}Queue;


void initQueue();
int queueEmpty();
int enqueue();
int outqueue();
int InitBiTree();
int print(int e);
int createBiTree();
int DestoryBiTree();
int BiTreeEmpty();
int LevelOrderTraverse();
struct BiTNode Parent();
struct BiTNode LeftSibling();
struct BiTNode RightSibling();
struct BiTNode LeftChild();
struct BiTNode RightChild();
int Value();
int Assign(int e);
void InsertChild(int LR);
void DeleteChild(int LR);
int PreOrderTraverse_1(struct BiTNode T);
int InOrderTraverse_1();
int PostOrderTraverse_1();




#endif 
