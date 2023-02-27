using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace DecimalOperationsTester
{
    public static class ComparerOperations
    {
        public static bool IsComparerOperations(this string typeOfOperation)
        {
            return _Operations.ContainsKey(typeOfOperation);
        }

        public static bool Execute(string typeOfOperation, decimal number_1, decimal number_2)
        {
            return _Operations[typeOfOperation](number_1, number_2);
        }

        private static Dictionary<string, Comparator> _Operations { get; } = new Dictionary<string, Comparator>
        {
            { "LESS", (x, y)=> x > y},
            { "MORE", (x, y)=> x < y },
            { "MORE_OR_EQUAL", (x, y)=> x >= y},
            {"EQUAL", (x, y)=> x == y },
            {"LESS_OR_EQUAL", (x, y)=> x <= y },
            {"NOT_EQUAL", (x, y)=> x != y }
        };
        private delegate bool Comparator(decimal num1, decimal num2);
    }
}