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
    printf("Vykreslení pravého trojúhelníku\n");
    int sirka = zadani(5, 50, "Zadejte, prosím, šířku trojúhelníku: ");

    for (int i = 1; i <= sirka; i++)
    {
        for (int j = 0; j < i; j++)
            printf("* ");
        putchar('\n');
    }
    for (int i = sirka-1; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
            printf("* ");
        putchar('\n');
    }
}