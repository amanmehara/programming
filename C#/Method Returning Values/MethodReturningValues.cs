using System;

namespace Programming
{
    class MethodReturningValues
    {
        static void Main(string[] args)
        {
            MethodReturningValues dummyObject = new MethodReturningValues();
            int addition = dummyObject.AddTwoNumbers(24, 48);
            Console.WriteLine("Result of addition = {0}", addition);

            int square = dummyObject.SquareANumber(6);
            Console.WriteLine("Result of square = {0}", square);
        }

        public int AddTwoNumbers(int number1, int number2)
        {
            return number1 + number2;
        }

        public int SquareANumber(int number)
        {
            return number * number;
        }
    }
}