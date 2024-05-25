int max(int a, int b);

int nodeHeight(AVL *);

AVL *RightRotation(AVL *);
AVL *LeftRotation(AVL *);
AVL *LRRotation(AVL *);
AVL *RLRotation(AVL *);

int compareKeys(teamInfo, teamInfo);
AVL *insertAVL(AVL *, teamInfo);
void printAVL_LVL2(AVL *root, FILE *fout);