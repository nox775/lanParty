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
    fscanf(file, "%d %[^\n]", &(buffer.numberOfPlayers), buffer.teamName);

    buffer.teamName[strlen(buffer.teamName) - 1] = '\0';
    if (buffer.teamName[strlen(buffer.teamName) - 1] == ' ')
    {
        buffer.teamName[strlen(buffer.teamName) - 1] = '\0';
    }

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
    int power = 0;
    while (nr_teams > 1)
    {
        nr_teams = nr_teams / 2;
        power++;
    }

    int remaning = 1;
    for (int i = 1; i <= power; i++)
        remaning = remaning * 2;

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

int VersusWinner(teamInfo team1, teamInfo team2)
{
    // Aflarea castigatorului meciului
    if (team1.teamPoints > team2.teamPoints)
        return 1;
    else
        return 0;
}

void printGames(Queue **QueueGames, FILE *fout, int nr_games, int round, Node **WinStack, Node **LoseStack)
{
    // pune in fisierul de iesire date despre meciuri
    //  compara echipele
    teamInfo team1, team2;
    fprintf(fout, "\n--- ROUND NO:%d\n", round);

    for (int i = 1; i <= nr_games; i++)
    {
        team1 = deQueue(*QueueGames);
        team2 = deQueue(*QueueGames);

        fprintf(fout, "%-32s - %32s\n", team1.teamName, team2.teamName);

        if (VersusWinner(team1, team2) == 1)
        {
            team1.teamPoints++;
            push(WinStack, team1);
            push(LoseStack, team2);
        }
        else
        {
            team2.teamPoints++;
            push(WinStack, team2);
            push(LoseStack, team1);
        }
    }
}

void printWinners(Node *WinStack, int round, FILE *fout, int nr_teams)
{
    // Afiseaza castigatorii fiecarei runde
    fprintf(fout, "\nWINNERS OF ROUND NO:%d\n", round);

    for (int i = 1; i <= nr_teams / 2; i++)
    {
        fprintf(fout, "%-32s  -  %.2f\n", WinStack->val.teamName, WinStack->val.teamPoints);
        WinStack = WinStack->next;
    }
}

void QueueExtractFromList(Queue **QueueGames, Node *listTeams)
{
    // Puna in coada echipele din lista
    while (listTeams != NULL)
    {
        enQueue(*QueueGames, listTeams->val);
        listTeams = listTeams->next;
    }
}

void QueueExtractFromStack(Queue **QueueGames, Node *WinStack)
{
    // Pune in coada echipele victorioase din stiva
    while (WinStack != NULL)
    {
        enQueue(*QueueGames, WinStack->val);
        WinStack = WinStack->next;
    }
    deleteStack(&WinStack);
}

Node *task3(Node *listTeams, FILE *fout, int nr_teams)
{
    nr_teams = NumberRemaningTeams(nr_teams);
    int nr_games = nr_teams / 2;
    int round = 1;

    Queue *QueueGames = createQueue();
    Node *WinStack = NULL, *LoseStack = NULL, *LastEightList = NULL;

    QueueExtractFromList(&QueueGames, listTeams);

    while (nr_teams >= 2)
    {

        if (nr_teams == 8)
            addWinnersToList(&LastEightList, WinStack);

        printGames(&QueueGames, fout, nr_games, round, &WinStack, &LoseStack);
        printWinners(WinStack, round, fout, nr_teams);

        nr_teams = nr_teams / 2;
        nr_games = nr_games / 2;
        round++;

        deleteQueue(QueueGames);
        QueueGames = createQueue();

        QueueExtractFromStack(&QueueGames, WinStack);

        deleteStack(&LoseStack);
    }
    deleteList(&listTeams);
    return LastEightList;
}
