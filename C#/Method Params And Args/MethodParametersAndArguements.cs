namespace Programming
{
    class MethodParametersAndArguements
    {
        static void Main(string[] args)
        {
            int numA = 4;
            // Call with an int variable. 
            int productA = Square(numA);
            // numA is the arguement

            int numB = 32;
            // Call with another int variable. 
            int productB = Square(numB);
            // numB is the arguement

            // Call with an integer literal. 
            int productC = Square(12);
            // 12 is the arguement

            // Call with an expression that evaulates to int.
            productC = Square(productA * 3);
            // (productA * 3) is an arguement
        }

        // i is the parameter
        static int Square(int i)
        {
            // Store input argument in a local variable. 
            int input = i;
            return input * input;
        }
    }
}