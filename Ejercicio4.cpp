#include <iostream>
#include <string>
#include <chrono>
#include <cstring>
using namespace std;

int length(string s){
    int n = 0;
    for (int i:s){
        if (i == '\0'){
            break;
        }
        n++;
    }
    return n;
}
int lengthC(char* s){
    int n = 0;
    for (int i=0;;i++){
        if (s[i] == '\0'){
            break;
        }
        n++;
    }
    return n;
}

bool strCompare(string str1, string str2, int l1, int l2){
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

bool strComparec(char *str1, char *str2, int l1, int l2){
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

int main(){
    string a = "Demuestre la funcionalidad de su código con un texto de, al menos, 64 caracteres";
    string b = "Demuestre la funcionalidad de su código con un texto de, al menos, 64 caracteres";

    char* aptr = new char[length(a)+1];
    strcpy(aptr,"Demuestre la funcionalidad de su código con un texto de, al menos, 64 caracteres");
    char* bptr = new char[length(b)+1];
    strcpy(bptr,"Demuestre la funcionalidad de su código con un texto de, al menos, 64 caracteres");

    cout<<"funcion string:"<<endl;
    cout<<strCompare(a,b,length(a),length(b))<<endl;

    auto startTime = chrono::high_resolution_clock::now();
    strCompare(a,b,length(a),length(b));
    auto endTime = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);

    cout<<"funcion string demoro: "<<elapsedTime.count()<<" nanosegundos"<<endl;
    //-----------------------------------------------------------
    cout<<"funcion char*:"<<endl;
    cout<<strComparec(aptr,bptr,length(aptr),length(bptr))<<endl;

    auto startTime1 = chrono::high_resolution_clock::now();
    strComparec(aptr,bptr,length(aptr),length(bptr));
    auto endTime1 = chrono::high_resolution_clock::now();
    auto elapsedTime1 = chrono::duration_cast<chrono::nanoseconds>(endTime1-startTime1);

    cout<<"funcion char* demoro: "<<elapsedTime1.count()<<" nanosegundos"<<endl;
}

// En c++ puedo asumir que un char* es un array?
// Segun copilot:
/*No exactamente. Un char* es un puntero que puede apuntar al inicio de un bloque de memoria que contenga caracteres, pero no maneja automáticamente su tamaño ni realiza comprobación de límites. Un arreglo de char[] se gestiona con información de su tamaño en tiempo de compilación. En C++, se suele recomendar usar std::string en lugar de un char* cuando sea posible.*/