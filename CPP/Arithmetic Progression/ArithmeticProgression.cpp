#include <iostream>

double arithmeticProgression(double firstTerm, double commonDifference, int numberOfTerms)
{
    return firstTerm + commonDifference * (numberOfTerms - 1);
}

int main()
{
    double firstTerm = 0;
    double commonDifference = 0;
    int numberOfTerms = 0;

    std::cout << "First term: ";
    std::cin >> firstTerm;

    std::cout << "Common difference: ";
    std::cin >> commonDifference;

    std::cout << "Number of terms: ";
    std::cin >> numberOfTerms;

    for(int termIndex = 0; termIndex < numberOfTerms; termIndex++)
    {
        std::cout << arithmeticProgression(firstTerm, commonDifference, termIndex + 1) << std::endl;
    }

    return 0;
}