#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define FILE_NAME "students.txt"

// Structure
struct Student {
    char name[50];
    int age;
};

struct Student students[MAX];
int count = 0;

// Prototypes
void addStudent();
void viewStudents();
void loadFromFile();
void saveToFile();
void clearInputBuffer();

int main() {
    int choice;

    // Load data at startup
    loadFromFile();

    while (1) {
        printf("\n===============================\n");
        printf(" Student Management System\n");
        printf("===============================\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Save & Exit\n");
        printf("-------------------------------\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                viewStudents();
                break;

            case 3:
                saveToFile();
                printf("Data saved. Goodbye.\n");
                exit(0);

            default:
                printf("Invalid option.\n");
        }
    }
}

// Clear input buffer
void clearInputBuffer() {
    while (getchar() != '\n');
}

// Load students from file
void loadFromFile() {
    FILE *file = fopen(FILE_NAME, "r");

    if (file == NULL) {
        // File doesn't exist yet
        return;
    }

    while (fscanf(file, " %49[^,],%d\n",
                  students[count].name,
                  &students[count].age) == 2) {

        count++;

        if (count >= MAX)
            break;
    }

    fclose(file);
}

// Save students to file
void saveToFile() {
    FILE *file = fopen(FILE_NAME, "w");

    if (file == NULL) {
        printf("Error saving file.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%d\n",
                students[i].name,
                students[i].age);
    }

    fclose(file);
}

// Add student
void addStudent() {
    if (count >= MAX) {
        printf("Student list full.\n");
        return;
    }

    clearInputBuffer();

    printf("Enter name: ");
    fgets(students[count].name, 50, stdin);

    // Remove newline
    students[count].name[strcspn(students[count].name, "\n")] = 0;

    printf("Enter age: ");
    scanf("%d", &students[count].age);

    count++;

    printf("Student added.\n");
}

// View students
void viewStudents() {
    if (count == 0) {
        printf("No students available.\n");
        return;
    }

    printf("\n--- Student List ---\n");

    for (int i = 0; i < count; i++) {
        printf("%d. %s - Age: %d\n",
               i + 1,
               students[i].name,
               students[i].age);
    }
}
README.md


## Author
Fon Bertrand
