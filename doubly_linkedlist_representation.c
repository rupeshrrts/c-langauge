#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *previous;
};

void display(struct Node *Node1)
{
    struct Node *temp = Node1;
    printf("display node data : \n");
    while (temp != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
}
int main()
{

    struct Node *Node1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *Node2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *Node3 = (struct Node *)malloc(sizeof(struct Node));

    Node1->data = 10;
    Node1->next = Node2;
    Node1->previous = NULL;

    Node2->data = 20;
    Node2->next = Node3;
    Node2->previous = Node1;

    Node3->data = 30;
    Node3->next = NULL;
    Node3->previous = Node2;
    display(Node1);
    return 0;
}
