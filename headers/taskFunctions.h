void fileOpenVerification(FILE *);
void fileDeclarations(FILE *, FILE *, FILE *, char **);
void taskInit(FILE *, int *);

int numberOfTeams(FILE *, int);

playerInfo *allocatePlayers(int);

teamInfo fileReadTeam(FILE *, teamInfo);
teamInfo fileReadPlayer(FILE *, teamInfo, int);

void task1(FILE *, FILE *, Node **, int);
void printNameOfTeams(FILE *, Node *);

int NumberRemaningTeams(int);

void descending_sort(float *, int);
int float_equal(float, float);

void task2(Node **, int, FILE *);

Node *task3(Node *, FILE *, int);

void printGames(Queue **, FILE *, int, int, Node **, Node **);
int VersusWinner(teamInfo, teamInfo);

Tree *task4(Node *, FILE *);
