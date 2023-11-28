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

int searchitr1(struct node *root, int key)
{
    while (root != NULL)
    {
        
        if (root->data == key)
        {
            return 1;
        }
        else if (root->data < key)
        {
            //redirecting the new root to the right of root.
           root = root->right;
        }
        else
        {
            //redirecting the new root to the 
            root = root->left;
        }
    }
    return 0;
}

struct node *searchitr(struct node *root, int key)
{
    while (root != NULL)
    {
        
        if (root->data == key)
        {
            return root;
        }
        else if (root->data < key)
        {
            //redirecting the new root to the right of root.
           root = root->right;
        }
        else
        {
            //redirecting the new root to the 
            root = root->left;
        }
    }
    return NULL;
}
struct node *lca(struct node *root, int v1, int v2) {
    struct node* temp;
    struct node* maxNode = NULL;  // To store the highest valued temp node
    int a,b;
    if(v1>v2)
    {
        a=v1;
        b=v2;
    }
    else {
        a=v2;
        b=v1;    
    }
    
    for(int i = b ; i <= a; i++) {
        temp = searchitr(root, i);
        if(searchitr1(temp, v1) == 1 && searchitr1(temp, v2) == 1) {
            // Check if temp is greater than the current maxNode
            if (maxNode == NULL || temp->data > maxNode->data) {
                maxNode = temp;
            }
        }
    }
    
    return maxNode;  // Return the highest valued temp node
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
  	int v1;
  	int v2;
  
  	scanf("%d%d", &v1, &v2);
	struct node *ans = lca(root, v1, v2);
  	printf("%d", ans->data);
  	
    return 0;
}
