#include <stdio.h>
#include <stdlib.h>

void vykresliOkraje()
{
    for (int i = 0; i < 4; i++)
        printf("+-----+ ");
    putchar('\n');
}

void vykresliNaprazdno()
{
    for (int i = 0; i < 4; i++)
        printf("|     | ");
    putchar('\n');
}

void vykresliStredy(char odhaleno)
{
    for (int i = 0; i < 4; i++)
    {
        if ((odhaleno >> (3-i))%2)
            printf("|     | ");
        else
            printf("|  ?  | ");
    }
    putchar('\n');
}

void vykresliRadu(char odhaleno)
{
    vykresliOkraje();
    vykresliNaprazdno();
    vykresliStredy(odhaleno);
    vykresliNaprazdno();
    vykresliOkraje();
    putchar('\n');
}

void vykresliKarty(char odhaleno)
{
    char odhalenoPrvni = odhaleno >> 4;
    char odhalenoDruhe = odhaleno;

    vykresliRadu(odhalenoPrvni);
    putchar('\n');
    vykresliRadu(odhalenoDruhe);
    putchar('\n');
}

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

void vyhra(int pokusy)
{
    printf("Vyhráli jste, stálo vás to %d pokusů!\n\n\n", pokusy);
}

int main() {
    int prvniVolba, druhaVolba;
    char *karty[] = {"Pes", "Kočka", "Velbloud", "Velbloud",
                     "Velryba", "Kočka", "Velryba", "Pes"};
    unsigned char odhaleno = 0;
    int pokusy = 0;

    for (;;)
    {
        pokusy++;
        system("clear");
        vykresliKarty(odhaleno);
        prvniVolba = zadani(1, 8, "Zadej, prosím, první kartu: ") - 1;
        printf("%s\n", karty[prvniVolba]);
        druhaVolba = zadani(1, 8, "Zadej, prosím, druhou kartu: ") - 1;
        printf("%s\n", karty[druhaVolba]);

        if (prvniVolba == druhaVolba)
        {
            printf("Zadal jste dvakrát touž kartu!\n");
            getchar();
            getchar();
        }
        else if (karty[prvniVolba] == karty[druhaVolba])
        {
            if (!((odhaleno >> (7 - prvniVolba))%2))
            {
                odhaleno += 1 << (7 - prvniVolba);
                odhaleno += 1 << (7 - druhaVolba);
            }
            printf("Perfektní, karta uhodnuta!\n");
            getchar();
            getchar();
        }
        else
        {
            printf("Bohužel!\n");
            getchar();
            getchar();
        }

        if (odhaleno == 255)
        {
            vyhra(pokusy);
            return 0;
        }
    }
}
