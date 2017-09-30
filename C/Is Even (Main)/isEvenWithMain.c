#include <stdio.h>
#include <stdbool.h>

bool isEven(int);

int main()
{

    printf("Is Even? \n");

    int number;
    printf("number = ");
    scanf("%d", &number);

    printf(isEven(number) ? "isEven(%d) -> true" : "isEven(%d) -> false", number);

    return 0;
}

bool isEven(int number)
{
    /* 
    An even number is an integer of the form n=2k, where k is an integer.
    The congruence n ≡ 0 (mod2) holds for even n.
    */

    // If the number is divisible by 2 then return true
    return number % 2 == 0 ? true : false;
}