#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define numberOfTasks 5
#define maxName 50
#define maxNrPlayers 20
#define epsilon 0.00001

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
    float teamPoints;
    playerInfo player[maxNrPlayers];
};

typedef struct Team teamInfo;

struct elem
{
    teamInfo val;
    struct elem *next;
};

typedef struct elem Node;

struct Q
{
    Node *front, *rear;
};
typedef struct Q Queue;