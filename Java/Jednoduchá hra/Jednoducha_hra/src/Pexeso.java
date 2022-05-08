import java.util.Scanner;

public class Pexeso {

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        // Uživatel má na výběr z osmi karet
        // Vždy si zadá první a druhou, vypíše se mu, co je na nich

        int prvniVolba, druhaVolba;
        String[] karty = new String[] {
                "Pes", "Kočka", "Velryba", "Velryba",
                "Velbloud", "Kočka", "Velbloud", "Pes"
        };

        int odhaleno = 0;
        int pokusy = 0;

        for (;;)
        {
            pokusy++;

            vykresliKarty(odhaleno);

            prvniVolba = zadani(1, 8, "Zadej, první kartu, kterou si přeješ otočit: ") - 1;
            System.out.println(karty[prvniVolba]);
            druhaVolba = zadani(1, 8, "Zadej, druhou kartu, kterou si přeješ otočit: ") - 1;
            System.out.println(karty[druhaVolba]);

            if (prvniVolba == druhaVolba) {
                System.out.println("Bohužel, otočil jsi dvakrát stejnou kartu!");
                scanner.nextLine();
            }
            else if (karty[prvniVolba] == karty[druhaVolba])
            {
                if ((odhaleno >> (7-prvniVolba))%2 != 1)
                {
                    odhaleno += 1 << (7 - prvniVolba);
                    odhaleno += 1 << (7 - druhaVolba);
                }
                System.out.println("Výborně, otočil jsi stejné karty!");
                scanner.nextLine();
            }
            else
            {
                System.out.println("Bohužel, otočil jsi dvě jiné karty!");
                scanner.nextLine();
            }

            if (odhaleno == 255)
            {
                vyhra(pokusy);
                System.exit(0);
            }
        }
    }

    static int zadani(int min, int max, String hlaska)
    {
        Scanner scanner = new Scanner(System.in);
        int cislo = min - 1;
        while (!(cislo >= min && cislo <= max))
        {
            System.out.print(hlaska);
            cislo = scanner.nextInt();
        }
        return cislo;
    }

    static void vyhra(int pokusy)
    {
        System.out.println("Výborně, vyhrál jsi, stálo tě to " + pokusy + " pokusů.\n\n");
    }

    static void vykresliKarty(int odhaleno)
    {
        int odhalenoPrvni = odhaleno >> 4;
        int odhalenoDruhe = odhaleno;

        vykresliRadu(odhalenoPrvni);
        vykresliRadu(odhalenoDruhe);
    }

    static void vykresliRadu(int odhaleno)
    {
        vykresliOkraje();
        vykresliNaprazdno();
        vykresliStredy(odhaleno);
        vykresliNaprazdno();
        vykresliOkraje();
        System.out.println();
    }

    static void vykresliOkraje()
    {
        for (int i = 0; i < 4; i++)
            System.out.print("+-----+ ");
        System.out.println();
    }

    static void vykresliNaprazdno()
    {
        for (int i = 0; i < 4; i++)
            System.out.print("|     | ");
        System.out.println();
    }

    static void vykresliStredy(int odhaleno)
    {
        for (int i = 0; i < 4; i++)
        {
            if ((odhaleno >> (3-i))%2 == 1)
                System.out.print("|     | ");
            else
                System.out.print("|  ?  | ");
        }
        System.out.println();
    }
}
