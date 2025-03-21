#pragma once
#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Compara dos strings para verificar si son iguales
 * 
 * @param str1 Primera string a comparar
 * @param str2 Segunda string a comparar
 * @param l1 Longitud de la primera string
 * @param l2 Longitud de la segunda string
 * @return bool true si las strings son iguales, false en caso contrario
 * 
 * Compara dos objetos de tipo string. Utiliza recursión para comparar los caracteres desde
 * el último hasta el primero.
 */
bool strCompare(string str1, string str2, int l1, int l2);

/**
 * @brief Compara dos strings para verificar si son iguales
 * 
 * @param str1 Puntero a la primera string a comparar
 * @param str2 Puntero a la segunda string a comparar
 * @param l1 Longitud de la primera string
 * @param l2 Longitud de la segunda string
 * @return bool true si las strings son iguales, false en caso contrario
 * 
 * Esta función compara dos cadenas de caracteres tipo char*. Utiliza recursión para comparar los caracteres desde
 * el último hasta el primero.
 */
bool strCompare(char *str1, char *str2, int l1, int l2);

/**
 * @brief Compara dos strings literales para verificar si son iguales (versión constexpr)
 * 
 * @param str1 Puntero a la primera string a comparar
 * @param str2 Puntero a la segunda string a comparar
 * @param l1 Longitud de la primera string
 * @param l2 Longitud de la segunda string
 * @return bool true si las strings son iguales, false en caso contrario
 * 
 * Es una versión constexpr que puede evaluar la igualdad de strings
 * en tiempo de compilación. Utiliza recursión para comparar los caracteres desde
 * el último hasta el primero.
 */
constexpr bool strCompare(const char *str1,const char *str2, int l1, int l2){
    if (l1 == 0 && l2 == 0){return true;}
    if (l1 != l2){
        return false;
    }
    if (l1<0){
        return true;
    }
    if (str1[l1] != str2[l1]){
        return false;
    }
    return strCompare(str1,str2,l1-1,l2-1);
}