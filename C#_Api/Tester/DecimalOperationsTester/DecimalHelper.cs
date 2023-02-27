using System.Runtime.InteropServices;

namespace HelperForDecimal
{
    public static class DecimalHelper
    {
        public static decimal GetDecimalFromArguments(string[] argv)
        {
            int[] _parts = Array.ConvertAll(argv.Take(4).ToArray(),
                x => int.Parse(x.Replace(".", ","))
            );

            return new decimal(_parts);
        }

        public static string GetIntArrayString(this decimal number)
        {
            var numbers = decimal.GetBits(number);

            return $"{numbers[0]} {numbers[1]} {numbers[2]} {numbers[3]}";
        }

        public static decimal[] GetDecimalsFromArguments(string[] argv)
        {
            var size = (argv.Length - 1) / 4;
            var array = new decimal[size];

            for (int i = 0; i < size; i++)
            {
                int[] _parts = new int[4];
                for (int j = 0; j < 4; j++)
                {
                    _parts[j] = (int.Parse(argv[i * 4 + j]));
                }
                array[i] = new decimal(_parts);
            }
            return array;
        }

    }
}