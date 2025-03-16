#include <iostream>
#include <string>
#include "Ejercicio2_a.cpp"
using namespace std;

void logMessage(string error_message,string archive,int code_line){
    ofstream err_arch(archive,ios::app);
    err_arch<<"[Error]<"<<error_message<<">, line: "<<code_line<<endl;
    err_arch.close(); 
}   
void logMessage(string acces_message,string username){
    
}