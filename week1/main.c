#include <stdio.h>

int main(void)
{
    char municipalityName[100];
    char mayorName[100];
    int population;

    printf("====================================\n");
    printf("   WELCOME TO WINDHOEK MUNICIPALITY\n");
    printf("====================================\n\n");

    printf("Enter municipality name: ");
    if (scanf(" %99[^\n]", municipalityName) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter mayor's name: ");
    if (scanf(" %99[^\n]", mayorName) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter population: ");
    if (scanf("%d", &population) != 1 || population < 0) {
        printf("Invalid population.\n");
        return 1;
    }

    printf("\n====================================\n");
    printf("       MUNICIPALITY INFORMATION\n");
    printf("====================================\n");
    printf("Municipality: %s\n", municipalityName);
    printf("Mayor:        %s\n", mayorName);
    printf("Population:   %d\n", population);
    printf("====================================\n");

    return 0;
}