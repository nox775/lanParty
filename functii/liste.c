#include "../main.h"
#include "../headers/taskFunctions.h"
#include "../headers/liste.h"

void addToListFromFIile(Node **head, FILE *fin, int nr_teams)
{
    // scrie din fisier in lista
    for (int i = 0; i < nr_teams; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));

        newNode->val.teamName = (char *)malloc(maxName * sizeof(char));

        if (!newNode->val.teamName)
        {
            printf("Memory allocation failed\n");
            exit(-1);
        }
        newNode->val = fileReadTeam(fin, newNode->val);

        newNode->val.player = (playerInfo *)malloc(newNode->val.numberOfPlayers * sizeof(playerInfo));

        if (!newNode->val.player)
        {
            printf("Memory allocation failed\n");
            exit(-1);
        }
        for (int j = 0; j < newNode->val.numberOfPlayers; j++)
        {
            newNode->val.player[j].firstName = (char *)malloc(maxName * sizeof(char));
            newNode->val.player[j].secondName = (char *)malloc(maxName * sizeof(char));
        }

        newNode->val = fileReadPlayer(fin, newNode->val, (newNode->val).numberOfPlayers);
        newNode->next = *head;
        *head = newNode;
    }
}

void addAtBeginning(Node **head, teamInfo buffer)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = buffer;
    newNode->next = *head;
    *head = newNode;
}

void addAtEnd(Node **head, teamInfo v)
{
    Node *aux = *head;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = v;
    if (*head == NULL)
        addAtBeginning(head, v);
    else
    {
        while (aux->next != NULL)
            aux = aux->next;
        aux->next = newNode;
        newNode->next = NULL;
    }
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
    // pune din lista in stiva cu invingatori
    for (int i = 0; i < 8; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->val = WinStack->val;
        newNode->next = *head;
        *head = newNode;
        WinStack = WinStack->next;
    }
}

void totalTeamPoints(Node *listTeams)
{
    // Calculeaza punctele pe echipa si le memoreaza in campul teamPoints

    while (listTeams != NULL)
    {

        float points = 0;
        for (int i = 0; i < listTeams->val.numberOfPlayers; i++)
            points = points + listTeams->val.player[i].points;

        listTeams->val.teamPoints = points / ((float)listTeams->val.numberOfPlayers);

        listTeams = listTeams->next;
    }
}

void lastTeamPoints(Node *listTeams, int nr_teams, float *scoring)
{
    // sorteaza intr-un vector punctajele echipelor
    // pune la final punctajele mic;
    int i = 0;
    while (listTeams != NULL)
    {

        scoring[i] = listTeams->val.teamPoints;
        listTeams = listTeams->next;
        i++;
    }

    descending_sort(scoring, nr_teams);
}

void printNameOfTeams(FILE *fout, Node *listTeams)
{
    // scrie in fisierul de iesire numele echipelor din lista
    while (listTeams->next != NULL)
    {
        fprintf(fout, "%s\n", listTeams->val.teamName);
        listTeams = listTeams->next;
    }
    fprintf(fout, "%s\n", listTeams->val.teamName);
}