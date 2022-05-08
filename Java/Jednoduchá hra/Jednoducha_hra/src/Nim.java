import java.util.Scanner;

public class Nim {

    public static void main(String []args)
    {
        int pocetKamenu = zadani(10, 20, "Zadej, s kolika kameny si přeješ začít: ");
        int zadano;

        for (;;)
        {
            promaz();
            System.out.println("Máš " + pocetKamenu + " kamenů.");
            zadano = zadani(1, Math.min(3, pocetKamenu), "Kolik jich chceš vzít? (1 - 3): ");

            pocetKamenu -= zadano;

            if (pocetKamenu == 0)
            {
                vyhra();
                System.exit(0);
            }

            zadano = zadavaPC(pocetKamenu, zadano);
            System.out.println("Počítač bere " + zadano + " kamenů.");
            pocetKamenu -= zadano;

            if (pocetKamenu == 0)
            {
                prohra(zadano);
                System.exit(0);
            }
        }
    }

    static void vyhra()
    {
        System.out.println("Vyhrál jsi!\n\n");
    }

    static void prohra(int zadano)
    {
        System.out.println("Počítač vzal poslední " + zadano + " kameny, a vyhrál!\n\n");
    }

    static int zadavaPC(int pocetKamenu, int zadano)
    {
        if (pocetKamenu >= 1 && pocetKamenu <= 3)
            return pocetKamenu;
        else if (pocetKamenu >= 5 && pocetKamenu <= 7)
            return pocetKamenu - 4;
        else return 4 - zadano;
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

    static void promaz()
    {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }
}
