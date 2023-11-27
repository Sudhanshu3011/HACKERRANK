#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

void preOrder( struct node *root) {
  
	if( root == NULL ) 
      return;
	printf("%d ",root->data);
	preOrder(root->left);
	preOrder(root->right);
  
}

/* you only have to complete the function given below.  
node is defined as  

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

*/
struct node *createnode(int data)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node)); 
    new->data = data;
    new->left = NULL;                                 
    new->right = NULL;                                
    return new;
}
struct node* insert(struct node* root, int data) {
    struct node* prev = NULL;
    struct node* temp = root;  // Store the original root
    
    if(root==NULL)
    {
         root = createnode(data);
        return root;
    }
    while (temp != NULL) {
        prev = temp;
        if (data == temp->data) {
            return root;  // Node already exists, return the original root
        } else if (data < temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    struct node* ins = createnode(data);
    if (data < prev->data) {
        prev->left = ins;
    } else {
        prev->right = ins;
    }

    return root;  // Return the updated root of the tree
}


int main() {
  
    struct node* root = NULL;
    
    int t;
    int data;

    scanf("%d", &t);

    while(t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }
  
	preOrder(root);
    return 0;
}
