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

void delete_last()
{
    struct node *p;
    struct node *q;
    p = HEAD;
    q = HEAD->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL; // Also we can write (p->next = q->next;)
    q->prev = NULL; //(p->next = q->prev = NULL;)
    free(q);
}

// void delete_last()
// {
//     if (HEAD == NULL)
//     {
//         printf("List is empty so we cant delete any Node\n");
//     }
//     else
//     {
//         struct node *p;
//         struct node *q;
//         p = HEAD;
//         q = HEAD->next;
//         while (q->next != NULL)
//         {
//             p = p->next;
//             q = q->next;
//         }
//         p->next = NULL;
//         q->prev = NULL;
//         free(q);
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
    delete_last();
    dis();

    printf("\n");
    delete_last();
    dis();

    printf("\n");
    delete_last();
    dis();

}
