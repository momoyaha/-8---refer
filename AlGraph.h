#ifndef ALGRAPH_H_INCLUDED
#define ALGRAPH_H_INCLUDED
#define MVNum 100//��󶥵���
typedef char VerTexType;
typedef int OtherInfo;
typedef struct ArcNode//�߽��
{
    int adjvex;
    struct ArcNode* nextarc;
    OtherInfo info;
}ArcNode;
typedef struct VNode//��ͷ�ڵ�
{
    VerTexType data;
    ArcNode* firstarc;
}VNode, AdjList[MVNum];
typedef struct//�ڽӱ�
{
    AdjList vertices;
    int vexnum, arcnum;//�������ͱ���
}ALGraph;

#endif // ALGRAPH_H_INCLUDED
