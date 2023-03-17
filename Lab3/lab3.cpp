#include <iostream>
#include <cmath>

using std::cout, std::cin;

double Foo(double r, double ro, double h)
{
    return pow(h, 3) - 3 * r * pow(h, 2) + 4 * pow(r, 3) * ro;
}

double FooDerivative(double r, double ro, double h)
{
    return 3 * pow(h, 2) - 6 * r * h;
}

int main()
{
    // h ^ 3 - 3 * r * h ^ 2 + 4 * r ^ 3 * ro = 0
    double xk = 0, xk1 = 28, xkminus1 = 28, ro = 0.620, r = 10, eps = 0.001, res1, res2;
    int i = 0;

    do
    {
        xk = xk1;
        res1 = Foo(r, ro, xk);
        res2 = FooDerivative(r, ro, xk);
        xk1 = xk - res1 / res2;

        cout << "n = " << i << "; x = " << xk << "; f[x] = " << res1 << "; f1[x] = " << res2 << '\n';
        i++;
    } while (fabs(xk - xk1) > eps); // while(i < 10);//

    cout << "\n----------\n\n";

    xk = 0;
    xk1 = 28;
    xkminus1 = 28;
    i = 0;

    do
    {
        xkminus1 = xk;
        xk = xk1;

        res1 = Foo(r, ro, xk);
        res2 = Foo(r, ro, xkminus1);
        xk1 = xk - (res1 * (xk - xkminus1)) / (res1 - res2);

        cout << "n = " << i << "; x = " << xk << "; f[x] = " << res1 << "; f1[x] = " << res2 << '\n';
        i++;
    } while (fabs(xk - xk1) > eps);

    return 0;
}