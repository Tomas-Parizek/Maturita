import java.util.Random;

public class BubbleSort {

    public static void main(String [] args)
    {
        int[] pole = new int[10];

        napln(pole);
        vypis(pole);
        vylepsenySort(pole);
        //sort(pole);
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
        for (int i = 0; i < pole.length - 1; i++)
        {
            for (int j = 0; j < pole.length - 1; j++)
            {
                if (pole[j] > pole[j+1])
                {
                    int p = pole[j];
                    pole[j] = pole[j+1];
                    pole[j+1] = p;
                }
            }
        }
    }

    static void vylepsenySort(int[] pole)
    {
        for (int i = pole.length - 1; i >= 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (pole[j] > pole[j+1])
                {
                    int p = pole[j];
                    pole[j] = pole[j+1];
                    pole[j+1] = p;
                }
            }
        }
    }
}
