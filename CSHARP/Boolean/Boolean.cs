using System;

namespace Programming
{
    class Boolean
    {
        static void Main(string[] args)
        {
            bool b = true;

            // WriteLine automatically converts the value of b to text.
            Console.WriteLine(b);

            int today = DateTime.Now.DayOfYear;

            // Assign the result of a boolean expression to b.
            b = (today % 2 == 0);

            // Branch depending on whether b is true or false. 
            if (b)
            {
                Console.WriteLine("today: {0} (Day Of Year) is even.", today);
            }
            else
            {
                Console.WriteLine("today: {0} (Day Of Year) is odd.", today);
            }
        }
    }
}