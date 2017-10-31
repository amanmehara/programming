#include <iostream>
#include <cmath>

double geometricProgression(double firstTerm, double commonRatio, int numberOfTerms)
{
    return firstTerm * std::pow(commonRatio, numberOfTerms - 1);
}

int main()
{
    double firstTerm = 0;
    double commonRatio = 0;
    int numberOfTerms = 0;

    std::cout << "First term: ";
    std::cin >> firstTerm;

    std::cout << "Common ratio: ";
    std::cin >> commonRatio;

    std::cout << "Number of terms: ";
    std::cin >> numberOfTerms;

    for(int termIndex = 0; termIndex < numberOfTerms; termIndex++)
    {
        std::cout << geometricProgression(firstTerm, commonRatio, termIndex + 1) << std::endl;
    }

    return 0;
}