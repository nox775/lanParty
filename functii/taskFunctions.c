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

void task1(FILE *fin, FILE *fout, Node *listTeams, int nr_teams)
{
    // scrie informatiile despre echipa intr-o lista
    teamInfo team;

    for (int i = 0; i < nr_teams; i++)
    {
        team = fileReadTeam(fin, team);

        addAtBeginning(&listTeams, team, fin);
    }
    printNameOfTeams(fout, listTeams);
}

void totalTeamPoints(Node **listTeams)
{
    // Calculeaza punctele pe echipa si le memoreaza in campul teamPoints
    Node *headcopy = *listTeams;

    while (headcopy != NULL)
    {

        float points = 0;
        for (int i = 0; i < headcopy->val.numberOfPlayers; i++)
            points = points + (headcopy->val.player[i]).points;

        headcopy->val.teamPoints = points / headcopy->val.numberOfPlayers;
        headcopy = headcopy->next;
    }
}

int NumberRemaningTeams(int nr_teams)
{
    // numarul de echipe ramase
    int power = 0;
    while (nr_teams)
    {
        nr_teams = nr_teams / 2;
        power++;
    }

    int remaning = 1;
    for (int i = 0; i <= power; i++)
        remaning = remaning * 2;

    return remaning;
}

void descending_sort(int *v, int nr_teams)
{
    for (int i = 0; i < nr_teams; i++)
        for (int j = 0; j < nr_teams; j++)
            if (v[i] < v[j])
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
}

void *lastTeamPoints(Node *listTeams, int nr_teams, int *scoring)
{
    // sorteaza intr-un vector punctajele echipelor
    // pune la final punctajele mic;

    for (int i = 0; i < nr_teams; i++)
    {
        scoring[i] = listTeams->val.teamPoints;
        listTeams = listTeams->next;
    }
    descending_sort(scoring, nr_teams);
}

void task2(Node *listTeams, int nr_teams, FILE *fout)
{
    totalTeamPoints(&listTeams);

    int *scoring = (int *)malloc(nr_teams * sizeof(int));
    lastTeamPoints(listTeams, nr_teams, scoring);

    int nr_teams_remaning = NumberRemaningTeams(nr_teams);

    for (int i = nr_teams - 1; i >= nr_teams_remaning; i--)
    {
        deleteNode(&listTeams, scoring[i]);
    }
    printNameOfTeams(fout, listTeams);
}