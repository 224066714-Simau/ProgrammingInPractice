#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SUPPLIERS 50

typedef struct {
    char name[80];
    char email[100];
    char phone[30];
    char town[60];
} Supplier;

Supplier suppliers[MAX_SUPPLIERS];
int supplierCount = 0;

void readLine(const char *prompt, char *buffer, size_t size)
{
    printf("%s", prompt);

    if (fgets(buffer, (int)size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
    } else {
        buffer[0] = '\0';
    }
}

double readNumber(const char *prompt)
{
    char input[100];
    char *end;
    double number;

    while (1) {
        readLine(prompt, input, sizeof(input));
        number = strtod(input, &end);

        if (end != input && *end == '\0' && number >= 0) {
            return number;
        }

        printf("Invalid input. Enter a non-negative number.\n");
    }
}

void addSupplier(void)
{
    if (supplierCount >= MAX_SUPPLIERS) {
        printf("Supplier list is full.\n");
        return;
    }

    readLine("Enter supplier name: ",
             suppliers[supplierCount].name,
             sizeof(suppliers[supplierCount].name));

    if (suppliers[supplierCount].name[0] == '\0') {
        printf("Supplier name cannot be empty.\n");
        return;
    }

    readLine("Enter email: ",
             suppliers[supplierCount].email,
             sizeof(suppliers[supplierCount].email));

    readLine("Enter phone number: ",
             suppliers[supplierCount].phone,
             sizeof(suppliers[supplierCount].phone));

    readLine("Enter town: ",
             suppliers[supplierCount].town,
             sizeof(suppliers[supplierCount].town));

    supplierCount++;
    printf("Supplier added successfully.\n");
}

void displaySuppliers(void)
{
    int i;

    if (supplierCount == 0) {
        printf("No suppliers available.\n");
        return;
    }

    printf("\n--- Supplier List ---\n");

    for (i = 0; i < supplierCount; i++) {
        printf("\nSupplier %d\n", i + 1);
        printf("Name: %s\n", suppliers[i].name);
        printf("Email: %s\n", suppliers[i].email);
        printf("Phone: %s\n", suppliers[i].phone);
        printf("Town: %s\n", suppliers[i].town);
    }
}

void searchSupplier(void)
{
    char searchName[80];
    int i;
    int found = 0;

    readLine("Enter supplier name to search: ",
             searchName, sizeof(searchName));

    for (i = 0; i < supplierCount; i++) {
        if (strcmp(suppliers[i].name, searchName) == 0) {
            printf("Supplier found!\n");
            printf("Name: %s\n", suppliers[i].name);
            printf("Email: %s\n", suppliers[i].email);
            printf("Phone: %s\n", suppliers[i].phone);
            printf("Town: %s\n", suppliers[i].town);
            found = 1;
        }
    }

    if (!found) {
        printf("Supplier not found.\n");
    }
}

double calculateVAT(double amount, double rate)
{
    return amount * rate / 100.0;
}

double calculateSalary(double basic, double housing,
                       double transport, double tax)
{
    return basic + housing + transport - tax;
}

double calculateBudget(double revenue, double expenses)
{
    return revenue - expenses;
}

void calculateVATMenu(void)
{
    double amount = readNumber("Enter amount: ");
    double rate = readNumber("Enter VAT rate (%): ");
    double vat = calculateVAT(amount, rate);

    printf("VAT amount: %.2f\n", vat);
    printf("Total including VAT: %.2f\n", amount + vat);
}

void calculateSalaryMenu(void)
{
    double basic = readNumber("Enter basic salary: ");
    double housing = readNumber("Enter housing allowance: ");
    double transport = readNumber("Enter transport allowance: ");
    double tax = readNumber("Enter tax deduction: ");

    printf("Net salary: %.2f\n",
           calculateSalary(basic, housing, transport, tax));
}

void calculateBudgetMenu(void)
{
    double revenue = readNumber("Enter total revenue: ");
    double expenses = readNumber("Enter total expenses: ");
    double balance = calculateBudget(revenue, expenses);

    if (balance > 0) {
        printf("Budget surplus: %.2f\n", balance);
    } else if (balance < 0) {
        printf("Budget deficit: %.2f\n", -balance);
    } else {
        printf("The budget is balanced.\n");
    }
}

int main(void)
{
    int choice;

    do {
        printf("\n===== MFMS WEEK 7-8 =====\n");
        printf("1. Add supplier\n");
        printf("2. Display suppliers\n");
        printf("3. Search supplier\n");
        printf("4. Calculate VAT\n");
        printf("5. Calculate net salary\n");
        printf("6. Calculate budget balance\n");
        printf("0. Exit\n");

        choice = (int)readNumber("Choose an option: ");

        switch (choice) {
            case 1:
                addSupplier();
                break;
            case 2:
                displaySuppliers();
                break;
            case 3:
                searchSupplier();
                break;
            case 4:
                calculateVATMenu();
                break;
            case 5:
                calculateSalaryMenu();
                break;
            case 6:
                calculateBudgetMenu();
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }

    } while (choice != 0);

    return 0;
}