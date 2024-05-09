#include "main.h"
#include "./headers/taskFunctions.h"

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

    Node *listTeams = NULL;
    int nr_teams = numberOfTeams(fin, nr_teams);
    if (task[0] == 1)
    {
        fout = fopen(argv[3], "wb");
        fileOpenVerification(fout);
        task1(fin, fout, &listTeams, nr_teams);
        fclose(fout);
    }

    if (task[1] == 1)
    {
        fout = fopen(argv[3], "wb");
        fileOpenVerification(fout);

        task2(&listTeams, nr_teams, fout);
        fclose(fout);
    }
    /*
   if (task[2] == 1)
       task3();
   if (task[3] == 1)
       task4();
   if (task[4] == 1)
       task5();*/

    fclose(fin);

    return 0;
}