#include "../main.h"
#include "../headers/taskFunctions.h"
#include "../headers/liste.h"
#include "../headers/stack.h"
#include "../headers/queue.h"
#include "../headers/AVLtree.h"

int max(int a, int b)
{
    return ((a > b) ? a : b);
}

int nodeHeight(AVL *root)
{
    if (root == NULL)
        return -1;
    return root->height;
}

AVL *RightRotation(AVL *z)
{
    AVL *y = z->left;
    AVL *T3 = y->right;

    y->right = z;
    z->left = T3;

    z->height = max(nodeHeight(z->left), nodeHeight(z->right)) + 1;
    y->height = max(nodeHeight(y->left), nodeHeight(y->right)) + 1;

    return y;
}

AVL *LeftRotation(AVL *z)
{
    AVL *y = z->right;
    AVL *T2 = y->left;

    y->left = z;
    z->right = T2;

    z->height = max(nodeHeight(z->left), nodeHeight(z->right)) + 1;
    y->height = max(nodeHeight(y->left), nodeHeight(y->right)) + 1;

    return y;
}

AVL *LRRotation(AVL *Z)
{
    Z->left = LeftRotation(Z->left);
    return RightRotation(Z);
}

AVL *RLRotation(AVL *Z)
{
    Z->right = RightRotation(Z->right);
    return LeftRotation(Z);
}

int compareKeys(teamInfo key1, teamInfo key2)
{
    if (float_equal(key1.teamPoints, key2.teamPoints))
    {
        if (strcmp(key1.teamName, key2.teamName) < 0)
            return 1;
        else
            return -1;
    }
    else if (key1.teamPoints > key2.teamPoints)
        return -1;
    else if (key1.teamPoints < key2.teamPoints)
        return 1;
}

AVL *insertAVL(AVL *node, teamInfo key)
{
    if (node == NULL)
    {
        node = (AVL *)malloc(sizeof(AVL));
        node->val = key;
        node->height = 0;
        node->left = node->right = NULL;
        return node;
    }

    int cmp = compareKeys(key, node->val);
    if (cmp < 0)
    {
        node->left = insertAVL(node->left, key);
    }
    else if (cmp > 0)
    {
        node->right = insertAVL(node->right, key);
    }
    else
        return node;

    node->height = 1 + max(nodeHeight(node->left), nodeHeight(node->right));

    int balance = (nodeHeight(node->left)) - (nodeHeight(node->right));

    if (balance > 1 && compareKeys(key, node->left->val) < 0)
        return RightRotation(node);

    if (balance < -1 && compareKeys(key, node->right->val) > 0)
        return LeftRotation(node);

    if (balance > 1 && compareKeys(key, node->left->val) > 0)
        return LRRotation(node);

    if (balance < -1 && compareKeys(key, node->right->val) < 0)
        return RLRotation(node);

    return node;
}

void printAVL_LVL2(AVL *root, FILE *fout)
{
    if (root)
    {
        if (root->left)
        {
            if (root->left->left)
                fprintf(fout, "%s\n", root->left->left->val.teamName);
            if (root->left->right)
                fprintf(fout, "%s\n", root->left->right->val.teamName);
        }
        if (root->right)
        {
            if (root->right->left)
                fprintf(fout, "%s\n", root->right->left->val.teamName);
            if (root->right->right)
                fprintf(fout, "%s\n", root->right->right->val.teamName);
        }
    }
}