#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define numberOfTasks 5
#define maxName 50
#define epsilon 0.00001

typedef struct Players
{
    char *firstName;
    char *secondName;
    int points;
} playerInfo;

typedef struct Team
{
    char *teamName;
    int numberOfPlayers;
    float teamPoints;
    playerInfo *player;
} teamInfo;

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

struct N
{
    teamInfo val;
    struct N *left, *right;
};
typedef struct N BST;

struct a
{
    int height;
    teamInfo val;
    struct a *left, *right;
};

typedef struct a AVL;