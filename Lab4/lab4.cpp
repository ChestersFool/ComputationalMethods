#include <iostream>
#include <cmath>

using std::cout, std::cin;

int main()
{
    const int N = 10;
    int years[] = {8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    float y[] = {68.27, 69.29, 70.44, 71.02, 71.15, 71.37, 71.38, 71.68, 71.98, 71.76};

    float sumXY = 0, sumX = 0, sumY = 0, sumXSquare = 0, sumSquareX = 0;

    for (int i = 0; i < N; i++)
    {
        sumXY += years[i] * y[i];
        sumX += years[i];
        sumY += y[i];
        sumXSquare += pow(years[i], 2);
    }
    sumSquareX = sumX * sumX;

    float a = (N * sumXY - sumX * sumY) / (N * sumXSquare - sumSquareX);
    float b = (sumY - a * sumX) / N;
    cout << "a = " << a << "; b = " << b << '\n';
    return 0;
}