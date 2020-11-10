#include"ALGraph.h"
#include<iostream>
using namespace std;
typedef int Status;
Status LocateVex(ALGraph& G, char i)//确定在图中的序号
{
    for (int j = 0; j < G.vexnum; j++)
    {
        if (G.vertices[j].data == i)
            return j;
        continue;
    }
    return 0;
}
Status CreateUDG(ALGraph& G)//采用邻接矩阵表示法，创建无向网G
{
    cout << "输入顶点数和边数:";
    cin >> G.vexnum >> G.arcnum;//输入顶点数和边数
    char v1, v2;
    int weight;
    cout << "输入顶点元素:" << endl;
    for (int i = 0; i < G.vexnum; i++)
    {
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }
    cout << "输入边两边顶点及权值:" << endl;
    for (int k = 0; k < G.arcnum; k++)//输入各边，构建邻接表
    {
        cin >> v1 >> v2 >> weight;//输入一条边依附的两个顶点
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);
        ArcNode* p1 = new ArcNode;
        p1->adjvex = j;//邻接点序号为j
        p1->info = weight;
        p1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1;
        ArcNode* p2 = new ArcNode;
        p2->adjvex = i;//邻接点序号为i
        p2->nextarc = G.vertices[j].firstarc;
        p2->info = weight;
        G.vertices[j].firstarc = p2;
    }
    return 1;
}
void print(ALGraph G)
{
    int i;
    ArcNode* p;
    for (i = 0; i < G.vexnum; i++)
    {
        p = G.vertices[i].firstarc;
        while (p)
        {
            cout << "(" << G.vertices[i].data << "," << G.vertices[p->adjvex].data << "," << p->info << ")";
            p = p->nextarc;
        }
        cout << endl;
    }
}
