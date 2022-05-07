#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void napln(int pole[10])
{
    for (int i = 0; i < 10; i++)
        pole[i] = rand()%100;
}

void vypis(int pole[10])
{
    for (int i = 0; i < 10; i++)
        printf("%d ", pole[i]);
    putchar('\n');
}

void sort(int pole[10]) // Verze pana Skalky
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (pole[j] > pole[j+1])
            {
                int p = pole[j+1];
                pole[j+1] = pole[j];
                pole[j] = p;
            }
        }
    }
}

void sortVylepseny(int pole[10]) // Lehce vylepšená verze, vnořený cyklus nejezdí v každém opakování až nakonec
{
    for (int i = 9; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (pole[j] > pole[j+1])
            {
                int p = pole[j+1];
                pole[j+1] = pole[j];
                pole[j] = p;
            }
        }
    }
}

int main()
{
    srand(time(0));

    int pole[10];
    napln(pole);
    vypis(pole);
    //sort(pole);
    sortVylepseny(pole);
    vypis(pole);
}