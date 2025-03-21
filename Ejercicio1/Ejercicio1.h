#pragma once
#include <vector>
using namespace std;

/**
 * @brief Genera una matriz cuadrada de dimensiones n x n con valores consecutivos.
 *
 * Construye un vector matriz de tamaño n x n. La misma se rellena 
 * con numeros, desde 1 hasta n*n, de forma creciente.
 *
 * @param n Tamaño de la matriz (n x n).
 * @return Un vector de vectores de enteros que representa la matriz cuadrada.
 */
vector<vector<int>> squareMatrix(int n);