using System;

namespace Programming
{
    class Character
    {
        static void Main(string[] args)
        {
            char[] chars = new char[4];

            chars[0] = 'X';        // Character literal
            chars[1] = '\x0058';   // Hexadecimal
            chars[2] = (char)88;   // Cast from integral type
            chars[3] = '\u0058';   // Unicode 

            foreach (char c in chars)
            {
                Console.Write(c + "\n");
            }
        }
    }
}