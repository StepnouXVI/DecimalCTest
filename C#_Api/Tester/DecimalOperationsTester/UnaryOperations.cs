using HelperForDecimal;

namespace DecimalOperations
{
    public static class UnaryOperations
    {

        public static bool IsUnaryOperations(this string typeOfOperation)
        {
            return _Operations.ContainsKey(typeOfOperation);
        }

        public static decimal Execute(string typeOfOperation, decimal number)
        {
            return _Operations[typeOfOperation](number);
        }

        private static Dictionary<string, Operation> _Operations { get; } = new Dictionary<string, Operation>
        {
            { "NEGATIVE", decimal.Negate },
            { "FLOOR", decimal.Floor },
            { "ROUND", decimal.Round },
            {"TRUNCATE", decimal.Truncate }
        };

        private delegate decimal Operation(decimal num);
    }
}