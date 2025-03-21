#include "Ejercicio1.h"
#include <iostream>
#include <vector>


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