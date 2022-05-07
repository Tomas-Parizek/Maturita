#include <stdio.h>

int zadani(int min, int max, char * hlaska)
{
    int cislo = 0;
    while (!(cislo >= min && cislo <= max && cislo%2 == 1))
    {
        printf("%s", hlaska);
        scanf("%d", &cislo);
    }
    return cislo;
}

int main()
{
    printf("Vykreslení diamantu\n");
    int vyska = zadani(5, 49, "Zadejte výšku (5-49, liché číslo): ");

    for (int i = 1; i <= vyska; i += 2)
    {
        for (int j = 0; j < (vyska-i)/2; j++)
            printf("  ");
        for (int j = 0; j < i; j++)
            printf("* ");
        putchar('\n');
    }
    for (int i = vyska - 2; i >= 0; i -= 2)
    {
        for (int j = 0; j < (vyska-i)/2; j++)
            printf("  ");
        for (int j = 0; j < i; j++)
            printf("* ");
        putchar('\n');
    }
}