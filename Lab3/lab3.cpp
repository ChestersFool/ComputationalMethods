#include <iostream>
#include <cmath>

using std::cout, std::cin;

double Foo(double r, double ro, double h)
{
    return pow(h, 3) - 3 * r * pow(h, 2) + 4 * pow(r, 3) * ro;
}

double FooDerivative(double r, double ro, double h)
{
    return 2 * pow(h, 2) - 6 * r * h + 12 * pow(r, 2) * ro;
}

int main()
{
    // h ^ 3 - 3 * r * h ^ 2 + 4 * r ^ 3 * ro = 0
    double x0 = 0, xk = 0, xk1, ro = 0.620, r = 10;

    for (int i = 0; i < 10; i++)
    {
        xk = xk - Foo(r, ro, i) / FooDerivative(r, ro, i);

        cout << "n = " << i << "; x = " << xk << "; f[x] = " << Foo(r, ro, i) << "; f1[x] = " << FooDerivative(r, ro, i) << '\n';
    }

    return 0;
}