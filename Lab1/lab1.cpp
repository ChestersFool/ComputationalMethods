#include <iostream>
#include <iomanip>
#include <cmath>

template <class T>
void fun1_up(int &n, T &result)
{
    for (int i = 1; i < n; i++)
    {
        result *= i / float(i + 1);
    }
}

template <class T>
void fun1_down(int &n, T &result)
{
    for (int i = n - 1; i >= 1; i--)
    {
        result *= i / float(i + 1);
    }
}

template <class T>
void fun2_up(int &n, T &result)
{
    T number = 1;
    for (int i = 0; i < n; i++)
    {
        result *= number / (number * 2);
        number *= 2;
    }
}

template <class T>
void fun2_down(int &n, T &result)
{
    for (int i = n - 1; i >= 0; i--)
    {
        result *= powl(2, i) / powl(2, i + 1);
    }
}

using std::cin, std::cout, std::endl;

int main()
{
    float f_result = 1;
    double d_result = 1;
    int n;

    cout << "Enter n: ";
    cin >> n;

    fun1_up<float>(n, f_result);
    cout << "FIRST\nf_up_result - \t\t" << std::setprecision(20) << f_result << '\n';

    f_result = 1;
    fun1_down<float>(n, f_result);
    cout << "f_down_result - \t" << std::setprecision(20) << f_result << '\n';

    fun1_up<double>(n, d_result);
    cout << "d_up_result - \t\t" << std::setprecision(20) << d_result << '\n';

    d_result = 1;
    fun1_down<double>(n, d_result);
    cout << "d_down_result - \t" << std::setprecision(20) << d_result << '\n';

    cout << "1/n - " << std::setprecision(20) << 1 / double(n);

    f_result = 1;
    float number = 1;
    for (int i = 0; i < n; i++)
    {
        f_result *= number / (number * 2);
        number *= 2;
    }
    cout << "\n\nSECOND\nf_up_result - \t\t" << std::setprecision(16) << f_result << '\n';

    f_result = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        f_result *= powl(2, i) / powl(2, i + 1);
    }
    cout << "f_down_result - \t" << std::setprecision(16) << f_result << '\n';

    d_result = 1;
    fun2_up<double>(n, d_result);
    cout << "d_up_result - \t\t" << std::setprecision(20) << d_result << '\n';

    d_result = 1;
    fun2_down<double>(n, d_result);
    cout << "d_down_result - \t" << std::setprecision(20) << d_result << '\n';

    cout << "1/2n - " << std::setprecision(20) << 1 / pow(double(2), n);

    return 0;
}