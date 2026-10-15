#include <stdio.h>

int main(void)
{
    double revenue;
    double expenses;
    double balance;

    printf("====================================\n");
    printf("     MUNICIPAL BUDGET CALCULATOR\n");
    printf("====================================\n");

    printf("Enter total revenue: ");
    if (scanf("%lf", &revenue) != 1 || revenue < 0) {
        printf("Invalid revenue. Try again.\n");
        return 1;
    }

    printf("Enter total expenses: ");
    if (scanf("%lf", &expenses) != 1 || expenses < 0) {
        printf("Invalid expenses. Try again.\n");
        return 1;
    }

    balance = revenue - expenses;

    printf("\n========== BUDGET REPORT ==========\n");
    printf("Total revenue:  %.2f\n", revenue);
    printf("Total expenses: %.2f\n", expenses);

    if (balance > 0) {
        printf("Surplus:        %.2f\n", balance);
    } else if (balance < 0) {
        printf("Deficit:        %.2f\n", -balance);
    } else {
        printf("The budget is balanced.\n");
    }

    printf("===================================\n");

    return 0;
}