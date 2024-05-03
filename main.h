#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define numberOfTasks 5
#define maxName 50
#define maxNrPlayers 20

struct Players
{
    char firstName[maxName];
    char secondName[maxName];
    int points;
};

typedef struct Players playerInfo;

struct Team
{
    char teamName[maxName];
    int numberOfPlayers;
    playerInfo player[maxNrPlayers];
};

typedef struct Team teamInfo;

struct elem
{
    teamInfo val;
    struct elem *next;
};

typedef struct elem Node;