#include <iostream>

using namespace std;

int main()
{
    int i, j, n;
    cout << "Введите размерность матрицы: ";
    cin >> n;
    double **matrix = new double*[n];
    double *a = new double [n];
    double *b = new double [n];
    double *c = new double [n];
    double *f = new double [n];
    double *x = new double [n+1];
    double *alpha = new double [n+1];
    double *beta = new double [n+1];

    cout << "Введите матрицу A:\n";
    for (i = 0; i < n; i++)
    {
        matrix[i] = new double[n];
        for (j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << "Введите вектор f: ";
    for (i = 0; i < n; i++)
        cin >> f[i];
    cout << endl;

    for (i = 1; i < n; i++) //элементы под главной диагональю
        a[i] = matrix[i][i-1];
    for (i = 0; i < n; i++) // элементы на главной диагонали
        b[i] = matrix[i][i];
    for (i = 0; i < n-1; i++) //элементы над главной диагональю
        c[i] = matrix[i][i+1];
    a[0] = 0;
    c[n-1] = 0;
	alpha[0] = 0;
    beta[0] = 0;
    double d;
    //прямой ход
    for (i = 0; i < n; i++)
    {
        d = a[i] * alpha[i] + b[i];
        if(c[i] == 0)
            alpha[i+1] = 0;
        else
            alpha[i+1] = -c[i] / d;
        beta[i+1] = (f[i] - a[i] * beta[i]) / d;
    }
    x[n] = 0;
    //обратный ход прогонки
    for (i = n - 1; i >= 0; i--)
        x[i] = alpha[i+1] *x[i+1] + beta[i+1];
    cout << "Решение системы х = ( ";
    for (i = 0; i < n; i++)
        cout << x[i] << ", ";
    cout << ")" << endl;
    free(x);
    free(beta);
    free(alpha);
    free(f);
    free(c);
    free(b);
    free(a);
    return 0;
}