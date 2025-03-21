#include "Ejercicio1.h"
#include <iostream>

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