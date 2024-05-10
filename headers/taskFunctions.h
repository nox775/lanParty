void fileOpenVerification(FILE *);
void fileDeclarations(FILE *, FILE *, FILE *, char **);
void taskInit(FILE *, int *);

int numberOfTeams(FILE *, int);

teamInfo fileReadTeam(FILE *, teamInfo);
teamInfo fileReadPlayer(FILE *, teamInfo, int);

void task1(FILE *, FILE *, Node **, int);
void printNameOfTeams(FILE *, Node *);

void totalTeamPoints(Node *);
int NumberRemaningTeams(int);
void lastTeamPoints(Node *, int, float *);

void descending_sort(float *, int);
int float_equal(float, float);

void task2(Node **, int, FILE *);

void task3(Node *, FILE *, Queue **, int);
void makeGames(Queue **, Node *);
void printGames(Queue *, FILE *, int);