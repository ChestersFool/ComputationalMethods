#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>

using std::cout, std::vector, std::setw;

vector<double> MatrixVectorMultiplication(vector<vector<double>> &matrix, vector<double> &vec)
{
    vector<double> result(4);
    // result.reserve(4);

    for (auto i = 0; i < 4; i++)
        for (auto j = 0; j < 4; j++)
            result[i] += matrix[i][j] * vec[j];

    return result;
}

vector<double> VectorNumberMultiplication(vector<double> &vec, double &number)
{
    vector<double> result(4);

    for (auto i = 0; i < 4; i++)
        result[i] = vec[i] * number;

    return result;
}

vector<double> VectorSubtraction(vector<double> &b, vector<double> &A)
{
    vector<double> result(4);

    for (int i = 0; i < 4; i++)
        result[i] = b[i] - A[i];

    return result;
}

double VectorScalar(vector<double> &first, vector<double> &second)
{
    double result = 0;

    for (int i = 0; i < 4; i++)
        result += first[i] * second[i];

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
    cout << '\n';
}

// * МЕТОД СПРЯЖЕНИХ ГРАДІЄНТІВ
int main()
{
    vector<vector<double>> A = {{0.0625, -0.0379, -0.0713, 0.0932},
                                {-0.0379, 0.0322, 0.0419, -0.0746},
                                {-0.0713, 0.0419, 0.1018, -0.1204},
                                {0.0932, -0.0746, -0.1204, 0.2317}};
    vector<double> b = {0.1528, -0.0985, -0.2474, 0.3872};
    vector<double> x0 = {1, 0, 0, 0}, r0(4), p0(4), qk(4);
    double alfaK;
    const double eps = 0.0000012;

    // A * x_0
    r0 = MatrixVectorMultiplication(A, x0);
    cout << "A * x_0 ";
    PrintVector(r0);
    // b - Ax_0
    r0 = VectorSubtraction(b, r0);
    cout << "b - A * x_0 ";
    PrintVector(r0);

    // p_0 = r_0
    p0 = r0;

    // q_k = A * p_k
    qk = MatrixVectorMultiplication(A, p0);
    cout << "q_k = A * p_k ";
    PrintVector(qk);

    // alfaK = (r_k, p_k) / (q_k, p_k)
    alfaK = VectorScalar(r0, p0) / VectorScalar(qk, p0);
    cout << "alfaK = (r_k, p_k) / (q_k, p_k) " << alfaK << '\n';

    // x_k+1 = x_k + alfaK * p_k
    // x0 = Vector return 0;
}