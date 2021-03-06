#include <stdio.h>
#include <stdlib.h>
#include "include/stack.h"
#define STACK_INIT_size 100
#define stackincreament 10
typedef struct sq//栈的结构
{
    int *base;
    int *top;
    int stacksize;
}SqStack;
extern SqStack S;
void InitStack()//构造一个空栈
{
    S.base=(int*)malloc(100*sizeof(int));//
    if(!S.base)
        exit(-1);
    S.top=S.base;
    S.stacksize=STACK_INIT_size;
}
void DestroyStack()
{
    int len=S.stacksize;
    int i;
    for(i=0;i<len;i++)
    {
        free(S.base);
        S.base++;
    }
    S.base=S.top=NULL;
    S.stacksize=0;
}
void ClearStack()
{
    S.top=S.base;
}
void StackEmpty()
{
    if(S.top==S.base)
    {
        printf("栈为空");
        return ;
    }
    else
    {
        printf("栈不空");
        return ;
    }
}
int StackLength()
{
    return (*S.top-*S.base+1);
}
int GetTop()
{
    int e;
    if(S.top==S.base)
        return 0;
    e=*(S.top);
    return e;
}
void Push(int e)
{
    if(S.top-S.base>=S.stacksize)
    {
        S.base=(int*)realloc(S.base,(S.stacksize+stackincreament)*sizeof(int*));
        if(!S.base)
            exit(0);
        S.top=S.base+S.stacksize;
        S.stacksize+=stackincreament;
    }
    *S.top++;
    *S.top=e;
}
int Pop()
{
    int e;
    if(S.top==S.base)
        return 0;
    e=*S.top;
    *S.top--;
    return e;
}
void StackTraverse()
{
    int i;
    int *a;
    a=S.base;
    a--;
    for (i=0;a!=S.top;i++)
    {
        a++;
        printf("%d ",*a);
        
    }
    printf("\n");
}
