#include "Ejercicio3.h"
#include <iostream>
#include <memory>

int main() {
    cout << "==== PRUEBAS DE LISTA ENLAZADA ====" << endl << endl;
    
    // Caso 1: Crear lista vacía
    cout<<"Caso 1: Crear lista vacía"<<endl;
    shared_ptr<list> miLista = create_list();
    cout<<"Lista creada. Tamaño: "<<miLista->size<<endl;
    cout<<"Imprimir lista vacía: ";
    print_list(miLista);
    cout<<endl;
    
    // Caso 2: Eliminar de lista vacía
    cout<<"Caso 2: Intentar eliminar de lista vacía"<<endl;
    erase(miLista, 0);
    cout<<endl;
    
    // Caso 3: push_front en lista vacía
    cout<<"Caso 3: push_front en lista vacía"<<endl;
    push_front(miLista, 10);
    cout<<"Lista después de push_front(10): ";
    print_list(miLista);
    cout<<"Tamaño: "<<miLista->size<<endl<<endl;
    
    // Caso 4: push_back en lista con un elemento
    cout<<"Caso 4: push_back en lista con un elemento"<<endl;
    push_back(miLista, 20);
    cout<<"Lista después de push_back(20): ";
    print_list(miLista);
    cout<<"Tamaño: "<<miLista->size<<endl<<endl;
    
    // Caso 5: Insertar en posición negativa
    cout<<"Caso 5: Insertar en posición negativa"<<endl;
    insert(miLista, 30, -1);
    cout<<"Lista después de insert(30, -1): ";
    print_list(miLista);
    cout<<"Tamaño: "<< miLista->size<<endl<<endl;
    
    // Caso 6: Insertar en posición 0
    cout<<"Caso 6: Insertar en posición 0"<<endl;
    insert(miLista, 5, 0);
    cout<<"Lista después de insert(5, 0): ";
    print_list(miLista);
    cout<<"Tamaño: "<< miLista->size<<endl<<endl;
    
    // Caso 7: Insertar en posición media
    cout<<"Caso 7: Insertar en posición media"<<endl;
    insert(miLista, 15, 2);
    cout<<"Lista después de insert(15, 2): ";
    print_list(miLista);
    cout<<"Tamaño: "<<miLista->size<<endl<<endl;
    
    // Caso 8: Insertar en posición mayor al tamaño
    cout<<"Caso 8: Insertar en posición mayor al tamaño"<<endl;
    insert(miLista, 25, 10);
    cout<<"Lista después de insert(25, 10): ";
    print_list(miLista);
    cout<<"Tamaño: "<<miLista->size<<endl<<endl;
    
    // Caso 9: Borrar primer elemento
    cout<<"Caso 9: Borrar primer elemento"<<endl;
    erase(miLista, 0);
    cout << "Lista después de erase(0): ";
    print_list(miLista);
    cout<<"Tamaño: "<< miLista->size<<endl<<endl;
    
    // Caso 10: Borrar elemento en medio
    cout<<"Caso 10: Borrar elemento en medio"<<endl;
    erase(miLista, 1);
    cout<<"Lista después de erase(1): ";
    print_list(miLista);
    cout<<"Tamaño: "<<miLista->size<<endl<<endl;
    
    // Caso 11: Borrar último elemento
    cout<<"Caso 11: Borrar último elemento"<<endl;
    erase(miLista, miLista->size - 1);
    cout<<"Lista después de erase(último): ";
    print_list(miLista);
    cout<<"Tamaño: "<<miLista->size<<endl<<endl;
    
    // Caso 12: Borrar en posición mayor al tamaño
    cout<<"Caso 12: Borrar en posición mayor al tamaño"<<endl;
    erase(miLista, 10);
    cout<<"Lista después de erase(10): ";
    print_list(miLista);
    cout<<"Tamaño: "<<miLista->size<<endl<<endl;
    
    // Caso 13: Borrar todos los elementos uno por uno
    cout<<"Caso 13: Borrar todos los elementos uno por uno"<<endl;
    while (miLista->size > 0) {
        cout<<"Borrando elemento. Lista antes: ";
        print_list(miLista);
        erase(miLista, 0);
    }
    cout<<"Lista después de borrar todo: ";
    print_list(miLista);
    cout<<"Tamaño: "<<miLista->size<<endl<<endl;
    
    // Caso 14: Reinsertar después de borrar todo
    cout<<"Caso 14: Reinsertar después de borrar todo"<<endl;
    push_back(miLista, 100);
    push_back(miLista, 200);
    push_back(miLista, 300);
    push_back(miLista, 400);
    cout<<"Lista después de reinsertar: ";
    print_list(miLista);
    cout<<"Tamaño: "<<miLista->size<<endl<<endl;

    // Caso 15: Borrar todos los elementos cuando son mas de dos
    cout<<"Caso 13: Borrar todos los elementos uno por uno"<<endl;
    while (miLista->size > 0) {
        cout<<"Borrando elemento. Lista antes: ";
        print_list(miLista);
        erase(miLista, 0);
    }
    cout<<"Lista después de borrar todo: ";
    print_list(miLista);
    cout<<"Tamaño: "<<miLista->size<<endl<<endl;
    
    cout<<"==== PRUEBAS COMPLETADAS ===="<<endl;
    
    return 0;
}