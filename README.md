# HOMEWORK 1 - Paradigmas de Programación
#### Segundo año de Ingeniería en IA. Universidad de San Andrés

## Comandos para compilacion de archivos
#### Previo a la compilación y ejecución de cada ejercicio es necesario ingresar a la carpeta que corresponda: 
Por ejemplo si quisiera ingresar a la carpeta del ejercicio 2 ejecuto
```
cd Ejercicio2
```
y para volver atrás
```
cd ..
```

#### Luego compilamos:
### Ejercicio 1
```
g++ main1.cpp Ejercicio1.cpp -o nombre_del_ejecutable
```
### Ejercicio 2
```
g++ main2.cpp Ejercicio2.cpp -o nombre_del_ejecutable
```
Luego de ejecutar se imprimirá un aviso de cuantos mensajes fueron logeados.
### Ejercicio 3
```
```
### Ejercicio 4
```
g++ main4.cpp Ejercicio4.cpp -o ejecutable
```
## Comentarios
###    INCISO 4.a
Basandome en el tiempo que tarda cada funcion lo indicado seria elegir (char*) a la hora de comparar cadenas de texto. Además es razonable que el tiempo de ejecución de strCompare con char* sea mas rápido que con string por el modo en que se accede a las posiciones de las cadenas de texto: char* accede directamente a la pos en memoria con punteros, pero string opera con un buffer, si bien no itera (no es o(n)) porque no recorre la cadena de texto completa tarda un poco más.

###    INCISO 4.c
Luego de comparar los tiempos de bool strCompare() con char* (que es el más rápido entre string y char*) y de constexpr bool strCompare() con const char*, puedo concluir que usar constexpr hace que la ejecucion sea mas rapida siempre. Esto se debe a que estoy llamando a la funcion constexpr con variables conocidas en tiempo de compilacion (const char*), entonces el compilador puede resolver el problema (resolver la funcion) por adelantado, lo que genera un resultado constante que no requiere calculos en tiempo de ejecución. O sea, el codigo es mas rapido porque se ahorran calculos (hechos al compilar) que antes ocurrian cuando ejecutabamos el programa.

###    Aclaración (ejercicio 4):
Defino la funcion constexpr en el archivo de cabecera ya que sino trae problemas al compilarlo (errores porque no se encuentra la definicion de la funcion).
