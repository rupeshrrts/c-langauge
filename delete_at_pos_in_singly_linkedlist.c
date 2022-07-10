
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

// struct node *delete_at_pos(struct node *head, int pos)
// {
//   struct node *p;
//   struct node *q;
//   p = head;
//   q = head->next;
//   for (int i = 1; i < pos - 1; i++)
//   {
//     p = p->next;
//     q = q->next;
//   }
//   p->next = q->next;
//   free(q);
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
//   printf("Linked list after deletion\n");

//   head = delete_at_pos(head, 3);

//   dis(head);

//   return 0;
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

void e(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (HEAD == NULL)
    {
        HEAD = newNode;
    }
    else
    {
        struct node *temp = HEAD;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int length()
{
    struct node *temp = HEAD;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void delete ()
{
    struct node *temp;
    int loc;
    printf("\n\nEnter the loc to delete :\n");
    scanf("%d",&loc);
    if (loc<1||loc>length())
    {
        printf("Invalid location\n");
        printf("Only you can eneter between 0-%d\n",length());
    }
    // else if(loc==1)
    // {
    //     temp=HEAD;
    //     HEAD=temp->next;
    //     temp->next=NULL;
    //     free(temp);
    // }
    
    else
    {
        struct node *p;
        struct node *q;
        p=HEAD;
        q=HEAD->next;
        int i=1;
        while (i<loc-1)
        {
           p=p->next;
           q=q->next;
           i++;
        }
        p->next=q->next;
        q->next=NULL; // this line is optional
        free(q);
    }
}

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
    e(3);
    e(4);
    e(5);
    e(6);
    e(7);
    e(8);
    e(9);
    e(11);
    e(12);
    e(18);
    e(19);
    e(34);
    printf("\n");
    printf("\n");
    printf("length is :%d",length());
    dis();

    delete ();
    dis();

    delete ();
    dis();
}