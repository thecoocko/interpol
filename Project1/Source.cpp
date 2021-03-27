#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n, p = 0;
    cout << "Enter number of equations = ";
    cin >> n;
    double e, k, C;
    std::vector<double> b(n), F(n, 0), x(n, 0), T(n, 0);
    std::vector<std::vector<double>> a(n, std::vector<double>(n));
    cout << "[a].[x]=[b]" << "\n";
    cout << "Enter Matrix a:" << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "," << j << "] = ";
            cin >> a[i][j];
        }
    }
    cout << "Enter Vector b:" << "\n";
    for (int j = 0; j < n; j++)
    {
        cout << "b[" << j << "] = ";
        cin >> b[j];
    }
    cout << "Enter the Accuracy = ";
    cin >> e;

    k = 1e10;
    while (k >= e) {
        p = p + 1;
        for (int i = 0; i < n; i++) {
            double B = 0;
            T[i] = b[i] / a[i][i];
            C = a[i][i];
            for (int j = 0; j < n; j++) {
                if (j != i)
                    B += a[i][j] * x[j];
            }
            x[i] = T[i] - B / C;
        }
        cout << x[0] << "\n";
        cout << x[1] << "\n";

        for (int i = 0; i < n; i++)
        {
            F[i] = 0.0;
            for (int j = 0; j < n; j++) {
                F[i] = F[i] + a[i][j] * x[j];
            }
        }
        for (int i = 0; i < n; i++) {
            F[i] = F[i] - b[i];
        }
        k = 0.0;
        for (int i = 0; i < n; i++) {
            k += F[i] * F[i];
        }
        k = std::sqrt(k);
    }

    cout << "Solution :\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i << "=" << x[i] << "\n";
    }

    cout << "number of iterations used: " << p << "\n";
    for (int i = 0; i < n; i++) {
        cout << "F" << i << "=" << F[i] << "\n";
    }
    cout << "Final error = " << k << "\n";




   /* int size;
    cin >> size;
    vector <vector <long double> > matrix;
   
    matrix.resize(size);
    for (int i = 0; i < size; i++)
    {
        matrix[i].resize(size + 1);

        for (int j = 0; j < size + 1; j++)
        {
            cin >> matrix[i][j];
        }
    }
    long double eps;
    cin >> eps;
    vector <long double> previousVariableValues(size, 0.0); 
    while (true)
    {    
        vector <long double> currentVariableValues(size);
        for (int i = 0; i < size; i++)
        {
            currentVariableValues[i] = matrix[i][size];
            for (int j = 0; j < size; j++)
            {
                if (i != j)
                {
                    currentVariableValues[i] -= matrix[i][j] * previousVariableValues[j];
                }
            }
            currentVariableValues[i] /= matrix[i][i];
        }

        long double error = 0.0;

        for (int i = 0; i < size; i++)
        {
            error += abs(currentVariableValues[i] - previousVariableValues[i]);
        }
        if (error < eps)
        {
            break;
        }
        previousVariableValues = currentVariableValues;
    }
    for (int i = 0; i < size; i++)
    {
        printf("%.8llf ", previousVariableValues[i]);
    }
    */
    return 0;
}