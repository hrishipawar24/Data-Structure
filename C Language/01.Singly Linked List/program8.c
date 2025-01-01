#include<stdio.h>
#include<stdlib.h>
//#include<malloc.h>

struct node
{
    int data;
    struct node *next;
}*head;

// Function to add a node at the beginning of the list
void add_at_beg(int d) 
{ 
    struct node *tmp; 
    tmp = malloc(sizeof(struct node)); // Allocate memory for the new node
    tmp->data = d; 
    tmp->next = head; // Point the new node to the current head
    head = tmp; // Update the head to the new node
} 

// Function to add a node after a specific position
void add_after(int d, int pos) 
{ 
    int i; 
    struct node *tmp, *q = head; 
    tmp = malloc(sizeof(struct node)); // Allocate memory for the new node
    tmp->data = d; 
    for (i = 0; i < pos - 1; i++) // Traverse to the desired position
    { 
        q = q->next; 
    } 
    tmp->next = q->next; // Link the new node
    q->next = tmp; 
} 
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
    int ch,n,v,i,pos;
    while(1)
    {
        printf("\n 0)Exit\n 1) Create\n 2) Display \n 3) Add After\n 4)Add at Begining\n ");
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
        case 3: // Add a node after a specific position
                printf("\n Enter the position: "); 
                scanf("%d", &pos); 
                printf("\n Enter the element: "); 
                scanf("%d", &v); 
                add_after(v,pos); 
                break; 
        case 4: // Add a node at the beginning
                printf("\n Enter the element: "); 
                scanf("%d", &v); 
                add_at_beg(v); 
                break; 
        }
    }
}

