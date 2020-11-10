#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#define MAXSIZE 100
#include<iostream>
#include<cstdlib>
typedef int Status;
typedef int SElemType;
typedef int QElemType;
typedef struct
{
    QElemType* base;
    int front;
    int rear;
}Queue;
bool Empty(Queue& Q)
{
    return Q.rear == Q.front;
}
Status InitQueue(Queue& Q)
{
    Q.base = new QElemType[MAXSIZE];
    if (!Q.base)
        exit(1);
    Q.front = Q.rear = 0;
    return 0;
}
Status EnQueue(Queue& Q, QElemType e)
{
    if ((Q.rear + 1) % MAXSIZE == Q.front)
        return 1;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return 0;
}
Status DeQueue(Queue& Q, QElemType& e)
{
    if (Q.rear == Q.front)
        return 1;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    return 0;
}
SElemType GetHead(Queue& Q)
{
    if (Q.front != Q.rear)
        return Q.base[Q.front];
    return 0;
}


#endif // QUEUE_H_INCLUDED
