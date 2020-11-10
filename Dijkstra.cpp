#include<iostream>
#include"ALGraph.h"
#define MaxInt 1000
#define MaxSize 50
using namespace std;
void ShorttestPath_DIJ(ALGraph& G, int v0)
{
    int n = G.vexnum;
    int dist[MaxSize];
    int pre[MaxSize];
    bool s[MaxSize];
    for (int v = 0; v < n; v++)
    {
        dist[v] = MaxInt;
    }
    for (ArcNode* p = G.vertices[v0].firstarc; p != NULL; p = p->nextarc)
    {
        dist[p->adjvex] = p->info;
    }
    for (int i = 0; i < n; i++)
    {
        s[i] = 0;
        if (dist[i] == MaxInt)
            pre[i] = 0;
        else
            pre[i] = v0;
    }
    dist[v0] = 0;
    s[v0] = 1;
    for (int i = 1; i < n; i++)
    {
        int temp = MaxInt;
        int u = v0;
        for (int j = 1; j < n; j++)
        {
            if (!s[j] && dist[j] < temp)
            {
                u = j;
                temp = dist[j];
            }
        }
        s[u] = 1;
        for (ArcNode* p = G.vertices[u].firstarc; p != NULL; p = p->nextarc)
        {
            int newdist = p->info + dist[u];
            if (newdist < dist[p->adjvex])
            {
                dist[p->adjvex] = newdist;
                pre[p->adjvex] = u;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << "源点到第" << i << "个顶点的最短距离为：" << dist[i] << endl;
}
