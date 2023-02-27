using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DecimalOperations;
using DecimalOperationsTester;
using HelperForDecimal;
namespace Decimal
{
    public class OperationManager
    {
        private decimal[] _numbers;
        private string _typeOfOperation;
        private int _convertedInt = 0;
        private float _convertedFloat = 0;
        private decimal _convertedDecimal = 0;

        public OperationManager(string[] argv)
        {
            _typeOfOperation = argv[argv.Length - 1];
            if (argv.Length > 4)
            {
                _numbers = DecimalHelper.GetDecimalsFromArguments(argv);
                _convertedDecimal = _numbers[0];
                return;
            }

            _numbers = Array.Empty<decimal>();
            if (int.TryParse(argv[0], out int res))
            {
                _convertedInt = res;
            }
            else if (float.TryParse(argv[0], out float result))
            {
                _convertedFloat = result;
            }

        }

        public string GetResult()
        {
            if (_typeOfOperation.IsArithmeticOperations())
            {
                return GetResultFromArithmeticOperation();
            }
            if (_typeOfOperation.IsComparerOperations())
            {
                return GetResultFromComparerOperation();
            }
            if (_typeOfOperation.IsConvertOperation())
            {
                return GetResultFromConverterOperation();
            }
            if (_typeOfOperation.IsUnaryOperations())
            {
                return GetResultFromUnaryOperation();
            }
            return "1";
        }

        private string GetResultFromArithmeticOperation()
        {
            try
            {
                var resultOfCalc = ArithmeticOperations.Execute(_typeOfOperation, _numbers[0], _numbers[1]);
                return "0 " + resultOfCalc.GetIntArrayString();
            }
            catch (OverflowException)
            {
                return ArithmeticOperations.DetermineOverflow(_numbers[0], _numbers[1], _typeOfOperation);
            }
            catch (DivideByZeroException)
            {
                return "3";
            }
        }


        private string GetResultFromComparerOperation()
        {
            try
            {
                var resultOfCalc = ComparerOperations.Execute(_typeOfOperation, _numbers[0], _numbers[1]);
                return "0 " + resultOfCalc.ToString();
            }
            catch (Exception)
            {
                return "1";
            }
        }

        private string GetResultFromConverterOperation()
        {
            try
            {
                return "0 " + ConvertOperations.Execute(_typeOfOperation, _convertedDecimal, _convertedFloat, _convertedInt);
            }
            catch (Exception)
            {
                return "1";
            }

        }

        private string GetResultFromUnaryOperation()
        {
            try
            {
                return "0 " + UnaryOperations.Execute(_typeOfOperation, _numbers[0]).GetIntArrayString();
            }
            catch (Exception)
            {
                return "1";
            }

        }
    }
}
