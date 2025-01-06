#include<stdio.h> // Include standard input-output header file
#include<stdlib.h> // Include standard library header file for functions like exit()

// Define a queue with a maximum size of 10 and initialize front and rear pointers
int q[10], front = 0, rear = 0;

// Function to add an element to the queue
int add(int d)
{
    // Check if the queue is full
    if(rear == 10)
    {
        printf("\n Queue is full"); // Print message if the queue is full
        return 0; // Return 0 to indicate failure
    }
    q[rear] = d; // Add the element at the rear of the queue
    rear++; // Increment the rear pointer
}

// Function to display all elements in the queue
int display()
{
    int i; // Variable for iteration
    // Check if the queue is empty
    if(front == rear)
    {
        printf("\n Queue is empty"); // Print message if the queue is empty
        return 0; // Return 0 to indicate the queue is empty
    }
    // Iterate through the queue from the front to the rear
    for(i = front; i < rear; i++)
    {
        printf("\n%d", q[i]); // Print each element in the queue
    }
}

// Function to delete an element from the queue
int delete()
{
    // Check if the queue is empty
    if(front == rear)
    {
        printf("\n\n Queue is empty"); // Print message if the queue is empty
        return 0; // Return 0 to indicate failure
    }
    front++; // Increment the front pointer to "remove" the front element
}

// Main function to manage the queue operations
int main()
{
    int d, i, ch, n; // Variables for user input and loop counters

    // Infinite loop to continuously display the menu
    while(1)
    {
        // Display menu options
        printf("\n 0) Exit");
        printf("\n 1) Add");
        printf("\n 2) Delete");
        printf("\n 3) Display");
        printf("\n Enter your choice =");
        scanf("%d", &ch); // Read user's choice

        switch(ch)
        {
            case 0: // Exit the program
                exit(0); // End the program
                break;

            case 1: // Add elements to the queue
                printf("\n How many elements do you want to add =");
                scanf("%d", &n); // Read the number of elements to add
                for(i = 0; i < n; i++) // Loop to read and add each element
                {
                    printf("\n Enter the element=");
                    scanf("%d", &d); // Read the element
                    add(d); // Call the add function
                }
                break;

            case 2: // Delete an element from the queue
                delete(); // Call the delete function
                break;

            case 3: // Display all elements in the queue
                display(); // Call the display function
                break;

            default: // Handle invalid choices
                printf("\n Invalid choice. Try again.");
        }
    }
}
