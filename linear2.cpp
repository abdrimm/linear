#include <iostream>

using namespace std;

void swap_lines(double **A, int n, int line1, int line2){
	double tem;
    int i;
	for(i = 0; i < n; i++){
		tem = A[line1][i];
		A[line1][i] = A[line2][i];
		A[line2][i] = tem;
	}
}


int main()
{
    int n, i, j, k, s;
    double t;
    cout << "Введите размерность матрицы A: " << endl;
    cin >> n;
    double **A = new double *[n];
    for (i = 0; i <= n; i++)
		A[i] = new double [n];
    double *f = new double [n];
    double *x = new double [n];
    cout << "Введите элементы матрицы A:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cin >> A[i][j];
    }
    cout << "Введите элементы вектора f:\n";
    for (j = 0; j < n; j++) 
            cin >> f[j];
    for (k = 0; k < n; k++) //прямой ход
    {
        for (i = k + 1; i < n; i++)
        {
            if(A[k][k] == 0)
            {
   			        for(s = 1; s <= n-k; s++)
                    {		
   				        if(s == n-k) 
                        {
   					        return 0.0;
   				        }
   				        if((A[k+s][k]) != 0)
                        {
   					        swap_lines(A, n, k, s+k);
   						    //det = -det;
   					        break;
   				        }
                    }
   			} 
            t = A[i][k] / A[k][k];
            A[i][k] = 0;
            for (j = k + 1; j < n; j++)
                A[i][j] = A[i][j] - t * A[k][j];
            f[i] = f[i] - t * f[k];
        }
    }

    for(i = n - 1; i >= 0; i--) //обратный ход
    {
        x[i] = f[i];
        for (j = i + 1; j < n; j++)
            x[i] = x[i] - A[i][j] * x[j];
        x[i] = x[i] / A[i][i];
    }
    cout << "Решение системы - ";
    for(i = 0; i < n; i++)
        cout << x[i] << ", ";
    for (i = 0; i <= n; i++)
		free(A[i]);
    free(A);
    free(f);
    free(x);
    return 0;
}