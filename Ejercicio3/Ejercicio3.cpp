#include "Ejercicio3.h"
#include <iostream>
#include <memory>
using namespace std;

shared_ptr<node> create_node(int value){
    shared_ptr<node> newNode(new node);
    newNode->next = nullptr;
    newNode->value = value;
    return newNode;
}

shared_ptr<list> create_list(){
    shared_ptr<list> newList(new list);
    newList->head = nullptr;
    newList->size = 0;
    return newList;
}

void push_front(shared_ptr<list> l, int val){
    shared_ptr<node> newNode = create_node(val);
    // No chequeo si l esta vacia ya que de todos modos head pasa a ser newNode y newNode sigue apuntando a nullptr
    newNode->next = move(l->head);
    l->head = move(newNode);
    l->size++;
}

void push_back(shared_ptr<list> l, int val){
    shared_ptr<node> newNode = create_node(val);
    if(l->size == 0){
        l->head = move(newNode);
        l->size++;
        return;
    }

    shared_ptr<node> current = l->head; // Previamente ya chequee si la lista esta vacia para que current no sea nullptr

    while(current->next){
        current = current->next;
    }
    current->next = move(newNode);
    l->size++;
}

void insert(shared_ptr<list> l, int val, int pos){
    if (pos < 0){
        cout<<"Error: la posicion ingresada es menor a cero"<<endl;
        return;
    }
    
    if(l->size == 0){
        push_back(l,val);
        if(pos != 0){
            cout<<"La posicion ingresada no existe. El valor fue insertado al final de la lista"<<endl;
        }
        return;
    }
    if (pos == 0){
        push_front(l,val);
        return;
    }
    shared_ptr<node> current = l->head;
    
    for(int i = 0; i < l->size-1; i++){
        if(i == (pos-1)){
            shared_ptr<node> aux = current->next;
            shared_ptr<node> newNode = create_node(val);
            newNode->next = move(aux);
            current->next = move(newNode);
            l->size++;
            return;
        }
        current = current->next;
    }
    // Si no lo inserto anteriormente:
    push_back(l,val);
    cout<<"La posicion ingresada no existe. El valor fue insertado al final de la lista"<<endl;
}

void erase(shared_ptr<list> l, int pos){// La posicion inicial es cero
    if(l->size == 0){
        cout<<"La lista esta vacia. No hay valores para borrar"<<endl;
        return;
    }

    if (pos == 0){
        if(l->head->next){l->head = move(l->head->next);}
        else{l->head = nullptr;}
        l->size--;
        return;
    }

    shared_ptr<node> current = l->head;
    for(int i = 0; i<(l->size)-1; i++){ // Quiero ir hasta la ante ultima posicion para guardarme ese nodo en caso de que pos sea mayor al largo (util para borrar el ultimo)
        
        if(i == (pos-1)){
            if(current->next->next){
                current->next = move(current->next->next);
            }
            else{
                current->next = nullptr;
            }
            l->size--;
            return;
        }
        if(i != (l->size-2)){current = current->next;} // No quiero segur iterando depues de haber contemplado que pos sea igual a size
    }
    // Si no se borro un elemento antes:
    current->next = nullptr;
    l->size--;
    cout<<"La posicion ingresada no existe. Se borro el ultimo valor de la lista"<<endl;
}

void print_list(shared_ptr<list> l){
    shared_ptr<node> current = l->head;
    while(current){
        cout<<current->value;
        if(current->next != nullptr){
            cout<<"->";
        }
        current = current->next;
    }
    cout<<"-> nullptr"<<endl;
}