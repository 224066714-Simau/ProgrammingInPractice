#include <stdio.h>

int main(void)
{
    char supplierName[50];
    float tenderPrice, budget;
    int registered, documentsComplete;

    printf("===== TENDER EVALUATION SYSTEM =====\n");

    printf("Enter supplier name (one word): ");
    if (scanf("%49s", supplierName) != 1) {
        printf("Invalid input. Try again.\n");
        return 1;
    }

    printf("Enter tender price: ");
    if (scanf("%f", &tenderPrice) != 1 || tenderPrice < 0) {
        printf("Invalid tender price.\n");
        return 1;
    }

    printf("Enter available budget: ");
    if (scanf("%f", &budget) != 1 || budget < 0) {
        printf("Invalid budget.\n");
        return 1;
    }

    printf("Is the supplier registered? (1 = Yes, 0 = No): ");
    if (scanf("%d", &registered) != 1 ||
        (registered != 0 && registered != 1)) {
        printf("Enter 1 or 0 only.\n");
        return 1;
    }

    printf("Are all required documents complete? (1 = Yes, 0 = No): ");
    if (scanf("%d", &documentsComplete) != 1 ||
        (documentsComplete != 0 && documentsComplete != 1)) {
        printf("Enter 1 or 0 only.\n");
        return 1;
    }

    printf("\n===== EVALUATION RESULT =====\n");
    printf("Supplier: %s\n", supplierName);
    printf("Tender price: %.2f\n", tenderPrice);
    printf("Available budget: %.2f\n", budget);

    if (registered == 1 &&
        documentsComplete == 1 &&
        tenderPrice <= budget) {
        printf("Result: QUALIFIED\n");
    } else {
        printf("Result: DISQUALIFIED\n");
    }

    return 0;
}