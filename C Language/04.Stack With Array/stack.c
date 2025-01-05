#include<stdio.h> 
#include<stdlib.h> 

// Define a stack with a maximum size of 10 and initialize the top pointer to 0
int stack[10], top = 0; 

// Function to push an element onto the stack
int push(int d) 
{ 
    // Check if the stack is full
    if(top == 9) 
    { 
        printf("\n Stack is full"); 
        return 0; // Return 0 to indicate failure
    } 
    stack[top] = d; // Add the element to the stack
    top++; // Increment the top pointer
} 

// Function to display the elements of the stack
int display() 
{ 
    int i; 
    // Check if the stack is empty
    if(top == 0) 
    { 
        printf("\n List is empty"); 
        return 0; // Return 0 to indicate that the stack is empty
    } 
    // Loop through and print all elements in the stack
    for(i = 0; i < top; i++) 
    { 
        printf("\n%d", stack[i]); 
    } 
} 

// Function to pop (remove) an element from the stack
int pop() 
{ 
    // Check if the stack is empty
    if(top == 0) 
    { 
        printf("\n List is empty"); 
        return 0; // Return 0 to indicate failure
    } 
    top = top - 1; // Decrement the top pointer to "remove" the top element
} 

// Main function to handle user interaction
int main() 
{ 
    int d, i, ch, n; // Variables for user input
    while(1) // Infinite loop to continuously display the menu
    { 
        // Display menu options
        printf("\n 0) Exit"); 
        printf("\n 1) Push"); 
        printf("\n 2) Pop"); 
        printf("\n 3) Display"); 
        printf("\n Enter your choice ="); 
        scanf("%d", &ch); // Read user's choice

        switch(ch) 
        { 
            case 0:  
                // Exit the program
                exit(0); 
                break; 

            case 1:  
                // Push multiple elements onto the stack
                printf
            case 2: 
                // Pop the top element from the stack
                pop(); 
                break; 

            case 3: 
                // Display all elements in the stack
                display(); 
                break; 

            default:
                // Handle invalid choices
                printf("\n Invalid choice. Try again.");
                break;
        } 
} 
