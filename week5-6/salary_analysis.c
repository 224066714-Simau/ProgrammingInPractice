#include <stdio.h>

#define EMPLOYEES 50

int main(void)
{
    float salaries[EMPLOYEES];
    float total = 0, average, highest, lowest, searchSalary;
    int i, found = 0;

    printf("===== EMPLOYEE SALARY ANALYSIS =====\n");

    for (i = 0; i < EMPLOYEES; i++) {
        printf("Enter salary for employee %d: ", i + 1);

        if (scanf("%f", &salaries[i]) != 1 || salaries[i] < 0) {
            printf("Invalid input. Please run the program again.\n");
            return 1;
        }

        total += salaries[i];
    }

    highest = salaries[0];
    lowest = salaries[0];

    for (i = 1; i < EMPLOYEES; i++) {
        if (salaries[i] > highest)
            highest = salaries[i];

        if (salaries[i] < lowest)
            lowest = salaries[i];
    }

    average = total / EMPLOYEES;

    printf("\n===== SALARY RESULTS =====\n");

    for (i = 0; i < EMPLOYEES; i++) {
        printf("Employee %d: %.2f\n", i + 1, salaries[i]);
    }

    printf("\nTotal salaries: %.2f\n", total);
    printf("Average salary: %.2f\n", average);
    printf("Highest salary: %.2f\n", highest);
    printf("Lowest salary: %.2f\n", lowest);

    printf("\nEnter a salary to search for: ");

    if (scanf("%f", &searchSalary) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    for (i = 0; i < EMPLOYEES; i++) {
        if (salaries[i] == searchSalary) {
            printf("Salary found for employee %d.\n", i + 1);
            found = 1;
        }
    }

    if (!found)
        printf("Salary not found.\n");

    /* Sort salaries in ascending order using bubble sort. */
    for (i = 0; i < EMPLOYEES - 1; i++) {
        int j;

        for (j = 0; j < EMPLOYEES - i - 1; j++) {
            if (salaries[j] > salaries[j + 1]) {
                float temp = salaries[j];
                salaries[j] = salaries[j + 1];
                salaries[j + 1] = temp;
            }
        }
    }

    printf("\n===== SALARIES IN ASCENDING ORDER =====\n");

    for (i = 0; i < EMPLOYEES; i++) {
        printf("%.2f\n", salaries[i]);
    }

    return 0;
}