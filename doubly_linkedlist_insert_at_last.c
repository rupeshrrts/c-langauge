#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *HEAD = NULL;

void insert(int data)
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

void dis()
{
    printf("\nDisplay the all inserted data\n");
    struct node *temp = HEAD;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}


int main()
{
    insert(5);
    insert(10);
    insert(15);
    insert(20);
    insert(80);
    insert(60);
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

// void insert()
// {
//     struct node *temp = HEAD;
//     struct node *newNode = (struct node *)malloc(sizeof(struct node));
//     printf("Enter the node data :\n");
//     scanf("%d",&newNode->data);
//     newNode->prev = NULL;
//     newNode->next = NULL;
//     if (HEAD == NULL)
//     {
//         HEAD = newNode;
//     }
//     else
//     {
//         while (temp->next != NULL)
//         {
//             temp = temp->next;
//         }
//         newNode->prev = temp;
//         temp->next = newNode;
//         temp = newNode;
//     }
// }

// void dis()
// {
//     printf("\nDisplay the all inserted data\n");
//     struct node *temp = HEAD;
//     while (temp != NULL)
//     {
//         printf("%d\n", temp->data);
//         temp = temp->next;
//     }
// }


// int main()
// {
//     insert();
//     insert();
//     insert();
//     insert();
//     insert();
//     insert();
//     dis();
// }
