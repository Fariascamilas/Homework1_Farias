#include "Ejercicio2.h"
#include <iostream>
#include <string>
#include <fstream>
int main(){
    cout<<"Ingrese un mensaje: "<<endl;
    string message;
    getline(cin,message);

    cout<<"Ingrese tipo de mensaje: (1:DEBUG, 2:INFO, 3:WARNING, 4:ERROR, 5:CRITICAL, 6:SECURITY)"<<endl;
    int type;
    cin>>type;

    string username;
    
    ofstream archive("LogSystem", ios::app);
    switch(type){
        case DEBUG:
            archive<<"["<<"DEBUG"<<"]"<<"<"<<message<<">"<<endl;
            break;
        case INFO:
            archive<<"["<<"INFO"<<"]"<<"<"<<message<<">"<<endl;
            break;
        case WARNING:
            archive<<"["<<"WARNING"<<"]"<<"<"<<message<<">"<<endl;
            break;
        case ERROR:
            cout<<"Desea agregar el archivo y la linea de codigo del error?: [s/n]"<<endl;
            char rta;

            if (rta == 's'){
                string arch;
                int code_line;
                cout<<"Ingrese nombre del archivo: ";
                getline(cin,arch);
                cout<<"Ingrese linea de codigo: ";
                cin>>code_line;
                logMessage(message,arch,code_line);
            }
            else if(rta == 'n'){
                archive<<"["<<"ERROR"<<"]"<<"<"<<message<<">"<<endl;
            }
            else{
                cout<<"La respuesta ingresada no es valida"<<endl;
            }

            break;
        case CRITICAL:
            archive<<"["<<"CRITICAL"<<"]"<<"<"<<message<<">"<<endl;
            break;
        case SECURITY:
            cout<<"Indique su nombre de usuario: ";
            cin>>username;
            logMessage(message,username);
        default:
        cout<<"Error: el numero ingresado no corresponde con ninguna etiqueta."<<endl;
    } 
}