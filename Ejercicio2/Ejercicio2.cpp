#include "Ejercicio2.h"
#include <iostream>
#include <string>
#include <fstream>

void logMessage(string message, int severity_level){
    ofstream archive("LogSystem.txt", ios::app);
    if(!archive){
        cout<<"Error de apertura de archivo log"<<endl;
        return;
    }
    
    switch(severity_level){
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
            archive<<"["<<"ERROR"<<"]"<<"<"<<message<<">"<<endl;
            break;
        case CRITICAL:
            archive<<"["<<"CRITICAL"<<"]"<<"<"<<message<<">"<<endl;
            break;
        default:
            cout<<"Error: el numero ingresado no corresponde con ninguna etiqueta."<<endl;
    }
    archive.close();
}

void logMessage(string error_message, string archive, int code_line){
    ofstream err_arch("LogSystem.txt",ios::app);
    if (!err_arch) {
        cout << "Error de apertura de archivo log" << endl;
        return;
    }
    err_arch<<"[ERROR]<"<<error_message<<"> archive: "<<archive<<", line: "<<code_line<<endl;
    err_arch.close(); 
}  

void logMessage(string acces_message, string username){
    ofstream err_arch("LogSystem.txt",ios::app);
    if (!err_arch) {
        cout << "Error de apertura de archivo log" << endl;
        return;
    }
    err_arch<<"[SECUTRITY]<"<<acces_message<<"> user: "<<username<<endl;
    err_arch.close();
}