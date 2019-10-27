#include <stdio.h>


int main()
{

   int counter, number;
   unsigned long long factorial = 1;

   printf(" Enter a Positive number: ");
   scanf("%d" , &number);
   

   
   while( number < 0)
   {
      printf(" Invalid Number! Please enter a positive number: ");
      scanf("%d" , &number);
   }

   for(counter = 1; counter <= number; counter++)
   {
      factorial = counter * factorial;
   }
   
   printf(" Factorial of %d = %llu" , number, factorial);
   
   return 0;
   } 

