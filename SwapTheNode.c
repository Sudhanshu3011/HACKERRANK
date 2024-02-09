#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *tail = NULL;

struct node *createnode(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct node *new(int data, struct node *head)
{
    if (head == NULL)
    {
        head = createnode(data);
        tail = head;
    }
    else
    {
        struct node *ptr = createnode(data);
        tail->next = ptr;
        tail = ptr;
    }
    return head;
}

struct node *swapthenode(int x, int y, struct node *head)
{
    if (x == y || head == NULL)
        return head;

    struct node *x_previous = NULL;
    struct node *y_previous = NULL;
    struct node *x_node = head;
    struct node *y_node = head;
    struct node *temp = head;

    for (int i = 1; i < x && x_node != NULL; i++)
    {
        x_previous = x_node;
        x_node = x_node->next;
    }

    for (int i = 1; i < y && y_node != NULL; i++)
    {
        y_previous = y_node;
        y_node = y_node->next;
    }

    if (x_node == NULL || y_node == NULL)
        return head;

    if (x_previous != NULL)
    {

        x_previous->next = y_node;
    }
    else
    {

        head = y_node;
    }

    if (y_previous != NULL)
    {
        y_previous->next = x_node;
    }
    else
    {
        head = x_node;
    }

    
    struct node *temp_next = x_node->next;
    x_node->next = y_node->next;
    y_node->next = temp_next;

    return head;
}

void traversal(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *head = NULL;

    head = new (1, head);
    head = new (2, head);
    head = new (3, head);
    head = new (4, head);
    head = new (5, head);
    head = new (7, head);
    head = new (8, head);
    head = new (9, head);

    printf("Original Linked List: ");
    traversal(head);

    head = swapthenode(3, 5, head);

    printf("Linked List after swapping nodes 3 and 5: ");
    traversal(head);

    return 0;
}
