using System;

namespace Nim
{
    class Program
    {
        static void Main()
        {
            int pocetKamenu = Zadani(10, 20, "Zadej, prosím, počet kamenů (10 - 20): ");
            int zadano;
            
            Console.Clear();
            for (;;)
            {
                Console.WriteLine("Máš " + pocetKamenu + " kamenů.");
                zadano = Zadani(1, Math.Min(pocetKamenu, 3), "Kolik jich chceš vzít? (1 - 3): ");
                pocetKamenu -= zadano;

                if (pocetKamenu == 0)
                {
                    Vyhra();
                    Environment.Exit(0);
                }

                zadano = ZadavaPC(pocetKamenu, zadano);
                Console.WriteLine("Počítač bere " + zadano + " kamenů.");
                pocetKamenu -= zadano;

                if (pocetKamenu == 0)
                {
                    Prohra(zadano);
                    Environment.Exit(0);
                }
                Console.WriteLine("\n\n");
            }
        }

        static void Prohra(int zadano)
        {
            Console.Clear();
            Console.WriteLine("Prohrál jsi. Počítač vzal poslední " + zadano + ", a vyhrál.\n\n");
        }

        static void Vyhra()
        {
            Console.Clear();
            Console.WriteLine("Výborně, vyhrál jsi.\n");
        }

        private static int ZadavaPC(int celkovyPocet, int zadano)
        {
            if (celkovyPocet >= 1 && celkovyPocet <= 3)
                return celkovyPocet;
            if (celkovyPocet >= 5 && celkovyPocet <= 7)
                return celkovyPocet-4;
            return (4 - zadano);
        }
        static int Zadani(int min, int max, string hlaska)
        {
            int cislo = min - 1;
            while (!(cislo >= min && cislo <= max))
            {
                Console.Write(hlaska);
                cislo = int.Parse(Console.ReadLine()!);
            }

            return cislo;
        }
    }
}
