using System;

namespace Programming
{
    class ArithmeticProgression
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Arithmetic Progression");
            Console.WriteLine();

            double firstTerm = 24;
            double commonDifference = 7.5;
            int numberOfTerms = 15;

            Console.WriteLine("first term: " + firstTerm);
            Console.WriteLine("common difference: " + commonDifference);
            Console.WriteLine("number of terms: " + numberOfTerms);
            Console.WriteLine();

            // Arithmetic Progression
            Console.WriteLine("Arithmetic Progression:");
            for (int i = 0; i < numberOfTerms; i++)
            {
                double ithTerm = firstTerm + i * commonDifference;
                Console.WriteLine(ithTerm);
            }
            Console.WriteLine();
        }
    }
}