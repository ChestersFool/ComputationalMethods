#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>

using std::vector, std::cout, std::swap, std::setw;

int SearchIndexOfRowWithMaxElementInPositionN(vector<vector<double>> &matrix, int n, int from)
{
    int indexOfRowWithMaxElementInPositionN = 0;
    double max = 0;

    for (int i = from; i < matrix.size(); i++)
    {
        if (matrix[i][n] > max)
        {
            max = matrix[i][n];
            indexOfRowWithMaxElementInPositionN = i;
        }
    }

    return indexOfRowWithMaxElementInPositionN;
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

int main()
{
    vector<vector<double>> matrix = {{0.58, -0.38, -0.93, 0.28, 0.7},
                                     {0.41, -0.55, 0.09, 0.96, -0.32},
                                     {0.24, 0.3, -0.08, -0.57, -0.32},
                                     {0.24, -0.21, -0.76, 1.64, 3.93}};

    double t;
    for (int k = 0; k < 4; k++)
    {
        t = SearchIndexOfRowWithMaxElementInPositionN(matrix, k, k);
        matrix[k].swap(matrix[t]);
        for (int i = k + 1; i < 4; i++)
        {
            t = matrix[i][k] / matrix[k][k];
            for (int j = k; j < 5; j++)
            {
                matrix[i][j] -= matrix[k][j] * t;
            }
        }
        cout << "\n\n";
        PrintMatrix(matrix);
    }
    cout << "\n\n";
    PrintMatrix(matrix);

    vector<double> x;
    x.reserve(4);
    x[3] = 1;

    for (int i = 3; i >= 0; i--)
    {
        t = matrix[i][4];
        for (int j = 2; j >= i; j--)
        {
            t -= matrix[i][j + 1] * x[j + 1];
        }
        x[i] = t / matrix[i][i];
        cout << 'x' << i + 1 << ": " << x[i] << '\t';
    }
    return 0;
}