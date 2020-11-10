#include"ALGraph.h"
#include<iostream>
using namespace std;
typedef int Status;
Status LocateVex(ALGraph& G, char i)//ȷ����ͼ�е����
{
    for (int j = 0; j < G.vexnum; j++)
    {
        if (G.vertices[j].data == i)
            return j;
        continue;
    }
    return 0;
}
Status CreateUDG(ALGraph& G)//�����ڽӾ����ʾ��������������G
{
    cout << "���붥�����ͱ���:";
    cin >> G.vexnum >> G.arcnum;//���붥�����ͱ���
    char v1, v2;
    int weight;
    cout << "���붥��Ԫ��:" << endl;
    for (int i = 0; i < G.vexnum; i++)
    {
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }
    cout << "��������߶��㼰Ȩֵ:" << endl;
    for (int k = 0; k < G.arcnum; k++)//������ߣ������ڽӱ�
    {
        cin >> v1 >> v2 >> weight;//����һ������������������
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);
        ArcNode* p1 = new ArcNode;
        p1->adjvex = j;//�ڽӵ����Ϊj
        p1->info = weight;
        p1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1;
        ArcNode* p2 = new ArcNode;
        p2->adjvex = i;//�ڽӵ����Ϊi
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
