#include <stdio.h>
#include <string.h>
#include "employees.h"

#define MAX_EMPLOYEES 100

typedef struct
{
    int id;
    char name[50];
    char department[50];
    double salary;
} Employee;

static Employee employees[MAX_EMPLOYEES];
static int employeeCount = 0;

void addEmployee(void)
{
    if (employeeCount >= MAX_EMPLOYEES)
    {
        printf("Employee list is full.\n");
        return;
    }

    Employee e;

    printf("Enter employee ID: ");
    if (scanf("%d", &e.id) != 1)
    {
        printf("Invalid ID.\n");
        while (getchar() != '\n');
        return;
    }

    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].id == e.id)
        {
            printf("Employee ID already exists.\n");
            return;
        }
    }

    printf("Enter employee name: ");
    scanf(" %49[^\n]", e.name);

    printf("Enter department: ");
    scanf(" %49[^\n]", e.department);

    printf("Enter salary: ");
    if (scanf("%lf", &e.salary) != 1 || e.salary < 0)
    {
        printf("Invalid salary.\n");
        while (getchar() != '\n');
        return;
    }

    employees[employeeCount++] = e;
    saveEmployees();

    printf("Employee added successfully.\n");
}

void displayEmployees(void)
{
    if (employeeCount == 0)
    {
        printf("No employees found.\n");
        return;
    }

    printf("\n--- Employee List ---\n");

    for (int i = 0; i < employeeCount; i++)
    {
        printf("ID: %d | Name: %s | Department: %s | Salary: %.2f\n",
               employees[i].id,
               employees[i].name,
               employees[i].department,
               employees[i].salary);
    }
}

void searchEmployee(void)
{
    int id;

    printf("Enter employee ID to search: ");

    if (scanf("%d", &id) != 1)
    {
        printf("Invalid ID.\n");
        while (getchar() != '\n');
        return;
    }

    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].id == id)
        {
            printf("Employee found: %s | Department: %s | Salary: %.2f\n",
                   employees[i].name,
                   employees[i].department,
                   employees[i].salary);
            return;
        }
    }

    printf("Employee not found.\n");
}

void saveEmployees(void)
{
    FILE *file = fopen("employees.txt", "w");

    if (file == NULL)
    {return; employeeCount = 0; while (employeeCount < MAX_EMPLOYEES && fscanf(file, "%d|%49[^|]|%49[^|]|%lf\n", &employees[employeeCount].id, employees[employeeCount].name, employees[employeeCount].department, &employees[employeeCount].salary) == 4) { employeeCount++; } fclose(file); }
    