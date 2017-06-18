#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/graph.h"
#define X 100
typedef struct MGraph//图的结构
{
    int arcs[22][22];
    int vnum,anum;
    int kind;//kind=0表示有向图，kind=1表示无向图
}MGraph;
int Q[22];
int P[22];
int D[22],finall[22];
extern MGraph G;
void addvex()
{
    int i,j,k,m,n,h;
    h=0;
    printf("点为G.vnum+1,增加的边数：");
    scanf("%d",&j);
    printf("输入相关边的信息（点 边 点）：\n");
    for(i=1;i<=j;i++)
    {
        scanf("%d %d %d",&m,&k,&n);
        G.arcs[m][n]=k;
        if(G.kind==1)
        {
            G.arcs[n][m]=k;
        }
    }
    G.anum=G.anum+j;
    G.vnum++;
}
void destroyvex()
{
    int i,j,k,h;
    h=0;
    printf("输入要删除的点：");
    scanf("%d",&k);
    printf("此时该点到各个点的距离：");
    for (i=1;i<G.vnum;i++)
    {
        if(G.arcs[i][k]<100&&G.kind==1)
        {
            G.arcs[i][k]=100;
            G.arcs[k][i]=100;
            h++;
            printf("%d ",G.arcs[k][i]);
        }
        else if(G.kind==0)
        {
            if(G.arcs[i][k]<100)
            {
                G.arcs[i][k]=100;
                h++;
                printf("%d ",G.arcs[i][k]);
            }
            if (G.arcs[k][i]<100)
            {
                G.arcs[k][i]=100;
                printf("%d ",G.arcs[k][i]);
                h++;
            }

        }
    }
    G.vnum--;
    G.anum=G.anum-h;
}
void addanum()
{
    int i,j,m,n,k;
    G.anum++;
    printf("输入边的信息（点 权值 点）：");
    scanf("%d %d %d",&m,&k,&n);
    G.arcs[m][n]=k;
    if(G.kind==1)
    {
        G.arcs[n][m]=k;
    }
    k=G.arcs[m][n];
    printf("此时该边权值为%d\n",k);
}
void destroyanum()
{
    int m,n,k;
    printf("输入要删除边的信息：");
    scanf("%d %d",&m,&n);
    G.arcs[m][n]=100;
    if(G.kind==1)
    {
        G.arcs[n][m]=100;
    }
    printf("此时该边权值为%d\n",G.arcs[m][n]);
}
void adjvex(int s)//和第一个点相连的点（若有向不考虑边的指向）
{
    int i,j,k,l;
    k=G.vnum;
    for(i=1;i<=G.vnum;i++)
    {
        if(i!=s)
        {
            if (G.arcs[i][s]<100)
            {
                printf("%d ",i);
                if(G.arcs[s][i]<100&&G.kind==0)
                    printf("%d ",i);
            }
        }
    }
    printf("\n");
}
void ShortesPath_DIJ(int m,int n)//两点之间最短路径
{
    int v,w,min,i,a[22],k;
    for (v=1;v<=G.vnum;++v)
    {
        finall[v]=0;D[v]=G.arcs[m][v];
        if (D[v]<100)
        {
            P[v]=m;
        }
    }
    D[m]=0;finall[m]=1;
    for (i=1;i<=G.vnum;i++)
    {
        min=X;
        for(w=1;w<=G.vnum;w++)
        {
            if(!finall[w])
            {
                if(D[w]<min)
                {
                    v=w;
                    min=D[w];
                }
            }
        }
            finall[v]=1;
            for(w=1;w<=G.vnum;w++)
            {
                k=min+G.arcs[v][w];
                if((finall[w]==0)&&(k<=D[w]))
                {
                    D[w]=min+G.arcs[v][w];
                    P[w]=v;
                }
            }
    }
    w=n;a[0]=n;v=1;
    do
    {
        a[v]=P[w];
        w=P[w];
        v++;
    }while(w!=m);
    for (w=v-1;w>=1;w--)
    {
        printf("%d-->",a[w]);
    }
    printf("%d\n",a[w]);
}



