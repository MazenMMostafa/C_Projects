#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student
struct Student {
    int rollNumber;
    char name[50];
    struct Student* next;
};

// Structure to represent a queue
struct Queue {
    struct Student* front;
    struct Student* rear;
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to add a student to the rear of the queue
void enqueue(struct Queue* queue, int rollNumber, const char* name) {
    // Create a new student
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->rollNumber = rollNumber;
    strcpy(newStudent->name, name);
    newStudent->next = NULL;

    // If the queue is empty, set both front and rear to the new student
    if (queue->rear == NULL) {
        queue->front = newStudent;
        queue->rear = newStudent;
    } else {
        // Otherwise, add the new student to the rear of the queue
        queue->rear->next = newStudent;
        queue->rear = newStudent;
    }
}

// Function to remove a student from the front of the queue
void dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
    } else {
        // Store the front student to be removed
        struct Student* temp = queue->front;

        // Move the front pointer to the next student in the queue
        queue->front = queue->front->next;

        // If the front becomes NULL, set rear to NULL as well
        if (queue->front == NULL) {
            queue->rear = NULL;
        }

        // Free the memory occupied by the removed student
        free(temp);
    }
}

// Function to display the contents of the queue
void displayQueue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
    } else {
        struct Student* current = queue->front;

        printf("Roll Number\tName\n");
        printf("------------------------\n");

        while (current != NULL) {
            printf("%d\t\t%s\n", current->rollNumber, current->name);
            current = current->next;
        }
    }
}

int main() {
    // Create an empty queue
    struct Queue* studentQueue = createQueue();

    // Add students to the queue
    enqueue(studentQueue, 1, "Mazen");
    enqueue(studentQueue, 2, "Mohamed");
    enqueue(studentQueue, 3, "Ahmed");

    // Display the contents of the queue
    displayQueue(studentQueue);

    // Remove a student from the queue
    dequeue(studentQueue);

    // Display the updated contents of the queue
    displayQueue(studentQueue);

    return 0;
}
