using System;
using System.Threading;

namespace Jezdící_text
{
    internal static class Program
    {
        static void Main()
        {
            const int sirkaObrazovky = 80;
            //int SirkaObrazovky = Console.WindowWidth
            
            Console.WriteLine("Jezdící text");
            var text = Zadani("Zadej text: ");

            for (int a = 0; a < 5; a++)
                for (int i = 0; i < sirkaObrazovky; i++)
                    Vypsani(i, text, sirkaObrazovky);
        }

        private static string Zadani(string hlaska)
        {
            string a = "";
            while (a == "" || a!.Length > 30)
            {
                Console.Write(hlaska);
                a = Console.ReadLine();
            }

            return a;
        }

        static void Vypsani(int index, string text, int sirkaObrazovky)
        {
            Thread.Sleep(100);
            Console.Clear();

            if (index + text.Length > sirkaObrazovky)
            {
                int delka = 80 - index;
                Console.SetCursorPosition(index, 0);
                Console.Write(text.Substring(0, delka));
                
                Console.SetCursorPosition(0, 0);
                Console.Write(text.Substring(delka));
            }
            else
            {
                Console.SetCursorPosition(index, 0);
                Console.Write(text);
            }
        }
    }
}