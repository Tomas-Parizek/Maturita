using System;

namespace Pexeso
{
    class Program
    {
        static void Main()
        {
            int prvniVolba, druhaVolba;
            string[] karty = new string[]
            {
                "Pes", "Kočka", "Velbloud", "Velbloud",
                "Velryba", "Kočka", "Velryba", "Pes"
            };
            byte odhaleno = 0;
            int pokusy = 0;

            for (;;)
            {
                pokusy++;
                Console.Clear();
                Vykreslování.VykresliKarty(odhaleno);
                prvniVolba = Zadani(1, 8, "Zadej první kartu, kterou chceš zvolit (1 - 8): ")-1;
                Console.WriteLine(karty[prvniVolba]);
                druhaVolba = Zadani(1, 8, "Zadej druhou kartu, kterou chceš zvolit (1 - 8): ")-1;
                Console.WriteLine(karty[druhaVolba]);

                if (prvniVolba == druhaVolba)
                {
                    Console.WriteLine("Zadal jste dvakrát touž kartu!");
                    Console.ReadKey();
                }
                else if (karty[prvniVolba] == karty[druhaVolba])
                {
                    odhaleno += (byte) (1 << (7 - prvniVolba));
                    odhaleno += (byte) (1 << (7 - druhaVolba));
                    Console.WriteLine("Výborně, karta uhodnuta!");
                    Console.ReadKey();
                }
                else
                {
                    Console.WriteLine("Bohužel!");
                    Console.ReadKey();
                }

                if (odhaleno == 255)
                {
                    Vyhra(pokusy);
                    Environment.Exit(0);
                }
            }
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

        static void Vyhra(int pokusy)
        {
            Console.WriteLine("Výborně, vyhrál jsi, stálo tě to " + pokusy + " pokusů.");
        }
    }
}