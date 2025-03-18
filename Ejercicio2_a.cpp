#include <iostream>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

enum messages{DEBUG = 1, INFO, WARNING, ERROR, CRITICAL};

void logMessage(string message, int severity_level){
    ofstream archive("LogSystem", ios::app);
    if(!archive){
        cout<<"Error de apertura de archivo"<<endl;
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
    }
    archive.close();
}

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