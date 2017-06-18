#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/stack.h"
#include "include/queue.h"
//#include "include/tree.h"
#include "include/graph.h"
#define STACK_INIT_size 100
#define stackincreament 10
#define M 100
#define link 0
#define thread 1
#define N 20
#define X 100
typedef struct sq//栈的结构
{
    int *base;
    int *top;
    int stacksize;
}SqStack;
SqStack S;

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

LinkQueue Q;

/*struct BiTNode//二叉树
{
    int data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
};
//typedef BiTNode* BiTree;
typedef struct
{
    struct BiTNode *base;
    int front;
    int rear;
    int QueueSize;
}Queue;
Queue L;
struct BiTNode T;
struct BiTNode *q,*c;*/

int P[22];
int D[22],finall[22];
typedef struct//图的结构
{
    int arcs[22][22];
    int vnum,anum;
    int kind;//kind=0表示有向图，kind=1表示无向图
}MGraph;
MGraph G;

void stacktest()//栈的测试
{
    int i,j;
    //SqStack S;
    InitStack();
    printf("将0到9依次存入栈中：");
    for (i=0;i<10;i++)
    {
        Push(i);
    }
 
    StackTraverse();

    printf("读取栈顶元素（不删除）：");
    j=GetTop();
    printf("%d",j);

    printf("\n删除栈顶元素：");
    j=Pop();
    StackTraverse();
    printf("所删除的栈顶元素是：");
    printf("%d",j);

    printf("\n此时栈的长度：");
    j=StackLength();
    printf("%d",j);

    printf("\n判断栈是否为空：");
    StackEmpty();
}


void queuetest()//队列测试
{
    int i;
    InitQueue();
    printf("\n创建队列后判断栈空：");
    QueueEmpty();

    printf("\n将1—10放入队列中，此时队列的元素为：");
    for ( i=1;i<11;i++)
    {
        EnQueue(i);
    }
    QueueTraverse();
    printf("此时队列长度：");
    QueueLength();
    printf("\n队列头的元素：");
    GetHead();
    printf("\n删除三个队列元素后队列元素为：");
    DeQueue();
    DeQueue();
    DeQueue();
    QueueTraverse();
    printf("此时队列长度为：");
    QueueLength();
    DestroyQueue();
}
/*void treetest()//树的测试
{
    printf("请先序输入一棵二叉树：\n");
    createBiTree();
    InitBiTree();


    if(!BiTreeEmpty())
    {   q=T.lchild;q=q->rchild;//设定一个q

        printf("层序遍历：");
        LevelOrderTraverse(&T);printf("\n");//层序
        printf("先序遍历：");       
        PreOrderTraverse_1(T);printf("\n");//先序
        printf("中序遍历：");
        InOrderTraverse_1(T);printf("\n");//中序
        printf("后序遍历：");
        PostOrderTraverse_1(T);printf("\n");//后序
        printf("q结点的值：");
        printf("%d\n",q->data);//打印
        printf("q的父节点：");
        printf("%d\n",(Parent().data));//q的父节点
        printf("q的左兄弟：");
        printf("%d\n",Value((LeftSibling())));//左兄弟
        printf("q的右兄弟：");
        printf("%d\n",Value((RightSibling())));//右兄弟
        printf("q的左儿子：");
        printf("%d\n",Value((LeftChild())));//左儿子
        printf("q的右儿子：");
        printf("%d\n",Value((RightChild())));//右儿子
        printf("q赋完新值100\n先序遍历："); 
        Assign(100);//给q赋值100
        PreOrderTraverse_1(T);printf("\n");
        printf("q的左儿子值变成0，原q的左儿子变成0的右儿子\n先序遍历：");
        InsertChild(0);//让q的左儿子变成c，c的右儿子为原q的左儿子
        PreOrderTraverse_1(T);printf("\n");
        printf("删除q的左儿子\n先序遍历：");
        DeleteChild(0);//删除q的左儿子
        PreOrderTraverse_1(T);printf("\n");

       // ClearBiTree(T);
}
}*/
/*1 2 4 0 0 5 6 0 7 0 0 0 3 0 0 */

void graphtest()//图的测试
{

    int j,k,p,q,m,n;
    printf("请输入图的类型：");
    scanf("%d",&G.kind);
    printf("请输入点数，边数：\n");
    scanf("%d %d",&k,&j);
    G.vnum=k;
    G.anum=j;
    for (p=1;p<=G.vnum;p++)
    {
        for(q=1;q<=G.vnum;q++)
        {
            if (p==q)G.arcs[p][q]=0;
            else
                G.arcs[p][q]=X;
        }
    }
    printf("请输入点到另一点及其之间的距离：\n");
    for(j=0;j<G.anum;j++)
    {
        scanf("%d %d %d",&p,&k,&q);
        G.arcs[p][q]=k;
        if (G.kind==1)
        {
            G.arcs[q][p]=k;
        }
    }
    printf("\n1.找到和第一个点有关的边(重复说明在有向图中两点互相可达）：");
    adjvex(1);

    printf("2.请输入求最短距离的两端点并输出最短路径：");
    scanf("%d %d",&m,&n);printf("jkl");
    ShortesPath_DIJ(m,n);

    printf("\n3.增加一个点：\n");
    addvex();

    printf("\n4.删除一个点：\n");
    destroyvex();

    printf("\n5.增加一条边：");
    addanum();

    printf("\n6.删除一条边：");
    destroyanum();

    getchar();getchar();getchar();
}

int main(void)
{
    printf("栈的测试\n");
    stacktest();

    printf("\n\n队列的测试");
    queuetest();

    /*printf("\n\n树的测试");
    treetest();*/

    printf("\n\n图的测试\n");
    graphtest();
    return ;
}
