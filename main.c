#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;

    printf("=== Student Management System ===\n");
    printf("1. Add Student\n");
    printf("2. View Students\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Add student feature coming soon.\n");
            break;
        case 2:
            printf("View students feature coming soon.\n");
            break;
        case 3:
            printf("Goodbye.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
