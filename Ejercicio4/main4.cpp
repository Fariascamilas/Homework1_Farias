#include "Ejercicio4.h"
#include <cstring>
#include <chrono>

int main(){
    // PRUEBAS (1): Usando string
    string a1 = "Hola Mundo, mi nombre es Camila y estudio Ingeniería en UdeSA :)";
    string b1 = "Hola Mundo, mi nombre es Camila y estudio Ingeniería en UdeSA :)";
    string c1 = "Hola Mundo, mi nombre es Yamila y estudio Ingeniería en UdeSA :)"; // Cambia la Y

    bool result1 = strCompare(a1, b1, a1.size(), b1.size());
    bool result2 = strCompare(b1, c1, b1.size(), c1.size());

    cout<<"---------------------------------------------------------"<<endl;

    cout<<"strCompare(string)"<<endl;

    cout<<"Resultado1 esperado: true -> Resultado1 obtenido: -> ";
    if(result1 == true){cout<<"true"<<endl;}
    else{cout<<"false"<<endl;}

    cout<<"Resultado2 esperado: false -> Resultado2 obtenido: -> ";
    if(result2 == true){cout<<"true"<<endl;}
    else{cout<<"false"<<endl;}

    cout<<"---------------------------------------------------------"<<endl;

    // PRUEBAS (2): Usando char*
    char arrA2[] = "Hola Mundo, mi nombre es Camila y estudio Ingeniería en UdeSA :)";
    char arrB2[] = "Hola Mundo, mi nombre es Camila y estudio Ingeniería en UdeSA :)";
    char arrC2[] = "Hola Mundo, mi nombre es camila y estudio Ingeniería en UdeSA :)"; // Cambia la c mayúscula
    
    bool result3 = strCompare(arrA2, arrB2, strlen(arrA2), strlen(arrA2));
    bool result4 = strCompare(arrB2, arrC2, strlen(arrB2), strlen(arrC2));

    cout<<"strCompare(char *)"<<endl;

    cout<<"Resultado3 esperado: true -> Resultado3 obtenido: -> ";
    if(result3 == true){cout<<"true"<<endl;}
    else{cout<<"false"<<endl;}

    cout<<"Resultado4 esperado: false -> Resultado4 obtenido: -> ";
    if(result4 == true){cout<<"true"<<endl;}
    else{cout<<"false"<<endl;}

    cout<<"---------------------------------------------------------"<<endl;

    // PRUEBAS (3): Usando constexpr con const char*
    const char arrA3[] = "Hola Mundo, mi nombre es Camila y estudio Ingeniería en UdeSA :)";
    const char arrB3[] = "Hola Mundo, mi nombre es Camila y estudio Ingeniería en UdeSA :)";
    const char arrC3[] = "Hola Mundo, mi nombre es Camila , estudio Ingeniería en UdeSA :)"; // Cambia la coma

    bool result5 = strCompare(arrA3, arrB3, strlen(arrA3), strlen(arrA3));
    bool result6 = strCompare(arrB3, arrC3, strlen(arrB3), strlen(arrC3));

    cout<<"strCompare(constexpr)"<<endl;

    cout<<"Resultado5 esperado: true -> Resultado5 obtenido: -> ";
    if(result5 == true){cout<<"true"<<endl;}
    else{cout<<"false"<<endl;}

    cout<<"Resultado6 esperado: false -> Resultado6 obtenido: -> ";
    if(result6 == true){cout<<"true"<<endl;}
    else{cout<<"false"<<endl;}

    cout<<"---------------------------------------------------------"<<endl;

    //MEDICIONES de tiempo
    auto startTime1 = chrono::high_resolution_clock::now();
    strCompare(a1,b1, a1.size(), b1.size());
    auto endTime1 = chrono::high_resolution_clock::now();
    auto elapsedTime1 = chrono::duration_cast<chrono::nanoseconds>(endTime1 - startTime1);

    cout<<"strCompare(string) demoró: "<<elapsedTime1.count()<<" nanosegundos"<<endl;
    
    cout<<"---------------------------------------------------------"<<endl;

    auto startTime2 = chrono::high_resolution_clock::now();
    strCompare(arrA2, arrB2, strlen(arrA2), strlen(arrA2));
    auto endTime2 = chrono::high_resolution_clock::now();
    auto elapsedTime2 = chrono::duration_cast<chrono::nanoseconds>(endTime2 - startTime2);

    cout<<"strCompare(char *) demoró: "<<elapsedTime2.count()<<" nanosegundos"<<endl;

    cout<<"---------------------------------------------------------"<<endl;
    
    auto startTime3 = chrono::high_resolution_clock::now();
    strCompare(arrA3, arrB3, strlen(arrA3), strlen(arrA3));
    auto endTime3 = chrono::high_resolution_clock::now();
    auto elapsedTime3 = chrono::duration_cast<chrono::nanoseconds>(endTime3 - startTime3);

    cout<<"strCompare(constexpr) demoró: "<<elapsedTime3.count()<<" nanosegundos"<<endl;
    
    cout<<"---------------------------------------------------------"<<endl;
    
    return 0;
}

/*
    INCISO 4.a
Basandome en el tiempo que tarda cada funcion lo indicado seria elegir (char*) a la hora de comparar cadenas de texto. Además es razonable que el tiempo de ejecución de strCompare con char* sea mas rápido que con string por el modo en que se accede a las posiciones de las cadenas de texto: char* accede directamente a la pos en memoria con punteros, pero string opera con un buffer, si bien no itera (no es o(n)) porque no recorre la cadena de texto completa tarda un poco más.

    INCISO 4.c
Luego de comparar los tiempos de bool strCompare() con char* (que es el más rápido entre string y char*) y de constexpr bool strCompare() con const char*, puedo concluir que usar constexpr hace que la ejecucion sea mas rapida siempre. Esto se debe a que estoy llamando a la funcion constexpr con variables conocidas en tiempo de compilacion (const char*), entonces el compilador puede resolver el problema (resolver la funcion) por adelantado, lo que genera un resultado constante que no requiere calculos en tiempo de ejecución. O sea, el codigo es mas rapido porque se ahorran calculos (hechos al compilar) que antes ocurrian cuando ejecutabamos el programa.

    Aclaración:
Defino la funcion constexpr en el archivo de cabecera ya que sino trae problemas al compilarlo (errores porque no se encuentra la definicion de la funcion).
*/