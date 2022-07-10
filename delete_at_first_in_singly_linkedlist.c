// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//   int data;
//   struct node *next;
// };

// void dis(struct node *head)
// {
//   struct node *temp = head;
//   while (temp != NULL)
//   {
//     printf(" %d \n", temp->data);
//     temp = temp->next;
//   }
// }
// struct node *deletefirst(struct node *head)
// {
//   struct node *temp;
//   temp = head;
//   head=head->next;
//   free(temp);
//   return head;
// }

// int main()
// {
//   struct node *head = (struct node *)malloc(sizeof(struct node));
//   head->data = 4;
//   struct node *node1 = (struct node *)malloc(sizeof(struct node));
//   node1->data = 5;
//   struct node *node2 = (struct node *)malloc(sizeof(struct node));
//   node2->data = 6;
//   struct node *node3 = (struct node *)malloc(sizeof(struct node));
//   node3->data = 8;
//   struct node *node4 = (struct node *)malloc(sizeof(struct node));
//   node4->data = 9;
//   struct node *node5 = (struct node *)malloc(sizeof(struct node));
//   node5->data = 10;

//   head->next = node1;
//   node1->next = node2;
//   node2->next = node3;
//   node3->next = node4;
//   node4->next = node5;
//   node5->next = NULL;

//   printf("Linked list before deletion\n");
//   dis(head);
//   printf("\n");
//   head = deletefirst(head);
//   // head = deletefirst(head);// after delete a node u can  also delete a head again
//   printf("Linked list after deletion\n");
//   dis(head);
//   return 0;
// }


#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *HEAD = NULL;

void e(int data)
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
    }
}

void deletefirst()
{
  struct node *temp=HEAD;
  HEAD=HEAD->link;
  free(temp);
}

void dis()
{
    printf("\n");
    struct node *temp = HEAD;
    printf("Dispaly nodes data :\n");
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->link;
    }
}

int main()
{
    e(35);
    e(49);
    e(57);
    e(64);
    e(31);
    e(45);
    e(54);
    e(62);
    dis();
    printf("\n");
    deletefirst();
    dis();
    printf("\n");
    deletefirst();
    dis();
}

