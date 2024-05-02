#include "../headers/taskFunctions.h"

void fileOpenVerification(FILE *file)
{
    if (file == NULL)
    {
        perror("File Error: ");
        exit(-1);
    }
}

void fileDeclarations(FILE *filename1, FILE *filename2, FILE *filename3, char argv[])
{
    // Deschiderea fisierelor din linia de comanda
    filename1 = fopen(argv[1], "r");
    fileOpenVerification(filename1);

    filename2 = fopen(argv[2], "r");
    fileOpenVerification(filename2);

    filename1 = fopen(argv[3], "w");
    fileOpenVerification(filename3);
}

void taskInit(FILE *filename1, int v[5])
{
    // Initializarea datelor din c.in intr-un vector
    for (int i = 0; i < 5; i++)
    {
        fscanf(filename1, "%d ", &v[i]);
    }
}

void taskCall(int i)
{
    // Apeleaza functia cu task-ul corespunzator
    if (i == 1)
        task1();
    if (i == 2)
        task2();
    if (i == 3)
        task3();
    if (i == 4)
        task4();
    if (i == 5)
        task5();
}