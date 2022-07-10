// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     struct node *next;
// };

// struct node*insert_at_big(struct node *head,int data)
// {
//     struct node*newNode=(struct node*)malloc(sizeof(struct node));
//     newNode->data=data;
//     newNode->next=NULL;
//     struct node*temp=head;  //we can also write (struct node*temp=head->next;)
//     while (temp->next!=head)
//     {
//         temp=temp->next;
//     }
//     newNode->next=temp->next;
//     temp->next=newNode;
//     temp=temp->next;   // this line is optional
// // temp->link = newNode;
// // newNode->link = HEAD;
// // newNode=temp;   // this line is optional

// }
// void dis(struct node *head)
// {
//     struct node *temp =head;
//     printf("Display node data:\n");
//     do
//     {
//         printf("%d \n", temp->data);
//         temp = temp->next;
//     } while (temp!= head);
// }

// int main()
// {
//     struct node *head = (struct node *)malloc(sizeof(struct node));
//     head ->data = 10;
//     struct node *node1 = (struct node *)malloc(sizeof(struct node));
//     node1->data = 20;
//     struct node *node2 = (struct node *)malloc(sizeof(struct node));
//     node2->data = 30;
//     struct node *node3 = (struct node *)malloc(sizeof(struct node));
//     node3->data = 40;

//     head->next = node1;
//     node1->next = node2;
//     node2->next = node3;
//     node3->next = head;

//     printf("circuler linkedlist before insertion\n");
//     dis(head);
//     printf("\n");
//     printf("circuler linkedlist after insertion\n");
//     insert_at_big(head,45);
//     dis(head);
//     printf("circuler linkedlist after insertion\n");
//     insert_at_big(head,50);
//     dis(head);
//     printf("circuler linkedlist after insertion\n");
//     insert_at_big(head,55);
//     dis(head);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head;
void last(int data)
{

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    struct node *temp = head; // we can also write (struct node*temp=head->next;)
    if (head == NULL)
    {
        head = temp = newNode;
        newNode->next = head;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next; //tish line is optional 
        // temp->link = newNode;
        // newNode->link = HEAD;
        // newNode=temp;// this line is optional
    }
}
void dis()
{
    struct node *temp = head;
    printf("Display circuler node data:\n");
    do
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main()
{
    last(15);
    last(20);
    last(25);
    last(30);
    last(35);
    last(40);
    dis();
}
