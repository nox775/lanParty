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
    if (task[0] == 1)
        task1(fin, fout, listTeams);

    /*if (task[1] == 1)
        task2();
    if (task[2] == 1)
        task3();
    if (task[3] == 1)
        task4();
    if (task[4] == 1)
        task5();*/

    fclose(fin);
    fclose(fout);

    return 0;
}