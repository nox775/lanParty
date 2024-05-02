#include "main.h"
#include "./headers/taskFunctions.h"

int main(int argc, char *argv[])
{

    FILE *fin, *fout, *ftask;
    fileDeclarations(ftask, fin, fout, argv);
    int v[5];
    taskInit(ftask, v);

    for (int i = 0; i < 5; i++)
    {
        if (v[i] == 1)
            taskCall(i + 1);
    }

    return 0;
}