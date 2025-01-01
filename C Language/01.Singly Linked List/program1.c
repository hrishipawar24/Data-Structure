#include<stdio.h>
#include<stdlib.h>
//#include<malloc.h>

struct node
{
    int data;
    struct node *next;
}*head;

int main()
{
    head=NULL;
    int ch;
    while(1)
    {
        printf("\n 0)Exit\n 1) Create\n 2) Display\n");
        printf("\n Enter the choice");
        scanf("%d",&ch);
    }
}

