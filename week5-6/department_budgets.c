#include <stdio.h>

#define DEPARTMENTS 10

int main(void)
{
    float budgets[DEPARTMENTS];
    float total = 0.0f, average, temp;
    int i, j;

    printf("===== MUNICIPAL DEPARTMENT BUDGET SYSTEM =====\n");

    /* Enter the budget for each department. */
    for (i = 0; i < DEPARTMENTS; i++) {
        printf("Enter budget for department %d: ", i + 1);

        if (scanf("%f", &budgets[i]) != 1 || budgets[i] < 0) {
            printf("Invalid input. Please run the program again.\n");
            return 1;
        }

        total += budgets[i];
    }

    average = total / DEPARTMENTS;

    printf("\n===== DEPARTMENT BUDGETS =====\n");

    for (i = 0; i < DEPARTMENTS; i++) {
        printf("Department %d: %.2f\n", i + 1, budgets[i]);
    }

    printf("\nTotal budget: %.2f\n", total);
    printf("Average budget: %.2f\n", average);

    /* Sort budgets in ascending order using bubble sort. */
    for (i = 0; i < DEPARTMENTS - 1; i++) {
        for (j = 0; j < DEPARTMENTS - i - 1; j++) {
            if (budgets[j] > budgets[j + 1]) {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    printf("\n===== BUDGETS IN ASCENDING ORDER =====\n");

    for (i = 0; i < DEPARTMENTS; i++) {
        printf("%.2f\n", budgets[i]);
    }

    return 0;
}