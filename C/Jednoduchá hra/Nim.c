#include <stdio.h>
#include <stdlib.h>

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

int min(int a, int b)
{
    if (a < b) return a;
    return b;
}

void vyhra()
{
    system("clear");
    printf("Vyhrál jsi.\n\n");
}

int zadavaPC(int celkovyPocet, int zadano)
{
    if (celkovyPocet >= 1 && celkovyPocet <= 3)
        return celkovyPocet;
    else if (celkovyPocet >= 5 && celkovyPocet <= 7)
        return celkovyPocet-4;
    else
        return (4 - zadano);
}

int main()
{
    int pocetKamenu = zadani(10, 20, "Zadej, kolik si chceš vytáhnout kamenů: ");
    int zadano;

    system("clear");
    // Na Windowsu system("cls");

    for (;;)
    {
        printf("Máš %d kamenů.\n", pocetKamenu);
        zadano = zadani(1, min(pocetKamenu, 3), "Kolik jich chceš vzít? (1-3: )");
        pocetKamenu -= zadano;

        if (pocetKamenu == 0)
        {
            vyhra();
            return 0;
        }

        zadano = zadavaPC(pocetKamenu, zadano);
        printf("Počítač bere %d kamenů.\n", zadano);
        pocetKamenu -= zadano;

        if (pocetKamenu == 0)
        {
            prohra(zadano);
            return 0;
        }

        printf("\n\n\n");
    }
}