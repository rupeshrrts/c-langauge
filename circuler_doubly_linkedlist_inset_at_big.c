
//insertion at big in circuler doubly linkedlist

#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *HEAD = NULL;

void insertAtbig(int data)
{
    struct node *temp;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;

    if (HEAD == NULL)
    {
        HEAD  = newNode;
        newNode->next = HEAD;
        newNode->prev = HEAD; //newNode->prev = temp; also
    }
    else
    {
        temp=HEAD;
        while (temp->next != HEAD)
        {
            temp = temp->next;
        }
        newNode->next=HEAD;
        HEAD->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
        HEAD= newNode;
    }
}

void dis()
{
    struct node *temp = HEAD;
    printf("Display circuler node data:\n");
    do
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    } while (temp != HEAD);
}


int main()
{
    insertAtbig(50);
    insertAtbig(20);
    insertAtbig(25);
    insertAtbig(20);
    insertAtbig(80);
    insertAtbig(60);
    dis();
}


// #include <stdio.h>
// #include <stdlib.h>
// struct node
// {
//     struct node *prev;
//     int data;
//     struct node *next;
// };

// struct node *HEAD = NULL;

// void insertAtbig()
// {
//     struct node *temp;
//     struct node *newNode = (struct node *)malloc(sizeof(struct node));
//     newNode->prev = NULL;
//     printf("Enter the data :\n");
//     scanf("%d",&newNode->data);
//     newNode->next = NULL;

//     if (HEAD == NULL)
//     {
//         HEAD  = newNode;
//         newNode->next = HEAD;
//         newNode->prev = HEAD; //newNode->prev = temp; also
//     }
//     else
//     {
//         temp=HEAD;
//         while (temp->next != HEAD)
//         {
//             temp = temp->next;
//         }
//         newNode->next=HEAD;
//         HEAD->prev = newNode;
//         temp->next = newNode;
//         newNode->prev = temp;
//         HEAD= newNode;
//     }
// }

// void dis()
// {
//     struct node *temp = HEAD;
//     printf("Display circuler node data:\n");
//     do
//     {
//         printf("%d  ", temp->data);
//         temp = temp->next;
//     } while (temp != HEAD);
// }

// int main()
// {
//     insertAtbig();
//     insertAtbig();
//     insertAtbig();
//     insertAtbig();
//     insertAtbig();
//     insertAtbig();
//     dis();
// }

