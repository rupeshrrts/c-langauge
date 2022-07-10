
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

void delete ()
{
    struct node *temp;
    int loc;
    printf("\n\nEnter the loc to delete :\n");
    scanf("%d",&loc);
    if (loc<1||loc>length())
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
        int i=1; //if we initialize i=1, other-wise default value of i will be 0;
        while (i!=loc-1)
        {
           p=p->next;
           q=q->next;
           i++;
        }
        p->next=q->next;
        q->next->prev=q->prev;
        free(q);
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
    e(37);
    e(42);
    e(59);
    e(64);
    e(76);
    e(82);
    e(97);
    e(13);
    e(12);
    e(18);
    e(19);
    e(21);
    e(34);

    printf("\n");
    printf("\n");
    dis();

    delete ();
    dis();

    delete ();
    dis();
}

