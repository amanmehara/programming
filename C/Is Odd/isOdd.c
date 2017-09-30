#include <stdio.h>
#include <stdbool.h>

bool isOdd(int number)
{
    /* 
    An odd number is an integer of the form n=2k+1, where k is an integer.
    The congruence n ≡ 1 (mod2) holds for odd n.
    */

    // If the number is not divisible by 2 then return true
    return number % 2 == 1 ? true : false;
}