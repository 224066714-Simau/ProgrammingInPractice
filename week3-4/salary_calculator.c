#include <stdio.h>

int main(void)
{
    float basicSalary, housingAllowance, transportAllowance;
    float tax, grossSalary, netSalary;

    printf("===== EMPLOYEE SALARY CALCULATOR =====\n");

    printf("Enter basic salary: ");
    if (scanf("%f", &basicSalary) != 1 || basicSalary < 0) {
        printf("Invalid input. Try again.\n");
        return 1;
    }

    printf("Enter housing allowance: ");
    if (scanf("%f", &housingAllowance) != 1 || housingAllowance < 0) {
        printf("Invalid input. Try again.\n");
        return 1;
    }

    printf("Enter transport allowance: ");
    if (scanf("%f", &transportAllowance) != 1 || transportAllowance < 0) {
        printf("Invalid input. Try again.\n");
        return 1;
    }

    printf("Enter tax amount: ");
    if (scanf("%f", &tax) != 1 || tax < 0) {
        printf("Invalid input. Try again.\n");
        return 1;
    }

    grossSalary = basicSalary + housingAllowance + transportAllowance;
    netSalary = grossSalary - tax;

    printf("\n===== SALARY DETAILS =====\n");
    printf("Basic Salary:        %.2f\n", basicSalary);
    printf("Housing Allowance:   %.2f\n", housingAllowance);
    printf("Transport Allowance: %.2f\n", transportAllowance);
    printf("Gross Salary:        %.2f\n", grossSalary);
    printf("Tax:                 %.2f\n", tax);
    printf("Net Salary:          %.2f\n", netSalary);

    if (netSalary >= 20000) {
        printf("Income Category: High Income\n");
    } else {
        printf("Income Category: Standard Income\n");
    }

    return 0;
}