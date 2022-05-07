#include <stdio.h>

int zadani(int min, int max, char * hlaska)
{
    int cislo = min - 1;
    while (!(cislo >= min && cislo <= max))
    {
        printf("%s", hlaska);
        scanf("%d", &cislo);
    }
    return cislo;
}

int main()
{
    printf("Vykreslení levého horního trojúhelníku\n");
    int velikost = zadani(5, 50, "Zadej prosím velikost trojúhelníku (5 - 50): ");

    for (int i = velikost; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
            printf("* ");
        putchar('\n');
    }
}