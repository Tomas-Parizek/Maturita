using System;

namespace Práce_s_poli
{
    class Program
    {
        static void Main()
        {
            int[] pole = new int[8];
            
            Console.WriteLine("Práce s poli");
            int n = ZadaniPole(pole);
            Console.Clear();
            VypisPole(pole);

            int[] poleBinarek = new int[n];
            NaplnBinarkami(pole, poleBinarek);
            VypisPole(poleBinarek);
            Prevodnik prevodnik = new Prevodnik(poleBinarek);
            Console.WriteLine(prevodnik.Preved());
        }

        private static int Zadani(int min, int max, string hlaska)
        {
            int cislo = min - 1;
            while (!(cislo >= min && cislo <= max))
            {
                Console.Write(hlaska);
                cislo = int.Parse(Console.ReadLine()!);
            }

            return cislo;
        }

        private static int ZadaniPole(int[] pole)
        {
            int pocetBinarek = 0;
            int delka = pole.Length;
            for (int i = 0; i < delka; i++)
            {
                pole[i] = Zadani(0, 9, "Zadej " + (i + 1) + ". hodnotu: ");
                if (pole[i] == 0 || pole[i] == 1)
                    pocetBinarek++;
            }

            return pocetBinarek;
        }

        static void VypisPole(int[] pole)
        {
            int delka = pole.Length;
            for (int i = 0; i < delka; i++)
                Console.Write(pole[i] + " ");
            Console.WriteLine();
        }

        static void NaplnBinarkami(int[] zdroj, int[] cil)
        {
            int delka = zdroj.Length;
            int index = 0;
            for (int i = 0; i < delka; i++)
            {
                if (zdroj[i] == 0 || zdroj[i] == 1)
                {
                    cil[index] = zdroj[i];
                    index++;
                }
            }
        }
    }
}