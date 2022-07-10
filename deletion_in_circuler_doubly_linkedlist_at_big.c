

// #include <stdio.h>
// #include <stdlib.h>
// struct node
// {
//     struct node *prev;
//     int data;
//     struct node *next;
// };

// struct node *HEAD = NULL;

// void insertAtend(int data)
// {
//     struct node *temp = HEAD;
//     struct node *newNode = (struct node *)malloc(sizeof(struct node));
//     newNode->prev = NULL;
//     newNode->data = data;
//     newNode->next = NULL;

//     if (HEAD == NULL)
//     {

//         HEAD = newNode;
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
//         temp = newNode;
//     }
// }

// void deletefirst()
// {
//     struct node *temp = HEAD;
//     if (temp->next == temp)
//     {
//         HEAD = NULL; // this line is optional
//         free(temp);
//     }
//     else
//     {
//         while (temp->next != HEAD)
//         {
//             temp = temp->next;
//         }
//         temp->next = HEAD->next;
//         HEAD->prev=temp;
//         HEAD = NULL;
//         free(HEAD);
//         HEAD = temp->next;
//     }
// }

// void dis()
// {
//     struct node *temp = HEAD;
//     do
//     {
//         printf("%d  ", temp->data);
//         temp = temp->next;
//     } while (temp != HEAD);
// }

// int main()
// {
//     insertAtend(15);
//     insertAtend(20);
//     insertAtend(25);
//     insertAtend(35);
//     insertAtend(80);
//     insertAtend(60);
//     printf("\nDisplay circuler node before deletion data:\n");
//     dis();
//     deletefirst();
//     printf("\n\nDisplay circuler node after deletion data:\n");
//     dis();
// }

#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *HEAD = NULL;

void insertAtend()
{
    struct node *temp = HEAD;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->prev = NULL;
    printf("Enetr the data :\n");
    scanf("%d", &newNode->data);
    // newNode->data = data;
    newNode->next = NULL;

    if (HEAD == NULL)
    {

        HEAD = newNode;
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
        temp = newNode;
    }
}

void deletefirst()
{
    struct node *temp = HEAD;
    if (temp->next == temp)
    {
        HEAD = NULL; // this line is optional
        free(temp);
    }
    else
    {
        while (temp->next != HEAD)
        {
            temp = temp->next;
        }
        temp->next = HEAD->next;
        HEAD->prev = temp;
        HEAD = NULL;
        free(HEAD);
        HEAD = temp->next;
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
    insertAtend();
    insertAtend();
    insertAtend();
    insertAtend();
    insertAtend();
    insertAtend();
    printf("\nDisplay circuler node before deletion data:\n");
    dis();
    deletefirst();
    printf("\n\nDisplay circuler node after deletion data:\n");
    dis();
    deletefirst();
    printf("\n\nDisplay circuler node after deletion data:\n");
    dis();
}