#include<stdio.h>
#include<stdlib.h>
//#include<malloc.h>

struct node
{
    int data;
    struct node *next;
}*head;
void create(int v)
{
    struct node *temp,*q;
    temp=malloc(sizeof(struct node));
    temp->data=v;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        q = head; 
            while (q->next != NULL) 
            { 
                q = q->next; 
            } 
            q->next = temp;
    }
}
void Display()
{
        struct node *q;
        if(head==NULL)
        {
            printf("\n List is empty");
            return;
        }
        q=head;
        printf("\n The list is =");
        while(q!=NULL)
        {
            printf("\n %d",q->data);
            q=q->next;
        }
}

int main()
{
    head=NULL;
    int ch,n,v,i;
    while(1)
    {
        printf("\n 0)Exit\n 1) Create\n 2) Display\n");
        printf("\n Enter the choice ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 0:
            exit(0);
            break;
        
        case 1:
            printf("\n How many nodes do you willing to create ");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                printf("\n Enter the Element = ");
                scanf("%d",&v);
                create(v);
            }
            break;
        case 2:
            Display();
            break;
        }
    }
}

