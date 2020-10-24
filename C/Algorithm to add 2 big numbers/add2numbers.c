// Copyright 2020 Ashish Kumar
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

//This program can add two numbers which are in the range 0 <= A , B <= 10^98

#include <stdio.h>
int main()
{
    char *a = (char *)malloc(100), *b = (char *)malloc(100); //to add even larger numbers increase the number of bytes allocated in the malloc.
    while (scanf("%s%s", a, b) != -1)                        // to take input till end of file is not reached
    {
        int big, carry = 0, temp, small;
        int aa = strlen(a) >= strlen(b) ? strlen(a) : strlen(b);

        char *sum = (char *)malloc(aa + 1);
        if (strlen(a) >= strlen(b))     //these if statements will assign the length of the bigger string(if any)
        {                               //to big variable and smaller to small variable.
            big = strlen(a);            //And also variable "a" will point to the bigger string and "b" will point to the
            small = strlen(b);          //smaller string.
        }                               // Doing all this coz in the below for loop we need to run it "length of bigger string" times.
        else if (strlen(a) < strlen(b)) //Also we have to know that which "ptr to char variable" among a & b points to the bigger string if there is a diff in length of both the strings.
        {
            big = strlen(b);
            small = strlen(a);
            char *tem = a;
            a = b;
            b = tem;
        }
        for (int i = big - 1, j = small - 1; i >= 0; i--, j--) // this loop performs addition of numbers just as we do.
        {
            if (j < 0) //if the smaller string reaches 0 index and there are indexes left in bigger string then code in this if block should execute.
            {
                temp = a[i] + carry - 48;
                if (temp >= 0 && temp <= 9)
                {
                    sum[i] = temp + 48;
                    carry = 0;
                }
                else
                {
                    sum[i] = (temp - 10) + 48;
                    carry = 1;
                }
            }

            else
            {
                temp = a[i] + b[j] + carry - 96;

                if (temp >= 0 && temp <= 9)
                {
                    sum[i] = temp + 48;
                    carry = 0;
                }
                else
                {
                    sum[i] = (temp - 10) + 48;
                    carry = 1;
                }
            }
        }
        sum[aa] = '\0'; //if we add 999 & 2 then by the above for loop we would get 001 in sum array and the value of carry when the control exits the loop will be 1
        if (carry == 1) //so here we are printing 1 ahead of the sum array so that the value displayed is 1001.
        {
            printf("1");
        }
        printf("%s\n", sum);
    }
    return 0;
}
