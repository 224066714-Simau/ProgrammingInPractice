#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"

void generateReport(void)
{
    printf("\n");
    printLine();

    printf("       MFMS SUMMARY REPORT\n");

    printLine();

    printf("\nEMPLOYEE INFORMATION\n");
    printLine();
    displayEmployees();

    printf("\nBUDGET INFORMATION\n");
    printLine();
    displayBudgets();

    printLine();

    printf("End of summary report.\n");
}