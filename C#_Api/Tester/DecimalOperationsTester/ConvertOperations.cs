using System.Reflection.Metadata.Ecma335;
using System.Security.AccessControl;
using HelperForDecimal;

namespace DecimalOperations
{
    public static class ConvertOperations
    {
        private const string DecimalToFloat = "D2F";
        private const string DecimalToInt = "D2I";
        private const string FloatToDecimal = "F2D";
        private const string IntToDecimal = "I2D";

        public static bool IsConvertOperation(this string typeOfOperation)
        {
            return typeOfOperation switch
            {
                DecimalToFloat => true,
                DecimalToInt => true,
                FloatToDecimal => true,
                IntToDecimal => true,
                _ => false,
            };
        }
        public static string Execute(string typeOfOperation, decimal value_d, float value_f, int value_i)
        {

            var result = typeOfOperation switch
            {
                DecimalToFloat => ((float)value_d).ToString(),
                FloatToDecimal => new decimal(value_f).GetIntArrayString(),
                IntToDecimal => new decimal(value_i).GetIntArrayString(),
                DecimalToInt => decimal.ToInt64(value_d).ToString(),
                _ => "Error operation",
            };

            return result;
        }
    }
}