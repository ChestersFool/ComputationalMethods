#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>

using std::cout, std::vector, std::setw;

vector<double> MatrixMultiplication(vector<vector<double>> &A, vector<double> &x)
{
    vector<double> result(4);
    //result.reserve(4);

    for (auto i = 0; i < A.size(); i++)
        for (auto j = 0; j < A[i].size(); j++)
            result[i] += A[i][j] * x[j];

    return result;
}

void PrintMatrix(vector<vector<double>> &matrix)
{
    for (auto &row : matrix)
    {
        for (auto &element : row)
            cout << setw(12) << element;

        cout << '\n';
    }
}

void PrintVector(vector<double> &array)
{
    for (auto element : array)
    {
        auto t = element;
        cout << setw(12) << element << ' ';
    }
}

int main()
{
    vector<vector<double>> A = {{0.0625, -0.0379, -0.0713, 0.0932},
                                {-0.0379, 0.0322, 0.0419, -0.0746},
                                {-0.0713, 0.0419, 0.1018, -0.1204},
                                {0.0932, -0.0746, -0.1204, 0.2317}};

    vector<double> x0 = {1, 0, 0, 0}, r0(4);
    vector<double> b = {0.1528, -0.0985, -0.2474, 0.3872};
    const double eps = 0.0000012;

    r0 = MatrixMultiplication(A, x0);
    PrintVector(r0);

    return 0;
}