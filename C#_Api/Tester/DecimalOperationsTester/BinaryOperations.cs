using System;
using HelperForDecimal;

namespace DecimalOperations
{
    public static class ArithmeticOperations
    {


        public static bool IsArithmeticOperations(this string typeOfOperation)
        {
            return _Operations.ContainsKey(typeOfOperation);
        }

        public static decimal Execute(string typeOfOperation, decimal number_1, decimal number_2)
        {
            return _Operations[typeOfOperation](number_1, number_2);
        }

        public static string DetermineOverflow(decimal num1, decimal num2, string typeOfOperation)
        {
            num1 = decimal.Divide(num1, decimal.Abs(decimal.Subtract(decimal.Abs(num1), 10m)));
            num2 = decimal.Divide(num2, decimal.Abs(decimal.Subtract(decimal.Abs(num2), 10m)));
            var result = _Operations[typeOfOperation](num1, num2);
            if (result > num1 && result > num2)
            {
                return "1";
            }
            else
            {
                return "2";
            }
        }

        private static Dictionary<string, OperationWith2> _Operations { get; } = new Dictionary<string, OperationWith2>
        {
            { "SUM", decimal.Add },
            { "SUB", decimal.Subtract },
            { "MUL", decimal.Multiply },
            {"DIV", decimal.Divide },
            {"MOD", decimal.Remainder }
        };
        private delegate decimal OperationWith2(decimal num1, decimal num2);
    }

}