using System;

namespace Programming
{
    class While
    {
        static void Main(string[] args)
        {
            // Example 1
            int n = 1;
            Console.WriteLine("Example 1:");
            while (n < 6)
            {
                Console.WriteLine("Current value of n is {0}", n);
                n++;
            }
            Console.WriteLine();

            // Example 2
            int p = 1;
            Console.WriteLine("Example 2:");
            while (p++ < 6)
            {
                Console.WriteLine("Current value of p is {0}", p);
            }
            Console.WriteLine();

            // Example 3
            int q = 5;
            Console.WriteLine("Example 3:");
            while (++q < 6)
            {
                Console.WriteLine("Current value of q is {0}", q);
            }
            Console.WriteLine();

            // Example 4
            int t = 5;
            Console.WriteLine("Example 4:");
            while (t <= 10)
            {
                Console.WriteLine("Current value of t is {0}", t);
                if (t % 3 == 0)
                {
                    Console.WriteLine("{0} is a multiple of 3", t);
                    break;
                }
                t++;
            }
            Console.WriteLine();
        }
    }
}