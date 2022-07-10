
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
    struct node *temp=HEAD;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;

    if (HEAD == NULL)
    {

        HEAD  = newNode;
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
        temp= newNode;
    }
}


int length()
{
    struct node *temp = HEAD;
    int count = 1;
    while (temp->next != HEAD)
    {
        count++;
        temp = temp->next;
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
        newNode->prev = NULL;
        newNode->next = NULL;

        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next->prev = newNode;
        newNode->prev=temp;
        temp->next=newNode;
    }
}
void dis()
{
    struct node *temp = HEAD;
    printf("Display circuler node data:\n");
    do
    {
        printf("%d  ", temp->data);
        temp = temp->next;
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
    printf("length is :%d", length());
    printf("\n");
    dis();
}