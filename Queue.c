#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_SIZE 10000

// Structure to represent a stack
struct Stack
{
    long items[MAX_SIZE];
    int top;
};

struct Queue
{
    long items[MAX_SIZE];
    int front;
    int rear;
};

// Function to initialize an empty stack
void initialize(struct Stack *stack)
{
    stack->top = -1;
}

void initializeQ(struct Queue *Queue)
{
    Queue->front = Queue->rear = 0;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

int isEmptyQ(struct Queue *Queue)
{
    // if(Queue->front == Queue->rear){
    //     //
    //     return 0;
    // }
    // else return 1;
    return Queue->front == Queue->rear;
}

// Function to push an element onto the stack
void push(struct Stack *stack, long value)
{
    if (stack->top == MAX_SIZE - 1)
    {
        printf("Stack overflow\n");
        return;
    }

    stack->items[++stack->top] = value;
}
long pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow\n");
        return LONG_MIN;
    }

    return stack->items[stack->top--];
}

// Enqueue
void EnqueueQ(struct Queue *Queue, long value)
{
    if (Queue->front == Queue->rear && Queue->front == 0)
    {
        Queue->front++;
        Queue->rear++;
        Queue->items[Queue->rear] = value;
    }
    else
    {
        Queue->rear++;
        Queue->items[Queue->rear] = value;
    }
}

void DequeueQ(struct Queue *Queue)
{
    if (isEmptyQ(Queue))
    {
        Queue->front++;
    }
}

void FirstinQ(struct Queue *Queue)
{
    printf("%ld\n", Queue->items[Queue->front]);
}

void Enqueuecall(struct Stack *stackdn, struct Queue *Queue)
{
    while (!isEmpty(stackdn))
    {
        long x = pop(stackdn);
        EnqueueQ(Queue, x);
    }
}

void Transfer(struct Stack *stacken, struct Stack *stackdn)
{
    while (!isEmpty(stacken))
    {
        long x = pop(stacken);
        push(stackdn, x);
    }
}

void insert(struct Stack *stack, long value)
{
    push(stack, value);
}

int main()
{
    int a, n;
    struct Stack stacken; // Declare a struct Stack, not a pointer
    struct Stack stackde; // Declare a struct Stack, not a pointer
    struct Queue Queue;

    initialize(&stacken);
    initialize(&stackde);
    initializeQ(&Queue);

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        long num;
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            // int num;
            scanf("%ld", &num);
            insert(&stacken, num);
            break;

        case 2:
            Transfer(&stacken, &stackde);
            Enqueuecall(&stackde, &Queue);
            DequeueQ(&Queue);
            break;

        case 3:
            Transfer(&stacken, &stackde);
            Enqueuecall(&stackde, &Queue);
            FirstinQ(&Queue);
            break;
        }
    }

    return 0;
}
