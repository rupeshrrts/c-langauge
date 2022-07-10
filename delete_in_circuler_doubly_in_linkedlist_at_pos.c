#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *HEAD = NULL;

void insertAtend(int data)
{
    struct node *temp=HEAD;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;

    if (HEAD == NULL)
    {

        HEAD  = newNode;
        newNode->next = HEAD;
        newNode->prev = HEAD;
    }
    else
    {
        while (temp->next != HEAD)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = HEAD;
        HEAD->prev = newNode;
        temp= newNode;
    }
}


int length()
{
    struct node *temp = HEAD;
    int count = 1;
    while (temp->next != HEAD)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void delete_at_pos()
{
    struct node *temp;
    int loc;
    printf("\n\nEnter the loc to delete :\n");
    scanf("%d",&loc);
    if (loc>length())
    {
        printf("Invalid location\n");
        printf("Only you can eneter between 0-%d\n",length());
    }
    else
    {
        struct node *p;
        struct node *q;
        p=HEAD;
        q=HEAD->next;
        int i=1; 
        while (i<loc-1)
        {
           p=p->next;
           q=q->next;
           i++;
        }
        p->next=q->next;
        p->next->prev=temp->prev;
        q->next=NULL; // this line is optional
        free(q);
    }
}


void dis()
{
    struct node *temp = HEAD;
    do
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    } while (temp != HEAD);
}


int main()
{
    insertAtend(15);
    insertAtend(20);
    insertAtend(25);
    insertAtend(30);
    insertAtend(80);
    insertAtend(60);
    insertAtend(95);
    insertAtend(51);
    insertAtend(12);
    insertAtend(54);
    insertAtend(74);
    printf("Length is :%d\n",length());
    printf("Display circuler node before deletion data:\n");
    dis();
    delete_at_pos();
    printf("\nDisplay circuler node after deletion data:\n");
    dis();
    delete_at_pos();
    printf("\nDisplay circuler node after deletion data:\n");
    dis();
}
