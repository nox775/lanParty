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
void descending_sort(float *, int);
void lastTeamPoints(Node *, int, float *);
int float_equal(float, float);
void task2(Node **, int, FILE *);