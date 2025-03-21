#pragma once
#include <iostream>
#include <memory>
using namespace std;

struct node{
    shared_ptr<node> next;
    int value;
};

struct list{
    shared_ptr<node> head;
    int size;
};

/**
 * @brief Crea un nuevo nodo con el valor especificado
 * 
 * @param value Valor entero a almacenar en el nodo
 * @return shared_ptr<node> Puntero shared al nuevo nodo creado
 */
shared_ptr<node> create_node(int value);

/**
 * @brief Crea una nueva lista vacía
 * 
 * @return shared_ptr<list> Puntero shared a la nueva lista creada
 */
shared_ptr<list> create_list();

/**
 * @brief Inserta un valor al inicio de la lista
 * 
 * @param l Puntero a la lista donde se insertará el valor
 * @param val Valor entero a insertar
 */
void push_front(shared_ptr<list> l, int val);

/**
 * @brief Inserta un valor al final de la lista
 * 
 * @param l Puntero a la lista donde se insertará el valor
 * @param val Valor entero a insertar
 */
void push_back(shared_ptr<list> l, int val);

/**
 * @brief Inserta un valor en la posición especificada de la lista
 * 
 * Si la posición es mayor que el tamaño de la lista, el valor se inserta al final.
 * Si la posición es negativa, muestra un mensaje de error y no realiza la inserción.
 * 
 * @param l Puntero a la lista donde se insertará el valor
 * @param val Valor entero a insertar
 * @param pos Posición donde insertar el valor (0 es la primera posición)
 */
void insert(shared_ptr<list> l, int val, int pos);

/**
 * @brief Elimina el elemento en una posición especificada de la lista
 * 
 * Si la posición es mayor que el tamaño de la lista, se elimina el último elemento.
 * Si la lista está vacía, muestra un mensaje de error y no realiza ninguna acción.
 * 
 * @param l Puntero a la lista de donde se eliminará el elemento
 * @param pos Posición del elemento a eliminar (0 es la primera posición)
 */
void erase(shared_ptr<list> l, int pos);

/**
 * @brief Imprime todos los elementos de la lista en formato "valor->valor->...->nullptr"
 * 
 * @param l Puntero a la lista que se imprimirá
 */
void print_list(shared_ptr<list> l);