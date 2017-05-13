#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
typedef
struct QNode{
    ElemType data;
    struct QNode *next;
}QNode, *QueuePrt;

typedef
struct{
    QueuePrt front,rear;//the front node do not contain data
}LinkQueue;

InitQueue(LinkQueue *q)
{
    q->front = q->rear = (QueuePrt)malloc(sizeof(QNode));
    if(!q->rear)
    {
        exit(0);
    }
    q->front->next = NULL;
}

InsertQueue(LinkQueue *q, ElemType e)
{
    QueuePrt p;
    p = (QueuePrt)malloc(sizeof(QNode));
    if(p==NULL)
        exit(0);

    p->data = e;
    q->rear->next = p;
    p->next = NULL;
    q->rear = p;
}

DeleteQueue(LinkQueue *q, ElemType *e)
{
    QueuePrt p;
    if( q->front == q->rear )//if it is an empty queue
        exit(0);

    p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    if( q->rear == p )//don't understand
        q->rear = q->front;
    free(p);
}

int main()
{
    char c;
    int i;
    LinkQueue q;
    InitQueue(&q);

    printf("请输入您要输入的字符串,以符号#作为结束符\n");
    scanf("%c",&c);
    while( c != '#' )
    {
        InsertQueue(&q, c);
        scanf("%c",&c);
    }
    getchar();

    printf("以队列形式输出\n");


    while( q.front != q.rear )
    {
        DeleteQueue(&q ,&c);
        printf("%c",c);
    }

    return 0;
}
