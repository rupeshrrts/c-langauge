
#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *HEAD = NULL;

void end(int data)
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
void deletefirst()
{
    struct node *temp=HEAD;
    HEAD = HEAD->next;
    HEAD->prev = NULL; // also we can write (HEAD->next->prev = NULL;)
    free(temp);     // we can also write (temp->next=NULL;)
}

// void deletefirst()
// {
//     struct node *temp;
//     if (HEAD == NULL)
//     {
//         printf("List is empty\n");
//     }
//     else
//     {
//         temp = HEAD;
//         HEAD = HEAD->next;
//         HEAD->prev = NULL;// also we can write (HEAD->next->prev = NULL;)
//         free(temp); // we can also write (temp->next=NULL;)
//     }
// }

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
    end(35);
    end(49);
    end(57);
    end(64);
    end(31);
    end(45);
    end(54);
    end(62);
    dis();
    printf("\n");
    deletefirst();
    dis();
    printf("\n");
    deletefirst();
    dis();
    printf("\n");
    deletefirst();
    dis();
}