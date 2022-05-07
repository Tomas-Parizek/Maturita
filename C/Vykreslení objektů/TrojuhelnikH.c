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
    printf("Vykreslení horního trojúhelníku\n");
    int vyska = zadani(5, 50, "Zadejte, prosím, výšku trojúhelníku: ");
    int sirka = 2 * vyska - 1;

    for (int i = 1; i <= sirka; i += 2)
    {
        for (int j = 0; j < (sirka-i)/2; j++)
            printf("  ");
        for (int j = 0; j < i; j++)
            printf("* ");
        putchar('\n');
    }
}