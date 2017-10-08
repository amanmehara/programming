namespace Programming
{
    class ArrayInitialization
    {
        static void Main(string[] args)
        {
            //Single-dimensional array

            //Example 1
            int[] numbersOne = new int[5] { 1, 2, 3, 4, 5 };
            string[] namesOne = new string[3] { "Matt", "Joanne", "Robert" };


            //Example 2
            int[] numbersTwo = new int[] { 1, 2, 3, 4, 5 };
            string[] namesTwo = new string[] { "Matt", "Joanne", "Robert" };

            //Example 3
            int[] numbersThree = { 1, 2, 3, 4, 5 };
            string[] namesThree = { "Matt", "Joanne", "Robert" };

            //Multidimensional array

            //Example 1
            int[,] valuesOne = new int[3, 2] { { 1, 2 }, { 3, 4 }, { 5, 6 } };
            string[,] siblingsOne = new string[2, 2] { { "Mike", "Amy" }, { "Mary", "Albert" } };

            //Example 2
            int[,] valuesTwo = new int[,] { { 1, 2 }, { 3, 4 }, { 5, 6 } };
            string[,] siblingsTwo = new string[,] { { "Mike", "Amy" }, { "Mary", "Albert" } };

            //Example 3
            int[,] valuesThree = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
            string[,] siblingsThree = { { "Mike", "Amy" }, { "Mary", "Albert" } };

            //array-of-arrays (Jagged array)

            //Example 1
            int[][] jaggedOne = new int[2][] { new int[] { 2, 3, 4 }, new int[] { 5, 6, 7, 8, 9 } };

            //Example 2
            int[][] jaggedTwo = new int[][] { new int[] { 2, 3, 4 }, new int[] { 5, 6, 7, 8, 9 } };

            //Example 3
            int[][] jaggedThree = { new int[] { 2, 3, 4 }, new int[] { 5, 6, 7, 8, 9 } };
        }
    }
}