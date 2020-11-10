#include <iostream>
#include"ALGraph.h"
typedef int Status;
using namespace std;
extern Status CreateUDG(ALGraph& G);
extern void DFSTraverse(ALGraph& G, int v);
extern void BFS(ALGraph G, int v);
extern void print(ALGraph G);
extern void ShorttestPath_DIJ(ALGraph& G, int v0);
int main()
{
    ALGraph G;
    int v = 0;
    CreateUDG(G);
    print(G);
    ShorttestPath_DIJ(G, v);
    cout << "1、深度优先搜索:" << endl;
    DFSTraverse(G, v);
    cout << endl;
    cout << "2、广度优先搜索:" << endl;
    BFS(G, v);
    return 0;
}
