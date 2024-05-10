#include "../main.h"
#include "../headers/taskFunctions.h"
// #include "../headers/liste.h"
#include "../headers/stack.h"
// #include "../headers/queue.h"

int isEmptyStack(Node *top)
{
    return top == NULL;
}

void push(Node **top, teamInfo v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = v;
    newNode->next = *top;
    *top = newNode;
}

teamInfo pop(Node **top)
{
    if (isEmptyStack(*top))
    {
        printf("Stiva goala");
        exit(-1);
    }

    Node *temp = (*top);

    teamInfo aux = temp->val;
    *top = (*top)->next;
    free(temp);
    return aux;
}

void deleteStack(Node **top)
{
    Node *temp;
    while (!isEmptyStack(*top))
    {
        temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}