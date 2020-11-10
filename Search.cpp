#include"ALGraph.h"
#include"Queue.h"
#include<iostream>
using namespace std;
bool visited[MVNum];
void DFS(ALGraph& G, int v)
{
    int w;
    cout << G.vertices[v].data;
    visited[v] = true;
    ArcNode* p = G.vertices[v].firstarc;
    while (p != NULL)
    {
        w = p->adjvex;
        if (!visited[w])
            DFS(G, w);
        p = p->nextarc;
    }
}
void DFSTraverse(ALGraph& G, int v)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        visited[i] = false;
    }
    for (int j = v; j < G.vexnum; j++)
    {
        if (!visited[j])
            DFS(G, j);
    }
}
void BFS(ALGraph G, int v)
{
    Queue Q;
    int u, w;
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = false;
    cout << G.vertices[v].data;
    visited[v] = true;
    InitQueue(Q);
    EnQueue(Q, v);
    while (!Empty(Q))
    {
        DeQueue(Q, u);
        ArcNode* p = G.vertices[u].firstarc;
        while (p != NULL)
        {
            w = p->adjvex;
            if (!visited[w])
            {
                cout << G.vertices[w].data;
                visited[w] = true;
                EnQueue(Q, w);
            }
            p = p->nextarc;
        }
    }
}
