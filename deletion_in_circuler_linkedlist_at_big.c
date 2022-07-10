
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
    struct node *temp = head; // we can also write (struct node*temp=head->next;)
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
        temp = temp->next; // this line is optional
        // temp->link = newNode;
        // newNode->link = HEAD;
        // temp=newNode;// this line is optional
    }
}

void beg_delete()
{
    struct node *temp = head;
    if (temp->next == temp)
    {
        head = NULL; //this line is optional
        free(temp);
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        // head=NULL; // this line is also optional
        free(head);
        head = temp->next;   
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
    
    printf("Display circuler linkedlist before deletion :\n");
    dis();
    printf("\n\n");

    beg_delete();
    printf("Display circuler linkedlist after deletion :\n");
    dis();
    printf("\n\n");

    beg_delete();
    printf("Display circuler linkedlist after deletion :\n");
    dis();
    printf("\n\n");

    beg_delete();
    printf("Display circuler linkedlist after deletion :\n");
    dis();
}
