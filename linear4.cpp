#include <iostream>
using namespace std;
const double eps2 = 0.2 * 0.2; 

double diff(int n, double *x1, double *x2)
{
    double s = 0;
    int i;
    for(i = 0; i < n; i++)
        s = s + (x1[i] - x2[i]) * (x1[i] - x2[i]);
    return s;
}

void jacobi(int n, double **A, double *f, double *x1, double *x2)
{
    int i, j;
    double s;
    for(i = 0; i < n; i++)
    {
        s = 0;
        for(j = 0; j <= i-1; j++)
            s = s + A[i][j] * x1[j];
        for(j = i+1; j < n; j++)
            s = s + A[i][j] * x1[j];
        x2[i] = (f[i] - s) / A[i][i];
    }
}
void zeidel(int n, double **A, double *f, double *x1, double *x2)
{
    int i, j;
    double s;
    for(i = 0; i < n; i++)
    {
        s = 0;
        for(j = 0; j <= i-1; j++)
            s = s + A[i][j] * x2[j];
        for(j = i+1; j < n; j++)
            s = s + A[i][j] * x1[j];
        x2[i] = (f[i] - s) / A[i][i];
    }
}

int main()
{
    int n, i, j;
    cout << "Введите размерность матрицы A: " << endl;
    cin >> n;
    double **A = new double *[n];
    for (i = 0; i <= n; i++)
		A[i] = new double [n];
    double *f = new double [n];
    double *x1 = new double [n];
    double *x2 = new double [n];
    cout << "Введите элементы матрицы A:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cin >> A[i][j];
    }
    cout << "Введите элементы вектора f:\n";
    for (j = 0; j < n; j++) 
            cin >> f[j];
    for(i = 0; i < n; i++)
    {
        x2[i] = 0;
    }
    do
    {
        for(i = 0; i < n; i++)
            x1[i] = x2[i];
        //jacobi(n, A, f, x1, x2);
        zeidel(n, A, f, x1, x2);
    }while(diff(n, x1, x2) > eps2);

    cout << "Решение системы х = (";
    for (i = 0; i < n-1; i++)
        cout << x1[i] << ", ";
    cout << x1[n-1] << ")" << endl;
    return 0;
}