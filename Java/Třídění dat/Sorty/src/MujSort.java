import java.util.Random;

public class MujSort {

    public static void main(String[] args) {
        int[] pole = new int[10];
        napln(pole);
        vypis(pole);
        sort(pole);
        vypis(pole);
    }

    static void napln(int[] pole)
    {
        Random random = new Random();

        for (int i = 0; i < pole.length; i++)
        {
            pole[i] = random.nextInt(100);
        }
    }

    static void vypis(int[] pole)
    {
        for (int clen : pole)
        {
            System.out.print(clen + " ");
        }
        System.out.println();
    }

    static void sort(int[] pole)
    {
        for (int i = 0; i < pole.length; i++)
        {
            for (int j = 0; j < pole.length; j++)
            {
                if (pole[j] > pole[i])
                {
                    int p = pole[j];
                    pole[j] = pole[i];
                    pole[i] = p;
                }
            }
        }
    }
}
