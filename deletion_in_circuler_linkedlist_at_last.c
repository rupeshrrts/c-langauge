#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;
void last(int data)
{

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    struct node *temp = head; 
    if (head == NULL)
    {
        head = temp = newNode;
        newNode->next = head;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void last_delete()
{
    struct node *p = head;
    struct node *q= head->next;

    if (p->next == p)
    {
        head = NULL;
        free(p);
    }
    else
    {
        while (q->next != head)
        {
            p = p->next;
            q = q->next;
        }
        p->next = head;
        free(q);
    }
}

void dis()
{
    struct node *temp = head;
    do
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main()
{
    last(15);
    last(20);
    last(25);
    last(30);
    last(35);
    last(40);
    last(45);
    printf("Display circuler node data before deletion:\n");
    dis();
    printf("\n\n");

    printf("Display circuler node data after deletion:\n");
    last_delete();
    dis();
    printf("\n\n");

    last_delete();
    dis();
    printf("\n\n");

    last_delete();
    dis();
}
