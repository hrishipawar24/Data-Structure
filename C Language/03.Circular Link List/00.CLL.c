#include<stdio.h> 
#include<stdlib.h> 
#include<malloc.h> 

// Define the structure of a node in the circular linked list
struct node 
{ 
    int data; // Data part of the node
    struct node *next; // Pointer to the next node
} *head; // Head pointer to the start of the circular linked list

// Function to create a new node and add it to the circular linked list
void create(int d) 
{ 
    struct node *q, *tmp; 
    tmp = malloc(sizeof(struct node)); // Allocate memory for the new node
    tmp->data = d; 
    if (head == NULL) // If the list is empty
    { 
        head = tmp; // Make the new node the head
        tmp->next = tmp; // Point the new node to itself
    } 
    else 
    { 
        q = head; 
        while (q->next != head) // Traverse to the last node
        { 
            q = q->next; 
        } 
        q->next = tmp; // Link the last node to the new node
        tmp->next = head; // Link the new node back to the head
    } 
} 

// Function to display the elements of the circular linked list
int display() 
{ 
    struct node *q; 
    if (head == NULL) // Check if the list is empty
    { 
        printf("\n\n List is empty"); 
        return 0; 
    } 
    q = head; 
    while (q->next != head) // Traverse the list
    { 
        printf("%d->", q->data); // Print the data of each node
        q = q->next; 
    } 
    printf("%d", q->data); // Print the last node
    return 0; 
} 

// Function to add a node at the beginning of the circular linked list
void add_at_beg(int d) 
{ 
    struct node *q, *tmp; 
    tmp = malloc(sizeof(struct node)); // Allocate memory for the new node
    tmp->data = d; 
    q = head; 
    while (q->next != head) // Traverse to the last node
    { 
        q = q->next; 
    } 
    tmp->next = head; // Link the new node to the current head
    q->next = tmp; // Link the last node to the new node
    head = tmp; // Update the head pointer to the new node
} 

// Function to add a node after a specific position
void add_after(int d, int pos) 
{ 
    struct node *q, *tmp; 
    int i; 
    tmp = malloc(sizeof(struct node)); // Allocate memory for the new node
    tmp->data = d; 
    q = head; 
    for (i = 0; i < pos - 1; i++) // Traverse to the desired position
    { 
        q = q->next; 
    } 
    tmp->next = q->next; // Link the new node to the next node
    q->next = tmp; // Link the current node to the new node
} 

// Function to delete a node with specific data
int del(int d) 
{ 
    struct node *tmp, *q; 
    if (head == NULL) // Check if the list is empty
    { 
        printf("\n List is EMPTY"); 
        return -1; 
    } 
    q = head; 
    tmp = head; 
    if (head->data == d) // If the head node is to be deleted
    { 
        while (q->next != head) // Traverse to the last node
        { 
            q = q->next; 
        } 
        head = head->next; // Move the head pointer to the next node
        q->next = head; // Link the last node to the new head
        free(tmp); // Free the memory of the deleted node
        return 0; 
    } 
    while (q->next->next != head) // Traverse the list to find the node
    { 
        if (q->next->data == d) 
        { 
            tmp = q->next; 
            q->next = tmp->next; // Link the current node to the next node
            free(tmp); // Free the memory of the deleted node
            return 0; 
        } 
        q = q->next; 
    } 
    if (q->next->data == d) // Check if the last node is to be deleted
    { 
        tmp = q->next; 
        q->next = head; // Link the current node to the head
        free(tmp); // Free the memory of the deleted node
        return 0; 
    } 
    printf("\n Element not found"); 
    return -1; 
} 

// Main function to drive the program
void main() 
{ 
    head = NULL; // Initialize the head pointer to NULL
    int ch, n, v, i, pos; 
    while (1) // Infinite loop for menu-driven operations
    { 
        printf("\n 0) Exit \n 1) Create \n 2) Display \n 3) Add After \n 4) Add at Begin \n 5) Delete "); 
        printf("\n Enter your choice: "); 
        scanf("%d", &ch); 
        switch (ch) 
        { 
            case 0: // Exit the program
                exit(0); 
                break; 

            case 1: // Create new nodes
                printf("\n How many nodes do you want to create? "); 
                scanf("%d", &n); 
                for (i = 0; i < n; i++) 
                { 
                    printf("\n Enter the element: "); 
                    scanf("%d", &v); 
                    create(v); 
                } 
                break; 

            case 2: // Display the list
                display(); 
                break; 

            case 3: // Add a node after a specific position
                printf("\n Enter the position: "); 
                scanf("%d", &pos); 
                printf("\n Enter the element: "); 
                scanf("%d", &v); 
                add_after(v, pos); 
                break; 

            case 4: // Add a node at the beginning
                printf("\n Enter the element: "); 
                scanf("%d", &v); 
                add_at_beg(v); 
                break; 

            case 5: // Delete a node
                if (head == NULL) 
                { 
                    printf("\n List is EMPTY"); 
                    continue; 
                } 
                printf("\n Enter the element to delete: "); 
                scanf("%d", &v); 
                del(v); 
                break; 

            default: 
                printf("\n Invalid choice. Please try again."); 
        } 
    } 
}
