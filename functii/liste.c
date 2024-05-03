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