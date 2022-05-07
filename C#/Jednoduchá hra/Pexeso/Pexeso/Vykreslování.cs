using System;

namespace Pexeso
{
    public class Vykreslování
    {
        public static void VykresliOkraje()
        {
            for (int i = 0; i < 4; i++)
                Console.Write("+-----+ ");
            Console.WriteLine();
        }

        public static void VykresliNaprazdno()
        {
            for (int i = 0; i < 4; i++)
                Console.Write("|     | ");
            Console.WriteLine();
        }

        public static void VykresliStredy(byte odhaleno)
        {
            for (int i = 0; i < 4; i++)
            {
                if ((odhaleno >> (3 - i))%2 == 1)
                    Console.Write("|     | ");
                else
                    Console.Write("|  ?  | ");
            }
            Console.WriteLine();
        }

        public static void VykresliRadu(byte odhaleno)
        {
            VykresliOkraje();
            VykresliNaprazdno();
            VykresliStredy(odhaleno);
            VykresliNaprazdno();
            VykresliOkraje();
            Console.WriteLine();
        }

        public static void VykresliKarty(byte odhaleno)
        {
            byte odhalenoPrvni = (byte) (odhaleno >> 4);
            byte odhalenoDruhe = odhaleno;

            VykresliRadu(odhalenoPrvni);
            Console.WriteLine();
            VykresliRadu(odhalenoDruhe);
            Console.WriteLine();
        }
    }
}