#include "Ejercicio2.h"
#include <stdexcept>
#include <string>
#include <iostream>

int main(){
    // Verficacion de funcionamiento para opciones default:
    logMessage("Mensaje de debug",1);
    logMessage("Mensaje de info",2);
    logMessage("Mensaje de warning",3);
    logMessage("Mensaje de error",4);
    logMessage("Mensaje de critical",5);

    // Verificacion para mensaje de error con especificacion de archivo y linea de codigo
    logMessage("Mensaje de error especifico","Archivo_con_error",45);
    logMessage("Se ha detectado una falla","Archivo_con_error",104);

    // Verificacion de mensajes de acceso
    logMessage("Access denied","juanito123");
    logMessage("Access granted","anaclara");

    cout<<"Mensajes añadidos: debug(1), info(1), warning(1), error(3), critical(1), security(2)"<<endl;

    // Verificacion de captura de errores en runtime
    try{
        throw runtime_error("Ocurrio un error");
    }catch(const exception &e){
        logMessage(e.what(),__FILE__,__LINE__);
        cout<<"Mensajes añadidos: error(1)"<<endl;
        return 1;
    }
    return 0;
}