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
//     struct node *temp = HEAD;
//     struct node *newNode = (struct node *)malloc(sizeof(struct node));
//     newNode->prev = NULL;
//     printf("Enetr the data :\n");
//     scanf("%d", &newNode->data);
    
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

// void last_delete()
// {
//     struct node *p = HEAD;
//     struct node *q= HEAD->next;

//     if (p->next == p)
//     {
//         HEAD = NULL;
//         free(p);
//     }
//     else
//     {
//         while (q->next != HEAD)
//         {
//             p = p->next;
//             q = q->next;
//         }
//         p->next = HEAD; // p->next = q->next;
//         HEAD->prev= p;
//         free(q);
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
//     insertAtend();
//     insertAtend();
//     insertAtend();
//     insertAtend();
//     insertAtend();
//     insertAtend();
//     printf("\nDisplay circuler node before deletion data:\n");
//     dis();
//     last_delete();
//     printf("\n\nDisplay circuler node after deletion data:\n");
//     dis();
//     last_delete();
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

void insertAtend(int data)
{
    struct node *temp = HEAD;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->prev = NULL;
    // printf("Enetr the data :\n");
    // scanf("%d", &newNode->data);
    newNode->data = data;
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

void last_delete()
{
    struct node *p = HEAD;
    struct node *q= HEAD->next;

    if (p->next == p)
    {
        HEAD = NULL;
        free(p);
    }
    else
    {
        while (q->next != HEAD)
        {
            p = p->next;
            q = q->next;
        }
        p->next = HEAD; // p->next = q->next;
        HEAD->prev= p;
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
    insertAtend(4);
    insertAtend(5);
    insertAtend(6);
    insertAtend(7);
    insertAtend(8);
    insertAtend(9);
    printf("\nDisplay circuler node before deletion data:\n");
    dis();
    last_delete();
    printf("\n\nDisplay circuler node after deletion data:\n");
    dis();
    last_delete();
    printf("\n\nDisplay circuler node after deletion data:\n");
    dis();
}
