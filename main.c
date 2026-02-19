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
void searchStudent();

/*
Student Management System
Author: Fon Bertrand
Language: C
Description:
A console-based application to manage student records.
Supports adding, viewing, searching, editing, deleting,
and saving student data using file storage.
*/
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
        printf("3. Search Student:\n");
        printf("4. save and exit:\n");
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
    searchStudent();
    break;

case 4:
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
void searchStudent() {
    char searchName[50];
    int found = 0;

    clearInputBuffer();

    printf("Enter name to search: ");
    fgets(searchName, 50, stdin);

    // Remove newline
    searchName[strcspn(searchName, "\n")] = 0;

    printf("\n--- Search Results ---\n");

    for (int i = 0; i < count; i++) {

        if (strcmp(students[i].name, searchName) == 0) {

            printf("Found:\n");
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}
