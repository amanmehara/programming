namespace Programming
{
    class ArrayInstantiation
    {
        static void Main(string[] args)
        {
            // Single-dimensional array
            int[] numbers = new int[5];

            // Multidimensional array
            string[,] names = new string[5, 4];

            // Array-of-arrays (jagged array)
            byte[][] scores = new byte[5][];
        }
    }
}