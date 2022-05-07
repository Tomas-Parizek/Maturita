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

void sort(int pole[10]) // Tento způsob třízení je značně neefektivní, nicméně je velice snadný na naprogramování i pochopení
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (pole[j] > pole[i])
            {
                int p = pole[i];
                pole[i] = pole[j];
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
    sort(pole);
    vypis(pole);
}