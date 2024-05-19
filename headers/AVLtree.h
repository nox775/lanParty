int max(int a, int b);

int nodeHeight(AVL_tree *);

AVL_tree *RightRotation(AVL_tree *);
AVL_tree *LeftRotation(AVL_tree *);
AVL_tree *LRRotation(AVL_tree *);
AVL_tree *RLRotation(AVL_tree *);

int compareKeys(teamInfo, teamInfo);
AVL_tree *insertAVL(AVL_tree *, teamInfo);
void printAVL_treeLVL2(AVL_tree *, FILE *, int);