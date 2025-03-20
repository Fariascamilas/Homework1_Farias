#include "Ejercicio2.h"
#include <iostream>

int main(void){
    string message;
    int level;
    cout<<"Ingrese un mensaje"<<endl;
    getline(cin,message); // Lee una linea completa
    cout<<"Ingrese nivel de severidad: (1:DEBUG, 2:INFO, 3:WARNING, 4:ERROR, 5:CRITICAL)"<<endl;
    cin>>level;
    logMessage(message,level);
    return 0;
}