using Decimal;
using DecimalOperations;
using HelperForDecimal;

namespace STM
{
    class Program
    {

        static void Main(string[] argv)
        {
            var operationManager = new OperationManager(argv);

            Console.WriteLine(operationManager.GetResult());
        }
    }

}
