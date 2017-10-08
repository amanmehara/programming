using System;

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

    class TestMotorcycle : Motorcycle
    {

        public override double GetTopSpeed()
        {
            return 246.81;
        }
    }

    class MethodAccess
    {
        static void Main(string[] args)
        {
            // This is the Main method 
            TestMotorcycle myMotorcycle = new TestMotorcycle();

            myMotorcycle.StartEngine();

            // AddGas(int) method of Motorcycle class can not be accessed as it is protected

            myMotorcycle.Drive(5, 20);
            double speed = myMotorcycle.GetTopSpeed();

            Console.WriteLine("My top speed is {0}", speed);
        }
    }
}