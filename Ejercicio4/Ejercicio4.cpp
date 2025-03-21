#include "Ejercicio4.h"
#include <iostream>
using namespace std;

bool strCompare(string str1, string str2, int l1, int l2){
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

bool strCompare(char *str1, char *str2, int l1, int l2){
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