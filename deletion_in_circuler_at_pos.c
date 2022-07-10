
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
    struct node *temp = HEAD; 
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

void delete_at_pos()
{
    struct node *temp;
    int loc;
    printf("\n\nEnter the loc to delete :\n");
    scanf("%d",&loc);
    if (loc>length())
    {
        printf("Invalid location\n");
        printf("Only you can eneter between 0-%d\n",length());
    }
    else
    {
        struct node *p;
        struct node *q;
        p=HEAD;
        q=HEAD->link;
        int i=1; 
        while (i<loc-1)
        {
           p=p->link;
           q=q->link;
           i++;
        }
        p->link=q->link;
        q->link=NULL; // this line is optional
        free(q);
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
    end(74);
    
    printf("%d",length());
    printf("\n");
    printf("\n");
    dis();
    
    delete_at_pos();
    dis();
    
    delete_at_pos();
    dis();
}