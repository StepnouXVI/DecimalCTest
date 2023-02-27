namespace DecimalGenerator
{
    class Program
    {
        static void Main(string[] argv)
        {
            var controller = new RequestController(argv);
            controller.AnswerRequest();
        }
    }
}