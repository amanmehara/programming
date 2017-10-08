using System;

namespace Programming
{
    class DoWhile
    {
        static void Main(string[] args)
        {
            int x = 0;
            do
            {
                Console.WriteLine(x);
                x++;
            } while (x < 5);
        }
    }
}