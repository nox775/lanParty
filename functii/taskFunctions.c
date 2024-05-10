#include "../main.h"
#include "../headers/taskFunctions.h"
#include "../headers/liste.h"
#include "../headers/stack.h"
#include "../headers/queue.h"

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
    fscanf(file, "%d %[^\n]\n", &(buffer.numberOfPlayers), buffer.teamName);
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

void task1(FILE *fin, FILE *fout, Node **listTeams, int nr_teams)
{
    // scrie informatiile despre echipa intr-o lista
    teamInfo team;

    for (int i = 0; i < nr_teams; i++)
    {
        team = fileReadTeam(fin, team);

        addAtBeginning(listTeams, team, fin);
    }
    printNameOfTeams(fout, *listTeams);
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

        // printf("\n%s %.2f\n", listTeams->val.teamName, listTeams->val.teamPoints);

        listTeams = listTeams->next;
    }
}

int NumberRemaningTeams(int nr_teams)
{
    // numarul de echipe ramase
    // printf("\n ECHIPE %d \n", nr_teams);
    int power = 0;
    while (nr_teams > 1)
    {
        nr_teams = nr_teams / 2;
        power++;
    }

    int remaning = 1;
    for (int i = 1; i <= power; i++)
        remaning = remaning * 2;

    //  printf("\n ECHIPE RAMASE %d \n", remaning);

    return remaning;
}

void descending_sort(float *v, int nr_teams)
{
    for (int i = 0; i < nr_teams; i++)
        for (int j = 0; j < nr_teams; j++)
            if (v[i] > v[j])
            {
                float aux = v[i];
                v[i] = v[j];
                v[j] = aux;
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

int float_equal(float a, float b)
{
    return fabs(a - b) < epsilon;
}

void task2(Node **listTeams, int nr_teams, FILE *fout)
{
    totalTeamPoints(*listTeams);

    float *scoring = (float *)malloc(nr_teams * sizeof(float));

    lastTeamPoints(*listTeams, nr_teams, scoring);

    int nr_teams_remaning = NumberRemaningTeams(nr_teams);

    for (int i = nr_teams - 1; i >= nr_teams_remaning; i--)
    {
        deleteNode(listTeams, scoring[i]);
    }

    printNameOfTeams(fout, *listTeams);
    free(scoring);
}

void printGames(Queue *games, FILE *fout, int nr_games)
{
    int rounda = 1;

    teamInfo team1, team2;
    // while (nr_games)
    // {
    fprintf(fout, "\n--- ROUND NO:%d\n", rounda);
    for (int i = 1; i <= nr_games; i++)
    {
        team1 = deQueue(games);
        team2 = deQueue(games);
        team1.teamName[strlen(team1.teamName) - 1] = '\0';
        team2.teamName[strlen(team2.teamName) - 1] = '\0';
        fprintf(fout, "%-30s - %30s\n", team1.teamName, team2.teamName);
    }
    //  rounda++;
    // nr_games = nr_games / rounda;
    // }
}

void makeGames(Queue **games, Node *listTeams)
{
    while (listTeams != NULL)
    {
        enQueue(*games, listTeams->val);
        listTeams = listTeams->next;
    }
}

void task3(Node *listTeams, FILE *fout, Queue **games, int nr_teams)
{
    int nr_games = NumberRemaningTeams(nr_teams) / 2;
    makeGames(games, listTeams);
    printGames(*games, fout, nr_games);
}