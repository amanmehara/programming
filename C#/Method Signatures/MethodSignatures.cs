namespace Programming
{
    abstract class Motorcycle
    {
        // Anyone can call this. 
        public void StartEngine()
        {
            /* Method statements here */
        }

        // Only derived classes can call this. 
        protected void AddGas(int gallons)
        {
            /* Method statements here */
        }

        // Derived classes can override the base class implementation. 
        public virtual int Drive(int miles, int speed)
        {
            /* Method statements here */
            return 1;
        }

        // Derived classes must implement this. 
        public abstract double GetTopSpeed();
    }

    class MethodSignatures
    {
        static void Main(string[] args)
        {
            // This is the Main method 
        }
    }
}