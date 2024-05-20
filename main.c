#include "main.h"
#include "./headers/taskFunctions.h"
#include "./headers/queue.h"

int main(int argc, char *argv[])
{

    FILE *ftask, *fin, *fout; // ftask = c.in , fin = d.in , fout = r.out

    ftask = fopen(argv[1], "rb");
    fileOpenVerification(ftask);

    fin = fopen(argv[2], "rb");
    fileOpenVerification(fin);

    fout = fopen(argv[3], "wb");
    fileOpenVerification(fout);

    int task[numberOfTasks];
    taskInit(ftask, task);

    fclose(ftask);

    Node *listTeams = NULL, *lastEightTeams = NULL;
    Tree *lastEightTree = NULL;

    int nr_teams = numberOfTeams(fin, nr_teams);

    if (task[0] == 1)
    {

        task1(fin, fout, &listTeams, nr_teams);
        fclose(fout);
        fclose(fin);
    }
    if (task[1] == 1)
    {
        fout = fopen(argv[3], "wb");
        fileOpenVerification(fout);

        task2(&listTeams, nr_teams, fout);
    }

    if (task[2] == 1)
    {
        lastEightTeams = task3(listTeams, fout, nr_teams);
    }
    Node *orderLastEightTeams = NULL;
    if (task[3] == 1)
    {
        orderLastEightTeams = task4(lastEightTeams, fout);
    }
    if (task[4] == 1)
        task5(orderLastEightTeams, fout);

    fclose(fout);

    return 0;
}