#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

bool IsBSTUtil(struct node *root, struct node **pre)
{
    // Base case
    if (root == NULL)
        return true;

    // Check the left subtree
    if (!IsBSTUtil(root->left, pre))
        return false;

    // Check the current node
    if (*pre != NULL && root->data <= (*pre)->data)
        return false;

    // Update the previous node to the current node
    *pre = root;

    // Check the right subtree
    return IsBSTUtil(root->right, pre);
}

bool IsBST(struct node *root)
{
    struct node *prev = NULL;
    return IsBSTUtil(root, &prev);
}

int main() {
    struct node* s;

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    if (IsBST(s))
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}
