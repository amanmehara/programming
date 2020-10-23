#include <iostream>
using namespace std;

int recurfun(int n)
{
if(n<10)
return n;
return recurfun(n/10)+n%10;
}
int main()
{
    int input;
    cin>>input;
    int output=recurfun(input);
    std::cout <<"sum of digit="<<output<< std::endl;
    return 0;
}
