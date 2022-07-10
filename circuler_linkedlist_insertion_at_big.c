#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node*insert_at_big(struct node *head,int data)
{
    struct node*newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    struct node*temp=head;  //we can also write (struct node*temp=head->next;)
    while (temp->next!=head)
    {
        temp=temp->next;
    }
     newNode->next=temp->next;
     temp->next=newNode;
     head=newNode;
    //temp->next=newNode;
    //newNode->next=head;
    //head=newNode;
}
void dis(struct node *head)
{
    struct node *temp = head;
    printf("Display node data:\n");
    do
    {
        printf("%d \n", temp->data);
        temp = temp->next;
    } while (temp!= head);
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 4;
    struct node *node1 = (struct node *)malloc(sizeof(struct node));
    node1->data = 5;
    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    node2->data = 6;
    struct node *node3 = (struct node *)malloc(sizeof(struct node));
    node3->data = 8;

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = head;

    printf("circuler linkedlist before insertion\n");
    dis(head);
    printf("\n");
    printf("circuler linkedlist after insertion\n");
    head=insert_at_big(head,45);
    dis(head);
    printf("\n");
    head=insert_at_big(head,50);
    dis(head);
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     struct node *next;
// };
// struct node *head = NULL;
// void big(int data)
// {
//     struct node *newNode = (struct node *)malloc(sizeof(struct node));
//     newNode->data = data;
//     newNode->next = NULL;
//     struct node *temp = head; // we can also write (struct node*temp=head->next;)
//     if (head == NULL)
//     {
//         head = newNode;
//         newNode->next = head;
//     }
//     else
//     {
//         while (temp->next != head)
//         {
//             temp = temp->next;
//         }
//         newNode->next = temp->next;
//         temp->next = newNode;
//         head = newNode;
//         // newNode->next = head;
//         // temp->next = newNode;
//         // head = newNode;
//     }
// }

// void dis()
// {
//     struct node *temp = head;
//     printf("Display node data:\n");
//     do
//     {
//         printf("%d \n", temp->data);
//         temp = temp->next;
//     } while (temp != head);
// }

// int main()
// {
//     big(45);
//     big(50);
//     big(55);
//     big(60);
//     big(65);
//     big(70);
//     dis();
// }
