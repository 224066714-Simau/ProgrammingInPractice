#include <stdio.h>

int budget() { 
    double revenue; 
    double expenses; 
    double balance; 

    printf("\nMUNICIPAL BUDGET CALCULATOR\n"); 
    printf("---------------------------\n"); 

    printf("Enter total revenue: "); 
    scanf("%lf", &revenue); 

    printf("Enter total expenses: "); 
    scanf("%lf", &expenses); 

    balance = revenue - expenses; 

    printf("\nRevenue: %.2f\n", revenue); 
    printf("Expenses: %.2f\n", expenses); 

    if (balance > 0) { 
        printf("Surplus: %.2f\n", balance); 
    } 
    else if (balance < 0) { 
        printf("Deficit: %.2f\n", -balance); 
    } 
    else { 
        printf("The budget is balanced.\n"); 
    } 
    return 0; 
}

int main() {
    char municipality[50];
    char mayor[50];
    int population;
    int calbudget;

    printf("Municipal Financial Management System\n");
    printf("Welcome to Windhoek Municipality\n\n");

    printf("Enter Municipality Name: ");
    scanf("%49s", municipality);

    printf("Enter Mayor: ");
    scanf("%49s", mayor);

    printf("Enter Population: ");
    scanf("%d", &population);

    printf("\n---------------------------------\n");
    printf("Municipality : %s\n", municipality);
    printf("Mayor       : %s\n", mayor);
    printf("Population  : %d\n", population);

    printf("\nPress 1 if you want to calculate the Budget: ");
    scanf("%d", &calbudget);

    if (calbudget == 1) {
        budget();
    }

    printf("\nAs of today 18 Aug 2026 @ 12:35\n");

    return 0;
}