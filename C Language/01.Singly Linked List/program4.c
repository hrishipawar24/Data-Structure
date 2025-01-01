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
    struct node *temp;
    temp=malloc(sizeof(struct node));
    temp->data=v;
    temp->next=NULL;
    printf("%d",temp->data);
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
        }
    }
}

