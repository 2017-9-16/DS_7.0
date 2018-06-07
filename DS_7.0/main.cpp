//
//  main.cpp
//  DS_7.0
//
//  Created by Walter Mitty on 2018/6/5.
//  Copyright © 2018年 Walter Mitty. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#define MaxNodeNum 20
typedef char VertexType;
typedef struct node{ //边表结点
    int adjvex; //邻接点域
    struct node *next; //链域
}EdgeNode; //若也表示边上的权，增加一个数据域
typedef struct vnode{ //顶点表结点
VertexType vertex; //顶点域
EdgeNode *firstedge; // 边表头指针
} VertexNode;
typedef VertexNode AdjList[MaxNodeNum];
typedef struct{
    AdjList adjlist;// 邻接表
    int n,e; //顶点数和边数
}ALGraph;

void  CreateGraph(ALGraph* G) {
    int i,j,k;
    EdgeNode *s;
    int m;
    printf("要建立的是有向图（1）还是无向图（0），请选择（输入1或0）：\n");
    scanf("%d",&m);
    printf("请输入图的顶点数\n");
    scanf("%d",&(G->n)); //读入顶点数和边数
    printf("请输入图的边数\n");
    scanf("%d",&(G->e));
    //getchar();
    printf("请输入图的各顶点信息：\n");
    for(i=0;i<G->n;i++){ //建立顶点表
        
            printf("第%d个顶点信息",i+1);
            getchar();
            scanf("%c",&(G->adjlist[i].vertex));
            G->adjlist[i].firstedge=NULL;
        
    } //边表置空

    for(k=0;k<G->e;k++){ //建立边表
        printf("请输入第%d条边(以空格分隔)",k);
        scanf("%d%d",&i,&j); //读入边(vi,vj)的顶点对序
        s=(EdgeNode *)malloc(sizeof(EdgeNode)); //生成边表结点
        s->adjvex=j; //邻结点的序号为j
        s->next=G->adjlist[i].firstedge;//前插入
        G->adjlist[i].firstedge=s; //将新结点*s插入vi头部
        //无向图 边的节点要再连接一次
        if (!m) {
            s= (EdgeNode *)malloc(sizeof(EdgeNode));
            s->adjvex=i; //邻接序号为i
            s->next=G->adjlist[j].firstedge;
            G->adjlist[j].firstedge=s; //将新结点*s插入vj头部
        }
}
 
    
}
void print(ALGraph *G)
{
    int i;
    EdgeNode *p;
    p=(EdgeNode*)malloc(sizeof(EdgeNode));
    for (i=0; i<G->n; i++) {
        
        printf("[%c]",G->adjlist[i].vertex);
        p=G->adjlist[i].firstedge;
        while (p!=NULL) {
            printf("->[%d]",p->adjvex);
            p=p->next;
        }
        printf("\n");
    }
}

int main() {
    
    ALGraph G ;
    CreateGraph(&G);
    print(&G);
}
