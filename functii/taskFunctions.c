#include "../main.h"
#include "../headers/taskFunctions.h"
#include "../headers/liste.h"

void fileOpenVerification(FILE *file)
{
    if (file == NULL)
    {
        printf("File doesnt open");
        perror("Fille Error");
        exit(-1);
    }
}

void taskInit(FILE *filename1, int v[numberOfTasks])
{
    // Initializarea datelor din c.in intr-un vector
    for (int i = 0; i < numberOfTasks; i++)
    {
        fscanf(filename1, "%d ", &v[i]);
    }
}

int numberOfTeams(FILE *file, int n)
{
    fscanf(file, "%d", &n);
    return n;
}

teamInfo fileReadTeam(FILE *file, teamInfo buffer)
{
    // citeste din fisier intr-un buffer informatii despre echipa
    fscanf(file, "%d %[^\n]", &(buffer.numberOfPlayers), buffer.teamName);

    return buffer;
}

teamInfo fileReadPlayer(FILE *file, teamInfo buffer, int n)
{
    // citeste din fisier intr-un buffer informatii despre jucator
    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%s %s %d", (buffer.player[i]).firstName, (buffer.player[i]).secondName, &((buffer.player[i]).points));
    }
    return buffer;
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

void task1(FILE *fin, FILE *fout, Node *listTeams)
{
    int n = numberOfTeams(fin, n);

    teamInfo team;

    for (int i = 0; i < n; i++)
    {
        team = fileReadTeam(fin, team);

        addAtBeginning(&listTeams, team, fin);
    }
    printNameOfTeams(fout, listTeams);
}