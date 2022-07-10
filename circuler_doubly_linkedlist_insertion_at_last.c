
// //circuler double linked list insertion at end

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
    insertAtend(50);
    insertAtend(20);
    insertAtend(25);
    insertAtend(20);
    insertAtend(80);
    insertAtend(60);
    dis();
}


// //double linked list insertion at end
// #include <stdio.h>
// #include <stdlib.h>
// struct node
// {
//     struct node *prev;
//     int data;
//     struct node *next;
// };

// struct node *HEAD = NULL;
// void insertAtend()
// {
//     struct node *temp=HEAD;
//     struct node *newNode = (struct node *)malloc(sizeof(struct node));
//     printf("Enter the data :\n");
//     scanf("%d",&newNode->data);
//     newNode->prev = NULL;
//     newNode->next = NULL;

//     if (HEAD == NULL)
//     {
//         HEAD  = newNode;
//         newNode->next = HEAD;
//         newNode->prev = HEAD;
//     }
//     else
//     {
//         while (temp->next != HEAD)
//         {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//         newNode->prev = temp;
//         newNode->next = HEAD;
//         HEAD->prev = newNode;
//         temp= newNode;
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
//     insertAtend();
//     insertAtend();
//     insertAtend();
//     insertAtend();
//     insertAtend();
//     insertAtend();
//     dis();
// }

