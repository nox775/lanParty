#include "../main.h"
#include "../headers/taskFunctions.h"
// #include "../headers/liste.h"
// #include "../headers/stack.h"
#include "../headers/queue.h"

Queue *createQueue()
{
    Queue *q;
    q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL)
        return NULL;
    q->front = q->rear = NULL;
    return q;
}

void enQueue(Queue *q, teamInfo v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = v;
    newNode->next = NULL;

    if (q->rear == NULL)
        q->rear = newNode;
    else
    {
        (q->rear)->next = newNode;
        (q->rear) = newNode;
    }
    if (q->front == NULL)
        q->front = q->rear;
}

int isEmptyQueue(Queue *q)
{
    return (q->front == NULL);
}

teamInfo deQueue(Queue *q)
{
    Node *aux;
    teamInfo d;
    if (isEmptyQueue(q))
    {
        printf("Coada goala\n");
        exit(-1);
    }

    aux = q->front;
    d = aux->val;
    q->front = (q->front)->next;
    free(aux);
    return d;
}

void deleteQueue(Queue *q)
{
    Node *aux;
    while (!isEmptyQueue(q))
    {
        aux = q->front;
        q->front = q->front->next;
        free(aux);
    }
    free(q);
}