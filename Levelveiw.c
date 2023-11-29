#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

struct node* insert( struct node* root, int data ) {
		
	if(root == NULL) {
	
        struct node* node = (struct node*)malloc(sizeof(struct node));

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;
	  
	} else {
      
		struct node* cur;
		
		if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
		} else {
            cur = insert(root->right, data);
            root->right = cur;
		}
	
		return root;
	}
}

/* you only have to complete the function given below.  
node is defined as  

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

*/

// Function to find the height of the tree
int height(struct node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to print the top view of the binary tree
void printTopViewUtil(struct node* root, int level, int hd) {
    if (root == NULL)
        return;

    // Print the node if it is the first node at the current horizontal distance and level
    if (level == 1) {
        printf("%d ", root->data);
    }

    // Recur for the left and right subtrees
    printTopViewUtil(root->left, level - 1, hd - 1);
    printTopViewUtil(root->right, level - 1, hd + 1);
}

// Function to print the top view of the binary tree
void levelOrder(struct node* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printTopViewUtil(root, i, 0);
    }
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
  
	levelOrder(root);
    return 0;
}
