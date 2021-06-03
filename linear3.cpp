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
    double t, det = 1;
    cout << "Введите размерность матрицы A: " << endl;
    cin >> n;
    double **A = new double *[n];
    for (i = 0; i <= n; i++)
		A[i] = new double [n];
    double **E = new double *[n];
    for (i = 0; i <= n; i++)
		E[i] = new double [n];
    double **X = new double *[n];
    for (i = 0; i <= n; i++)
		X[i] = new double [n];
    cout << "Введите элементы матрицы A:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cin >> A[i][j];
    }
    //единичная матрицa
    for (i = 0; i < n; i++)  
    {
        for (j = 0; j < n; j++)  
        {
            if(i == j)
                E[i][j] = 1;
            else
                E[i][j] = 0;
        }
    }
    for (k = 0; k < n; k++)
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
   						    det = -det;
   					        break;
   				        }
                    }
   			} 
            t = A[i][k] / A[k][k];
            A[i][k] = 0;
            for (j = k + 1; j < n; j++) 
                A[i][j] = A[i][j] - t * A[k][j];
            for (j = 0; j < n; j++) 
                E[i][j] = E[i][j] - t * E[k][j];
        }
    }
    for(k = 0; k < n; k++)
        det = det * A[k][k];
    if(det == 0)
    {
        cout << "Обратная матрица не существует" << endl;
        return 0;
    }
    for (j = 0; j < n; j++) //обратный ход методом гаусса
    {
        for (i = n - 1; i >= 0; i--)
        {
            X[i][j] = E[i][j];
            for(k = i + 1; k < n; k++)
                X[i][j] = X[i][j] - A[i][k] * X[k][j];
            X[i][j] = X[i][j] / A[i][i];
        }
    }
    cout << "Обратная матрица:" << endl;
    for (i = 0; i < n; i++)  
    {
        for (j = 0; j < n; j++) 
            cout << X[i][j] << " ";
        cout << endl;;
    }
    for (i = 0; i <= n; i++)
		free(A[i]);
    free(A);
    for (i = 0; i <= n; i++)
		free(E[i]);
    free(E);
    for (i = 0; i <= n; i++)
		free(X[i]);
    free(X);
    return 0;
}
