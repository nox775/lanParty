#include "../main.h"
#include "../headers/taskFunctions.h"
#include "../headers/liste.h"
#include "../headers/stack.h"
#include "../headers/queue.h"
#include "../headers/AVLtree.h"

int max(int a, int b)
{
    if (a > b)
        return 1;
    else
        return 0;
}

int nodeHeight(AVL_tree *root)
{
    if (root == NULL)
        return -1;
    else
        return root->height;
}

AVL_tree *RightRotation(AVL_tree *z)
{
    AVL_tree *y = z->left;
    AVL_tree *T3 = y->right;

    z->height = max(nodeHeight(z->left), nodeHeight(z->right)) + 1;
    y->height = max(nodeHeight(y->left), nodeHeight(y->right)) + 1;

    return y;
}

AVL_tree *LeftRotation(AVL_tree *z)
{
    AVL_tree *y = z->right;
    AVL_tree *T2 = y->left;
    y->left = z;
    z->right = T2;
    z->height = max(nodeHeight(z->left),
                    nodeHeight(z->right)) +
                1;
    y->height = max(nodeHeight(y->left),
                    nodeHeight(y->right)) +
                1;
    return y;
}

AVL_tree *LRRotation(AVL_tree *Z)
{
    Z->left = LeftRotation(Z->left);
    return RightRotation(Z);
}
AVL_tree *RLRotation(AVL_tree *Z)
{
    Z->right = RightRotation(Z->right);
    return LeftRotation(Z);
}

int compareKeys(teamInfo key1, teamInfo key2)
{
    if (float_equal(key1.teamPoints, key2.teamPoints))
        return strcmp(key1.teamName, key2.teamName);
    return (key1.teamPoints < key2.teamPoints) ? -1 : 1;
}

AVL_tree *insertAVL(AVL_tree *node, teamInfo key)
{
    if (node == NULL)
    {
        node = (AVL_tree *)malloc(sizeof(AVL_tree));
        node->val = key;
        node->height = 0;
        node->left = node->right = NULL;
        return node;
    }

    int cmp = compareKeys(key, node->val);
    if (cmp > 0)
    {
        node->left = insertAVL(node->left, key);
    }
    else if (cmp < 0)
    {
        node->right = insertAVL(node->right, key);
    }

    node->height = 1 + max(nodeHeight(node->left), nodeHeight(node->right));

    int balance = nodeHeight(node->left) - nodeHeight(node->right);

    if (balance > 1 && compareKeys(key, node->left->val) < 0)
    {
        return RightRotation(node);
    }

    if (balance < -1 && compareKeys(key, node->right->val) > 0)
    {
        return LeftRotation(node);
    }

    if (balance > 1 && compareKeys(key, node->left->val) > 0)
    {
        return LRRotation(node);
    }

    if (balance < -1 && compareKeys(key, node->right->val) < 0)
    {
        return RLRotation(node);
    }

    return node;
}

void printAVL_treeLVL2(AVL_tree *root, FILE *fout)
{

    if (root)
    {
        printAVL_treeLVL2(root->right, fout);

        //  if (root->height == 2)
        fprintf(fout, "%s\n", root->val.teamName);

        printAVL_treeLVL2(root->left, fout);
    }
}