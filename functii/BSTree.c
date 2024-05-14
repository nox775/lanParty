#include "../main.h"
#include "../headers/taskFunctions.h"
#include "../headers/liste.h"
#include "../headers/stack.h"
#include "../headers/queue.h"
#include "../headers/BSTree.h"

Tree *newNode(teamInfo team)
{
    Tree *node = (Tree *)malloc(sizeof(Tree));
    node->val = team;
    node->left = node->right = NULL;
    return node;
}

Tree *insertTree(Tree *node, teamInfo team)
{
    if (node == NULL)
        return newNode(team);

    if (float_equal(team.teamPoints, node->val.teamPoints))
    {
        // compara string-urile in caz de egalitate de puncte
        if (strcmp(team.teamName, node->val.teamName) < 0)
            node->left = insertTree(node->left, team);
        else
            node->right = insertTree(node->right, team);
    }
    else if (team.teamPoints < node->val.teamPoints)
        node->left = insertTree(node->left, team);
    else if (team.teamPoints > node->val.teamPoints)
        node->right = insertTree(node->right, team);

    return node;
}

void printTree(Tree *root, FILE *fout)
{
    // Afiseaza in fiser echipele din BST
    if (root)
    {
        printTree(root->right, fout);

        fprintf(fout, "%-32s  -  %.2f\n", root->val.teamName, root->val.teamPoints);
        printTree(root->left, fout);
    }
}
