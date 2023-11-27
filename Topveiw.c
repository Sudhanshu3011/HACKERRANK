// Incorrect approach still work reqired 

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        struct node* node = (struct node*)malloc(sizeof(struct node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return node;
    } else {
        struct node* cur;
        if (data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
        } else {
            cur = insert(root->right, data);
            root->right = cur;
        }
        return root;
    }
}

struct stack {
    int size;
    int top;
    int *arr;
};

struct queue {
    int front;
    int back;
    int size;
    int *arr;
};

// Initialize stack
struct stack* createStack(int size) {
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size = size;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    return s;
}

// Initialize queue
struct queue* createQueue(int size) {
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->front = -1;
    q->back = -1;
    q->size = size;
    q->arr = (int *)malloc(q->size * sizeof(int));
    return q;
}

//emputy function
int isempty(struct queue *q) {
    return (q->back == q->front);
}

//full function
int isfull(struct queue *q) {
    return (q->back == q->size - 1);
}

//enqueue function
void enqueue(struct queue *q, int val) {
    if (!isfull(q)) {
        q->back++;
        q->arr[q->back] = val;
    }
}

//dequeue function
int dequeue(struct queue *q) {
    int a;
    if (!isempty(q)) {
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}

// function that check the stack is full.
int empty(struct stack *ptr) {
    return (ptr->top == -1);
}

// pushing an elememt is a stack.
void push(struct stack *ptr, int value) {
    if (!empty(ptr)) {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

// poping an element in the stack
int pop(struct stack *ptr) {
    int value = -1;
    if (!empty(ptr)) {
        value = ptr->arr[ptr->top];
        ptr->top--;
    }
    return value;
}

void freeMemory(struct node* root, struct stack* s, struct queue* q) {
    if (root == NULL) {
        return;
    }
    freeMemory(root->left, s, q);
    freeMemory(root->right, s, q);
    free(root);
    free(s->arr);
    free(q->arr);
    free(s);
    free(q);
}

void topView(struct node *root) {
    if (root == NULL)
        return;

    struct stack *s = createStack(100);
    struct queue *q = createQueue(100);

    while (root->left != NULL) {
        push(s, root->left->data);
        root = root->left;
    }

    while (!empty(s)) {
        printf("%d ", pop(s));
    }

    printf("%d ", root->data);

    while (root->right != NULL) {
        enqueue(q, root->right->data);
        root = root->right;
    }

    while (!isempty(q)) {
        printf("%d ", dequeue(q));
    }

    // Free allocated memory
    freeMemory(root, s, q);
}

int main() {
    struct node* root = NULL;
    
    int t;
    int data;

    scanf("%d", &t);

    while (t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    topView(root);

    return 0;
}
