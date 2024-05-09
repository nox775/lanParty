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

void deleteNode(Node **head, int val)
{
    if (*head = NULL)
        return;

    Node *headcopy = *head;
    if (headcopy->val.teamPoints == val)
    {
        *head = (*head)->next;
        free(headcopy);
    }

    Node *prev = *head;
    while (headcopy != NULL)
    {
        if (headcopy->val.teamPoints != val)
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