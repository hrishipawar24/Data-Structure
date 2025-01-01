#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *head = NULL;

// Function to search for an element in the list
int search(int d) {
    struct node *q = head; // Temporary pointer for traversal
    int pos = 1;           // To track the position of the node

    if (head == NULL) { // Check if the list is empty
        printf("\n The list is empty.");
        return -1; // Indicate list is empty
    }

    while (q != NULL) { // Traverse through the list
        if (q->data == d) { // If the data matches
            printf("\n Element %d found at position %d", d, pos);
            return pos; // Return the position
        }
        q = q->next; // Move to the next node
        pos++;       // Increment position
    }

    printf("\n Element %d not found in the list", d);
    return -1; // Indicate element was not found
}


// Function to count the number of nodes in the list
void count() 
{ 
    struct node *q = head; // Temporary pointer for traversal
    int cnt = 0; // Counter to count nodes
    while (q != NULL) 
    { 
        q = q->next; // Move to the next node
        cnt++; // Increment the counter
    } 
    printf("\n Count is %d", cnt); 
} 

// Function to reverse the linked list
int reverse() 
{ 
    struct node *p1, *p2, *p3; // Pointers for traversal
    if (head == NULL || head->next == NULL) // Check for empty or single-node list
    { 
        return 0; 
    } 
    p1 = head; 
    p2 = p1->next; 
    p3 = p2->next; 
    p1->next = NULL; // The first node becomes the last node
    p2->next = p1; 
    while (p3 != NULL) 
    { 
        p1 = p2; 
        p2 = p3; 
        p3 = p3->next; 
        p2->next = p1; // Reverse the links
    } 
    head = p2; // Update the head pointer
    return 0; 
} 

// Function to delete a node with specific data
int del(int d) {
    struct node *temp, *q;
    if (head == NULL) { // Check if the list is empty
        printf("\n List is empty");
        return -1;
    }
    if (head->data == d) { // Check if the head node is to be deleted
        temp = head;
        head = head->next;
        free(temp); // Free the memory of the deleted node
        return 0;
    }
    q = head;
    while (q->next != NULL) { // Traverse the list to find the node
        if (q->next->data == d) {
            temp = q->next;
            q->next = temp->next;
            free(temp); // Free the memory of the deleted node
            return 0;
        }
        q = q->next;
    }
    printf("\n Element not found");
    return -1; // Indicate element was not found
}

// Function to add a node at the beginning of the list
void add_at_beg(int d) {
    struct node *tmp = malloc(sizeof(struct node)); // Allocate memory for the new node
    if (tmp == NULL) {
        printf("\n Memory allocation failed");
        return;
    }
    tmp->data = d;
    tmp->next = head; // Point the new node to the current head
    head = tmp; // Update the head to the new node
}

// Function to add a node after a specific position
void add_after(int d, int pos) {
    int i;
    struct node *tmp, *q = head;
    tmp = malloc(sizeof(struct node)); // Allocate memory for the new node
    if (tmp == NULL) {
        printf("\n Memory allocation failed");
        return;
    }
    tmp->data = d;
    for (i = 0; i < pos - 1 && q != NULL; i++) { // Traverse to the desired position
        q = q->next;
    }
    if (q == NULL) {
        printf("\n Position out of bounds");
        free(tmp);
        return;
    }
    tmp->next = q->next; // Link the new node
    q->next = tmp;
}

// Function to create a node
void create(int v) {
    struct node *temp, *q;
    temp = malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("\n Memory allocation failed");
        return;
    }
    temp->data = v;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    } else {
        q = head;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = temp;
    }
}

// Function to display the list
void Display() {
    struct node *q;
    if (head == NULL) {
        printf("\n List is empty");
        return;
    }
    q = head;
    printf("\n The list is:");
    while (q != NULL) {
        printf(" %d", q->data);
        q = q->next;
    }
}

int main() {
    int ch, n, v, i, pos;
    while (1) {
        printf("\n0)Exit\n1)Create\n2)Display\n3)Add After\n4)Add at Beginning\n5)Delete\n6)Reverse\n7)count\n8)Search\n");
        printf(" Enter the choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 0:
                exit(0);
                break;
            case 1:
                printf("\n How many nodes do you want to create? ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf(" Enter the element: ");
                    scanf("%d", &v);
                    create(v);
                }
                break;
            case 2:
                Display();
                break;
            case 3:
                printf("\n Enter the position: ");
                scanf("%d", &pos);
                printf(" Enter the element: ");
                scanf("%d", &v);
                add_after(v, pos);
                break;
            case 4:
                printf(" Enter the element: ");
                scanf("%d", &v);
                add_at_beg(v);
                break;
            case 5:
                if (head == NULL) {
                    printf("\n List is EMPTY");
                    continue;
                }
                printf(" Enter the element to delete: ");
                scanf("%d", &v);
                del(v);
                break;
            case 6: // Reverse the list
                reverse(); 
                break; 
            case 7: // Count the nodes
                count(); 
                break;
            case 8: // Search for an element
                printf("\n Enter the element to search: "); 
                scanf("%d", &v); 
                search(v); 
                break;                  
            default:
                printf("\n Invalid choice");
        }
    }
}
