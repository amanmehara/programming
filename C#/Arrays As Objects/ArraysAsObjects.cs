using System;

namespace Programming
{
    class ArraysAsObjects
    {
        static void Main(string[] args)
        {

            int[] numbersArray = { 1, 2, 3, 4, 5 };
            Console.WriteLine("numbersArray:");
            foreach (int i in numbersArray)
            {
                Console.WriteLine(i);
            }

            Console.WriteLine();

            int lengthOfNumbers = numbersArray.Length;
            Console.WriteLine("Length of numbersArray is {0}", lengthOfNumbers);

            Console.WriteLine();

            int[,] theArray = new int[5, 10];
            Console.WriteLine("theArray has {0} dimensions.", theArray.Rank);
        }
    }
}