#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    char post[50];
    int salary;
} Employee;

void addRecord(FILE *file) {
    Employee emp;

    printf("Enter Employee Name: ");
    scanf("%s", emp.name);
    printf("Enter Employee Post: ");
    scanf("%s", emp.post);
    printf("Enter Employee Salary: ");
    scanf("%d", &emp.salary);

    fwrite(&emp, sizeof(Employee), 1, file);
}

void displayRecordsInRange(FILE *file) {
    Employee emp;

    printf("\nEmployee Records with Salary between Rs. 15000 and Rs. 25000:\n");
    while (fread(&emp, sizeof(Employee), 1, file)) {
        if (emp.salary >= 15000 && emp.salary <= 25000) {
            printf("Name: %s\n", emp.name);
            printf("Post: %s\n", emp.post);
            printf("Salary: %d\n", emp.salary);
            printf("\n");
        }
    }
}

int main() {
    FILE *file;
    char choice;

    file = fopen("record.dat", "ab");
    if (file == NULL) {
        printf("Error! Can't open file.\n");
        exit(1);
    }

    do {
        addRecord(file);

        printf("Do you want to add another record? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    fclose(file);

    file = fopen("record.dat", "rb");
    if (file == NULL) {
        printf("Error! Can't open file.\n");
        exit(1);
    }

    displayRecordsInRange(file);

    fclose(file);

    return 0;
}
