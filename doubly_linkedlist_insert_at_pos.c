
#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *HEAD = NULL;

void e(int data)
{
    struct node *temp = HEAD;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;
    if (HEAD == NULL)
    {
        HEAD = newNode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newNode->prev = temp;
        temp->next = newNode;
        temp = newNode;
    }
}

int length()
{
    struct node *temp = HEAD;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void addatafter()
{
    int pos, i=1;
    struct node *temp = HEAD;
    printf("\n\nIf you want  to add a node in the list -\n");
    printf("Please Enter the possition :\n");
    scanf("%d", &pos);
    if (pos > length())
    {
        printf("Invalid position\n");
        printf("list contain only %d Nodes\n", length());
    }
    else
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the Node data :\n");
        scanf("%d", &newNode->data);
        newNode->prev = NULL;
        newNode->next = NULL;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }

        newNode->next = temp->next;
        temp->next->prev = newNode;
        newNode->prev=temp;
        temp->next=newNode;
    }
}

void dis()
{
    printf("\n");
    struct node *temp = HEAD;
    printf("Dispaly nodes data :\n");
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    e(3);
    e(4);
    e(5);
    e(6);
    e(7);
    e(8);
    e(9);
    e(11);
    e(12);
    e(14);
    printf("\n");
    printf("\n");
    dis();

    addatafter();
    dis();

    addatafter();
    dis();
}