#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student
typedef struct Student {
    int id;
    char name[50];
    struct Student* next;
} Student;

// Function to create a new student node
Student* createStudent(int id, const char* name) {
    Student* student = (Student*)malloc(sizeof(Student));
    student->id = id;
    strcpy(student->name, name);
    student->next = NULL;
    return student;
}

// Function to insert a new student at the beginning of the linked list
void insertStudent(Student** head, int id, const char* name) {
    Student* newStudent = createStudent(id, name);
    newStudent->next = *head;
    *head = newStudent;
}

// Function to display all students in the linked list
void displayStudents(Student* head) {
    if (head == NULL) {
        printf("No students in the database.\n");
        return;
    }

    printf("Student Database:\n");
    printf("ID\tName\n");
    printf("------------------------\n");
    Student* current = head;
    while (current != NULL) {
        printf("%d\t%s\n", current->id, current->name);
        current = current->next;
    }
}

// Function to search for a student by ID
Student* searchStudent(Student* head, int id) {
    Student* current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete a student by ID
void deleteStudent(Student** head, int id) {
    Student* current = *head;
    Student* prev = NULL;

    // If the student to be deleted is the first student
    if (current != NULL && current->id == id) {
        *head = current->next;
        free(current);
        printf("Student with ID %d has been deleted.\n", id);
        return;
    }

    // Search for the student to be deleted
    while (current != NULL && current->id != id) {
        prev = current;
        current = current->next;
    }

    // If the student is not found
    if (current == NULL) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    // Remove the student from the linked list
    prev->next = current->next;
    free(current);
    printf("Student with ID %d has been deleted.\n", id);
}

// Function to free the memory allocated for the linked list
void freeStudents(Student** head) {
    Student* current = *head;
    Student* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

int main() {
    Student* head = NULL;

    // Insert some students
    insertStudent(&head, 101, "John");
    insertStudent(&head, 102, "Jane");
    insertStudent(&head, 103, "Mike");

    // Display all students
    displayStudents(head);

    // Search for a student
    int searchId = 102;
    Student* foundStudent = searchStudent(head, searchId);
    if (foundStudent != NULL) {
        printf("\nStudent with ID %d found:\n", searchId);
        printf("ID\tName\n");
        printf("------------------------\n");
        printf("%d\t%s\n", foundStudent->id, foundStudent->name);
    } else {
        printf("\nStudent with ID %d not found.\n", searchId);
    }

    // Delete a student
    int deleteId = 103;
    deleteStudent(&head, deleteId);

    // Display all students again
    displayStudents(head);

    // Free memory
    freeStudents(&head);

    return 0;
}
