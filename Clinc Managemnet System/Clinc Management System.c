#include <stdio.h>
#include <string.h>

#define MAX_PATIENTS 100
#define MAX_SLOTS 5

// Define the structure for patient records
struct Patient {
    char name[50];
    int age;
    char gender;
    int id;
};

// Define an array to store patient records
struct Patient patients[MAX_PATIENTS];

// Define an array to store reserved slots
int reservedSlots[MAX_SLOTS];

// Function to add a new patient record
void addPatient() {
    // TODO: Implement this function
}

// Function to edit a patient record
void editPatient() {
    // TODO: Implement this function
}

// Function to reserve a slot with the doctor
void reserveSlot() {
    // TODO: Implement this function
}

// Function to cancel a reservation
void cancelReservation() {
    // TODO: Implement this function
}

// Function to view a patient's record
void viewPatientRecord() {
    // TODO: Implement this function
}

// Function to view today's reservations
void viewTodayReservations() {
    // TODO: Implement this function
}

// Function to check if the entered ID exists
int idExists(int id) {
    // TODO: Implement this function
}

// Main function
int main() {
    int mode; // Variable to store the selected mode
    char password[5]; // Array to store the password
    int passwordTries = 3; // Number of password attempts allowed

    printf("Choose a mode:\n"); // Prompt user to choose a mode
    printf("1. Admin mode\n");
    printf("2. User mode\n");
    scanf("%d", &mode); // Read the selected mode from the user

    if (mode == 1) { // If admin mode is selected
        printf("Enter the password: "); // Prompt for the password
        scanf("%s", password); // Read the password from the user

        while (strcmp(password, "1234") != 0) { // Check if the password is incorrect
            passwordTries--; // Decrement the number of password attempts remaining

            if (passwordTries == 0) { // If no attempts remaining, display an error message and exit
                printf("Too many incorrect password tries. Closing...\n");
                return 0;
            }

            printf("Incorrect password. %d tries left. Enter the password: ", passwordTries); // Prompt for the password again
            scanf("%s", password); // Read the password from the user
        }

        int choice; // Variable to store the selected choice in admin mode

        do {
            printf("\nAdmin mode features:\n"); // Display admin mode features
            printf("1. Add new patient record\n");
            printf("2. Edit patient record\n");
            printf("3. Reserve a slot with the doctor\n");
            printf("4. Cancel reservation\n");
            printf("5. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice); // Read the selected choice from the user

            switch (choice) { // Perform actions based on the selected choice
                case 1:
                    addPatient();
                    break;
                case 2:
                    editPatient();
                    break;
                case 3:
                    reserveSlot();
                    break;
                case 4:
                    cancelReservation();
                    break;
                case 5:
                    printf("Exiting admin mode...\n");
                    break;
                default:
                    printf("Invalid choice. Please enter a valid choice.\n");
            }
        } while (choice != 5); // Continue the loop until "Exit" option is selected
    } else if (mode == 2) { // If user mode is selected
        int choice; // Variable to store the selected choice in user mode

        do {
            printf("\nUser mode features:\n"); // Display user mode features
            printf("1. View patient record\n");
            printf("2. View today's reservations\n");
            printf("3. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice); // Read the selected choice from the user

            switch (choice) { // Perform actions based on the selected choice
                case 1:
                    viewPatientRecord();
                    break;
                case 2:
                    viewTodayReservations();
                    break;
                case 3:
                    printf("Exiting user mode...\n");
                    break;
                default:
                    printf("Invalid choice. Please enter a valid choice.\n");
            }
        } while (choice != 3); // Continue the loop until "Exit" option is selected
    } else { // If an invalid mode choice is entered
        printf("Invalid mode choice. Closing...\n");
        return 0;
    }

    return 0;
}
