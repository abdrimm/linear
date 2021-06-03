#include<iostream>

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

double determinant(double **A, int n) {
    double det = 1.0;
    double t;
    int i, j, k, s;
    for(k = 0; k < n; k++)
    {
   	    for(i = k+1; i < n; i++)
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
            A[i][k] = 0.0;
   		      for(j = k+1; j < n; j++)
              {
   			        A[i][j] = A[i][j] - t * A[k][j];
   		      }
   	    }
        det = det * A[k][k]; 
    }
    return det;
}

int main() {
    int n, i, j;
    cout << "Введите размерность матрицы: " << endl;
    cin >> n;
    double **A = new double *[n];
    for (i = 0; i < n; i++)
    {
		    A[i] = new double [n];
    }
    cout << "Введите элементы матрицы:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    } 
    double res = determinant(A, n);
    if(res == -0)
        res = 0;
   cout<<"Определитель матрицы равен "<< res << endl;
   for (i = 0; i < n; i++)
		free(A[i]);
   free(A);
   return 0;
}