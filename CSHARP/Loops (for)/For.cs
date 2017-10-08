using System;

namespace Programming
{
    class For
    {
        static void Main(string[] args)
        {
            // Example 1
            for (int i = 1; i <= 5; i++)
            {
                Console.WriteLine("Hello, World!");
            }
            Console.WriteLine();

            // Example 2
            for (int i = 2; i <= 8; i++)
            {
                Console.WriteLine(i);
            }
            Console.WriteLine();

            // Example 3
            int iOuter = 48;
            int isPositive = -400;
            for (; isPositive < 0; )
            {
                Console.WriteLine("Inside the loop : isPositive = {0}", isPositive);
                isPositive += iOuter;
                iOuter += 48;
            }
            Console.WriteLine();

            // Example 4
            for (int iA = 4, iB = 16; iA < iB; iA++, iB--)
            {
                Console.WriteLine("iA = {0}, iB = {1}", iA, iB);
            }
            Console.WriteLine();
        }
    }
}