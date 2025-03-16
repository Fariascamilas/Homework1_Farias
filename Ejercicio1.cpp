#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Inciso a
vector<vector<int>> squareMatrix(int n){
    int tope = n*n;
    vector<vector<int>> matrix(n,vector<int>(n));
    int num = 1;
    for (int i=0; i<n;i++){
        for (int j = 0; j<n; j++){
            matrix[i][j] = num;
            num++;
        }
    }
    return matrix;
}

// Inciso b
int main(void){
    int dim;
    cout<<"Ingrese dimension de la matriz:[un solo numero entero]"<<endl;
    cin>>dim;
    vector<vector<int>> matrix = squareMatrix(dim);
    int i = (dim-1), j = (dim-1);
    for (int _ = (dim*dim)-1; _>=0;_--){
        cout<<"M["<<i<<"]["<<j<<"] = "<<matrix[i][j]<<endl;
        if (j == 0){
                j = (dim-1);
                i--;
        }
        else{
            j--;
        }
    }
    return 0;
}