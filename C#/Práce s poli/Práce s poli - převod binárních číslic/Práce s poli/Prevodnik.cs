namespace Práce_s_poli
{
    public class Prevodnik
    {
        private readonly int[] _pole;

        public Prevodnik(int[] pole)
        {
            this._pole = pole;
        }

        public int Preved()
        {
            int vysledek = 0;
            int index = 1;
            for (int i = _pole.Length - 1; i >= 0; i--)
            {
                vysledek += _pole[i] * index;
                index *= 2;
            }

            return vysledek;
        }
    }
}