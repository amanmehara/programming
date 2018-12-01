using System;

namespace Programming
{
    class Clazz
    {
        static void Main(string[] args)
        {
            // Create objects by using the new operator
            ChildClazz childOne = new ChildClazz("Craig", 11);
            ChildClazz childTwo = new ChildClazz("Sally", 10);

            // Create an object using the default constructor
            ChildClazz childThree = new ChildClazz();

            // Display results
            Console.Write("ChildOne: ");
            childOne.PrintChild();
            Console.Write("ChildTwo: ");
            childTwo.PrintChild();
            Console.Write("ChildThree: ");
            childThree.PrintChild();
        }
    }

    class ChildClazz
    {
        private int age;
        private string name;

        // Default constructor 
        public ChildClazz()
        {
            name = "N/A";
        }

        // Constructor 
        public ChildClazz(string name, int age)
        {
            this.name = name;
            this.age = age;
        }

        // Printing method 
        public void PrintChild()
        {
            Console.WriteLine("{0}, {1} years old.", name, age);
        }
    }

}