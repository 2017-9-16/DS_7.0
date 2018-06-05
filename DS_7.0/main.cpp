//
//  main.cpp
//  DS_7.0
//
//  Created by Walter Mitty on 2018/6/5.
//  Copyright © 2018年 Walter Mitty. All rights reserved.
//

#include <iostream>
#define MaxNodeNum 20
typedef char VertexType;
typedef struct node{ //边表结点
    int adjtex; //邻接点域
    struct node *next; //链域
}EdgeNode; //若也表示边上的权，增加一个数据域
typedef struct vnode{ //顶点表结点
VertexType vertex; //顶点域
EdgeNode *firstedge; // 边表头指针
} VertexNode;
typedef VertexNode AdjList[MaxNodeNum]; typedef struct{
    AdjList adjlist;// 邻接表
    int n,e; //顶点数和边数
}ALGraph; //对于简单应用无需定义此类型，直接使用AdjList
void CreateALGraph(ALGraph *G) {
    int i,j,k;
    EdgeNode *s;
    scanf("%d%d",&G->n,&G->e); //读入顶点数和边数
    for(i=0;i<G->n;i++){ //建立顶点表
    G->adjlist[i].vertex=getchar( ); //读入顶点信息
    G->adjlist[i].firstedge=NULL;} //边表置空
    for(k=0;k<G->e;k++){ //建立边表
scanf("%d%d",&i,&j); //读入边(vi,vj)的顶点对序
s=(EdgeNode *)malloc(sizeof(EdgeNode)); //生成边表结点
        s->adjtex=j; //邻结点的序号为j
s->next=G-> adjlist[i].firstedge;//前插入
G-> adjlist[i].firstedge=s; //将新结点*s插入vi头部
        s= (EdgeNode *)malloc(sizeof(EdgeNode)); s->adjtex=i; //邻接序号为i
s->next=G-> adjlist[j].firstedge;
G-> adjlist[j].firstedge=s; //将新结点*s插入vj头部
} }
int main(int argc, const char * argv[]) {
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
