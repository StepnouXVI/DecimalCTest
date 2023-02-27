using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Diagnostics.Contracts;
using System.Globalization;
using System.Linq;
using System.Threading.Tasks;
using HelperForDecimal;

namespace DecimalGenerator
{
    public class RequestController
    {
        private string _TypeOfOperation { get; }
        private decimal[] _Numbers { get; }
        int _NumberOfValue = 0;

        public RequestController(string[] argv)
        {
            _TypeOfOperation = argv[0];
            _NumberOfValue = int.Parse(argv[1]);
            _Numbers = DecimalHelper.GetDecimalsFromArguments(argv.Skip(2));
        }


        public void AnswerRequest()
        {
            decimal generatedDecimal;
            if (_Numbers.Length == 2)
            {
                generatedDecimal = DecimalGenerator.Generators[_TypeOfOperation](_Numbers[0], _NumberOfValue, _Numbers[1]);
            }
            else
            {
                generatedDecimal = DecimalGenerator.Generators[_TypeOfOperation](_Numbers[0], _NumberOfValue);
            }

            generatedDecimal.Print();
        }
    }
}