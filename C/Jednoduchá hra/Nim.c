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

}