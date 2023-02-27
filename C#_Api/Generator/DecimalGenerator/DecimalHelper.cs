using System;
using System.Globalization;
using System.Linq;
using System.Runtime.InteropServices;

namespace HelperForDecimal
{
    public static class DecimalHelper
    {
        public static void Print(this decimal value)
        {
            System.Console.WriteLine(value.GetIntArrayString());
        }
        public static Decimal GetDecimalFromString(IEnumerable<string> stringDecimal)
        {
            int[] _parts = Array.ConvertAll(stringDecimal.ToArray(),
                x => int.Parse(x.Replace(".", ","))
            );

            return new Decimal(_parts);
        }

        public static decimal[] GetDecimalsFromArguments(IEnumerable<string> decimals)
        {
            var size = decimals.Count() / 4;
            var array = new decimal[size];

            for (int i = 0; i < size; i++)
            {
                array[i] = GetDecimalFromString(decimals.Skip(i * 4)
                .Take(4));
            }
            return array;
        }

        public static string GetIntArrayString(this Decimal number)
        {
            var numbers = Decimal.GetBits(number);

            return $"{numbers[0]} {numbers[1]} {numbers[2]} {numbers[3]}";
        }

        public static void Write(this List<Decimal> numbers)
        {
            if (numbers is not null)
                foreach (var number in numbers)
                {
                    System.Console.WriteLine(number.GetIntArrayString());
                }
        }
    }
}