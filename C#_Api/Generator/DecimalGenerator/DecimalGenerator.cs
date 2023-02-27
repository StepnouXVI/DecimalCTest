using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Threading.Tasks;

namespace DecimalGenerator
{
    public static class DecimalGenerator
    {

        public static decimal GetNumberFromRange(decimal start, int numberOfValue, decimal step = 0.01m)
        {
            return decimal.Add(start, decimal.Multiply(step, numberOfValue));
        }

        public static decimal GetNumberNearPoint(decimal point, int numberOfValue, decimal step = 0.01m)
        {
            return point switch
            {
                decimal.MaxValue => decimal.Add(decimal.Subtract(point, decimal.One), decimal.Multiply(step, numberOfValue)),
                decimal.MinValue => decimal.Add(decimal.Add(point, decimal.One), decimal.Multiply(step, (-1) * numberOfValue)),
                _ => decimal.Add(decimal.Subtract(point, decimal.One), decimal.Multiply(step, numberOfValue))
            };
        }

        public static readonly Dictionary<string, Generate> Generators = new Dictionary<string, Generate>{
            {"GET_DECIMAL_FROM_RANGE", GetNumberFromRange},
            {"GET_DECIMAL_NEAR_POINT", GetNumberNearPoint}
        };
        public delegate decimal Generate(decimal point, int numberOfValue, decimal step = 0.01m);
    }
}