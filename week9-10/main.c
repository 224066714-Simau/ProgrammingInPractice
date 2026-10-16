#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "reports.h"

int main(void)
{
    int choice;

    loadEmployees();
    loadBudgets();

    do
    {
        printf("\n========== MFMS WEEK 9-10 ==========\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Add Department Budget\n");
        printf("5. Display Budgets\n");
        printf("6. Generate Summary Report\n");
        printf("0. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Try again.\n");

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);

            choice = -1;
            continue;
        }

        switch (choice)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                addBudget();
                break;

            case 5:
                displayBudgets();
                break;

            case 6:
                generateReport();
                break;

            case 0:
                printf("Exiting MFMS. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 0);

    return 0;
}