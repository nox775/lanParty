#include "../main.h"
#include "../headers/taskFunctions.h"
#include "../headers/liste.h"

void addAtBeginning(Node **head, teamInfo buffer, FILE *fin)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    (newNode->val).numberOfPlayers = buffer.numberOfPlayers;
    strcpy(newNode->val.teamName, buffer.teamName);

    newNode->val = fileReadPlayer(fin, newNode->val, (newNode->val).numberOfPlayers);

    newNode->next = *head;
    *head = newNode;
}

void deleteNode(Node **head, float val)
{
    if (*head == NULL)
        return;

    Node *headcopy = *head;
    if (float_equal(val, headcopy->val.teamPoints))
    {
        *head = (*head)->next;
        free(headcopy);
        return;
    }

    Node *prev = *head;
    while (headcopy != NULL)
    {
        if (!float_equal(val, headcopy->val.teamPoints))
        {
            prev = headcopy;
            headcopy = headcopy->next;
        }
        else
        {
            prev->next = headcopy->next;
            free(headcopy);
            return;
        }
    }
}

void deleteList(Node **head)
{
    Node *headcopy;

    while (*head != NULL)
    {
        headcopy = (*head)->next;
        free(*head);
        *head = headcopy;
    }
    *head = NULL;
}

void addWinnersToList(Node **head, Node *WinStack)
{
    for (int i = 0; i < 8; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->val = WinStack->val;
        newNode->next = *head;
        *head = newNode;
        WinStack = WinStack->next;
    }
}