#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 

// Define the structure of a node in the doubly linked list
struct node 
{ 
    int data; // Data part of the node
    struct node *next; // Pointer to the next node
    struct node *prev; // Pointer to the previous node
} *head; // Head pointer to the start of the linked list

// Function to add a node after a specified position
void add_after(int d, int pos) 
{ 
    struct node *q, *tmp; 
    int i; 
    q = head; // Start traversal from the head
    for (i = 0; i < pos - 1; i++) 
    { 
        q = q->next; // Traverse to the specified position
    } 
    tmp = malloc(sizeof(struct node)); // Allocate memory for the new node
    tmp->data = d; 
    q->next->prev = tmp; // Update the previous pointer of the next node
    tmp->next = q->next; // Link the new node to the next node
    tmp->prev = q; // Link the new node to the current node
    q->next = tmp; // Update the next pointer of the current node
} 

// Function to add a node at the beginning of the list
void add_at_beg(int d) 
{ 
    struct node *tmp; 
    tmp = malloc(sizeof(struct node)); // Allocate memory for the new node
    tmp->data = d; 
    tmp->prev = NULL; // Set the previous pointer of the new node to NULL
    tmp->next = head; // Link the new node to the current head
    if (head != NULL) // If the list is not empty
        head->prev = tmp; // Update the previous pointer of the current head
    head = tmp; // Update the head pointer to the new node
} 

// Function to delete a node with a specific value
int delete(int d) 
{ 
    struct node *tmp, *q; 
    if (head == NULL) // Check if the list is empty
    { 
        printf("\n List is EMPTY"); 
        return -1; 
    } 
    if (head->data == d) // If the head node is to be deleted
    { 
        tmp = head; 
        head = head->next; // Move the head pointer to the next node
        if (head != NULL) // If the list is not empty after deletion
            head->prev = NULL; // Set the previous pointer of the new head to NULL
        free(tmp); // Free the memory of the deleted node
        return 0; 
    } 
    q = head; 
    while (q->next != NULL) // Traverse the list to find the node
    { 
        if (q->next->data == d) 
        { 
            tmp = q->next; 
            q->next = tmp->next; // Link the current node to the next node
            if (tmp->next != NULL) // If the deleted node is not the last node
                tmp->next->prev = q; // Update the previous pointer of the next node
            free(tmp); // Free the memory of the deleted node
            return 0; 
        } 
        q = q->next; 
    } 
    printf("\n Element not found"); 
    return -1; 
} 

// Function to reverse the doubly linked list
void reverse() 
{ 
    struct node *p1, *p2; 
    p1 = head; // Start from the head
    p2 = p1->next; 
    p1->next = NULL; // The first node becomes the last node
    p1->prev = p2; 
    while (p2 != NULL) 
    { 
        p2->prev = p2->next; // Swap the previous and next pointers
        p2->next = p1; 
        p1 = p2; // Move p1 to the next node
        p2 = p2->prev; // Move p2 to the next node (previous becomes next)
    } 
    head = p1; // Update the head pointer to the new head
} 

// Function to count the number of nodes in the list
void count() 
{ 
    int cnt = 0; 
    struct node *q = head; 
    while (q != NULL) // Traverse the list
    { 
        cnt++; // Increment the counter for each node
        q = q->next; 
    } 
    printf("\n Count is = %d", cnt); 
} 

// Function to search for a node with a specific value
void search(int d) 
{ 
    struct node *q = head; 
    while (q != NULL) // Traverse the list
    { 
        if (q->data == d) // Check if the current node contains the value
        { 
            printf("\n Element found"); 
            return; 
        } 
        q = q->next; // Move to the next node
    } 
    printf("\n Element not found"); 
} 

// Function to create a new node and add it to the end of the list
void create(int d) 
{ 
    struct node *q, *tmp; 
    tmp = malloc(sizeof(struct node)); // Allocate memory for the new node
    tmp->data = d; 
    tmp->next = NULL; 
    tmp->prev = NULL; 
    if (head == NULL) // If the list is empty
    { 
        head = tmp; // Make the new node the head
    } 
    else 
    { 
        q = head; 
        while (q->next != NULL) // Traverse to the last node
        { 
            q = q->next; 
        } 
        q->next = tmp; // Link the last node to the new node
        tmp->prev = q; // Link the new node to the last node
    } 
} 

// Function to display the elements of the list
void display() 
{ 
    struct node *q = head; 
    while (q != NULL) // Traverse the list
    { 
        printf("%d->", q->data); // Print the data of each node
        q = q->next; 
    } 
    printf("NULL\n"); // Indicate the end of the list
} 

// Main function to drive the program
void main() 
{ 
    head = NULL; // Initialize the head pointer to NULL
    int ch, n, v, i, pos; 
    while (1) // Infinite loop for menu-driven operations
    { 
        printf("\n 0) Exit \n 1) Create \n 2) Display \n 3) Add After \n 4) Add at Begin \n 5) Delete \n 6) Reverse \n 7) Count \n 8) Search\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &ch); 
        switch (ch) 
        { 
            case 0: // Exit the program
                exit(0); 
                break; 

            case 1: // Create new nodes
                printf("How many nodes do you want to create? "); 
                scanf("%d", &n); 
                for (i = 0; i < n; i++) 
                { 
                    printf("Enter the element: "); 
                    scanf("%d", &v); 
                    create(v); 
                } 
                break; 

            case 2: // Display the list
                display(); 
                break; 

            case 3: // Add a node after a specific position
                printf("Enter the position: "); 
                scanf("%d", &pos); 
                printf("Enter the element: "); 
                scanf("%d", &v); 
                add_after(v, pos); 
                break; 

            case 4: // Add a node at the beginning
                printf("Enter the element: "); 
                scanf("%d", &v); 
                add_at_beg(v); 
                break; 

            case 5: // Delete a node
                if (head == NULL) 
                { 
                    printf("\n List is EMPTY"); 
                    continue; 
                } 
                printf("Enter the element to delete: "); 
                scanf("%d", &v); 
                delete(v); 
                break; 

            case 6: // Reverse the list
                reverse(); 
                break;  

            case 7: // Count the nodes
                count(); 
                break; 

            case 8: // Search for an element
                printf("Enter the element to search: "); 
                scanf("%d", &v); 
                search(v); 
                break; 

            default: 
                printf("\n Invalid choice. Please try again."); 
        } 
    } 
}
