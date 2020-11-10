#ifndef ALGRAPH_H_INCLUDED
#define ALGRAPH_H_INCLUDED
#define MVNum 100//最大顶点数
typedef char VerTexType;
typedef int OtherInfo;
typedef struct ArcNode//边结点
{
    int adjvex;
    struct ArcNode* nextarc;
    OtherInfo info;
}ArcNode;
typedef struct VNode//表头节点
{
    VerTexType data;
    ArcNode* firstarc;
}VNode, AdjList[MVNum];
typedef struct//邻接表
{
    AdjList vertices;
    int vexnum, arcnum;//顶点数和边数
}ALGraph;

#endif // ALGRAPH_H_INCLUDED
