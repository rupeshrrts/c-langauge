
// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     struct node *next;
// };

// void dis(struct node *head)
// {
//     struct node *temp = head;
//     while (temp != NULL)
//     {
//         printf(" %d \n", temp->data);
//         temp = temp->next;
//     }
// }

// struct node *delete_at_last(struct node *head)
// {
//     struct node *p;
//     struct node *q;
//     p = head;
//     q = head->next;
//     while (q->next != NULL)
//     {
//         p = p->next;
//         q = q->next;
//     }
//     p->next=NULL;
//     free(q);
//     return head;
// }

// int main()
// {
//     struct node *head = (struct node *)malloc(sizeof(struct node));
//     head->data = 4;
//     struct node *node1 = (struct node *)malloc(sizeof(struct node));
//     node1->data = 5;
//     struct node *node2 = (struct node *)malloc(sizeof(struct node));
//     node2->data = 6;
//     struct node *node3 = (struct node *)malloc(sizeof(struct node));
//     node3->data = 8;
//     struct node *node4 = (struct node *)malloc(sizeof(struct node));
//     node4->data = 9;
//     struct node *node5 = (struct node *)malloc(sizeof(struct node));
//     node5->data = 10;

//     head->next = node1;
//     node1->next = node2;
//     node2->next = node3;
//     node3->next = node4;
//     node4->next = node5;
//     node5->next = NULL;

//     printf("Linked list before deletion\n");
//     dis(head);
//     printf("\n");
//     printf("Linked list after deletion\n");

//     head = delete_at_last(head);

//     dis(head);
//     printf("Linked list after deletion\n");
//     head = delete_at_last(head);
//     dis(head);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *HEAD = NULL;

void end(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;
    if (HEAD == NULL)
    {
        HEAD = newNode;
    }
    else
    {
        struct node *temp = HEAD;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newNode;
        newNode->link = NULL;
    }
}

void delete_at_last()
{
    struct node *p = HEAD;
    if (p->link ==NULL )
    {
        HEAD = NULL;
        free(p);
    }
    else
    {
        struct node *q;
        p = HEAD;
        q = HEAD->link;
        while (q->link != NULL)
        {
            p = p->link;
            q = q->link;
        }
        p->link = NULL;
        free(q);
    }
}

void dis()
{
    struct node *temp = HEAD;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->link;
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
    // end(62);
    printf("Dispaly nodes data before deletion:\n");
    dis();
    printf("\n\n");

    delete_at_last();
    printf("Dispaly nodes data after deletion:\n");
    dis();
    printf("\n\n");

    printf("Dispaly nodes data after deletion:\n");
    delete_at_last();
    dis();
    printf("\n\n");

    printf("Dispaly nodes data after deletion:\n");
    delete_at_last();
    dis();
}
