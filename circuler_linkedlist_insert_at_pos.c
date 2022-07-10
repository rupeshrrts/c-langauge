// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     struct node *next;
// };

// struct node * insertAtIndex(struct node *head, int data, int index){
//     struct node * newNode = (struct node *) malloc(sizeof(struct node));
//     newNode->data = data;
//     struct node * temp = head;
//     int i = 0;

//     while (i!=index-1)
//     {
//         temp = temp->next;
//         i++;
//     }

//     newNode->next = temp->next;
//     temp->next = newNode;
//     return head;
// }
// void dis(struct node *head)
// {
//     struct node *temp = head;
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
//     head ->data = 4;
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
//     node5->next = head;

//     printf("Display data before insert\n");
//     dis(head);
//     head = insertAtIndex(head, 45, 2);
//     printf("Display data after insert\n");
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
    struct node *temp = HEAD; // we can also write (struct node*temp=head->next;)
    if (HEAD == NULL)
    {
        HEAD = temp = newNode;
        newNode->link = HEAD;
    }
    else
    {
        while (temp->link != HEAD)
        {
            temp = temp->link;
        }
        newNode->link = temp->link;
        temp->link = newNode;
        temp = temp->link; // this line is optional

        // temp->link = newNode;
        // newNode->link = HEAD;
        // newNode=temp;// this line is optional
    }
}

int length()
{
    struct node *temp = HEAD;
    int count = 1;
    while (temp->link != HEAD)
    {
        count++;
        temp = temp->link;
    }
    return count;
}

void addatafter()
{
    int pos, len, i = 1;
    struct node *temp = HEAD;
    printf("\n\nIf you want  to add a node in the list -\n");
    printf("Please Enter the possition :\n");
    scanf("%d", &pos);

    if (pos > length())
    {
        printf("Invalid position\n");
        printf("you can insert Node between 0-%d Nodes\n", length());
    }
    else
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the Node data :\n");
        scanf("%d", &newNode->data);
        newNode->link = NULL;
        while (i < pos - 1)
        {
            temp = temp->link;
            i++;
        }
        newNode->link = temp->link;
        temp->link = newNode;
        // HEAD=HEAD->link; we use this line when , we use (struct node *temp = HEAD->next;)
    }
}

void dis()
{
    struct node *temp = HEAD;
    printf("Display circuler node data:\n");
    do
    {
        printf("%d  ", temp->data);
        temp = temp->link;
    } while (temp != HEAD);
}

int main()
{

    end(35);
    end(47);
    end(51);
    end(69);
    end(71);
    end(89);
    end(95);
    end(51);
    end(12);
    end(54);

    printf("length is :%d", length());
    printf("\n");
    dis();

    addatafter();
    printf("length is :%d", length());
    printf("\n");
    dis();

    addatafter();
    dis();
}