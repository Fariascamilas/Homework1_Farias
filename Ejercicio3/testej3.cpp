#include "Ejercicio3.cpp"
#include <cassert>

void test_push_front() {
    auto lista = make_shared<list>();
    lista->head = nullptr;
    lista->size = 0;

    push_front(lista, 10);
    assert(lista->size == 1);
    assert(lista->head->value == 10);

    push_front(lista, 20);
    assert(lista->size == 2);
    assert(lista->head->value == 20);
    assert(lista->head->next->value == 10);

    cout << "test_push_front passed!" << endl;
}

void test_push_back() {
    auto lista = make_shared<list>();
    lista->head = nullptr;
    lista->size = 0;

    push_back(lista, 10);
    assert(lista->size == 1);
    assert(lista->head->value == 10);

    push_back(lista, 20);
    assert(lista->size == 2);
    assert(lista->head->next->value == 20);

    cout << "test_push_back passed!" << endl;
}

void test_insert() {
    auto lista = make_shared<list>();
    lista->head = nullptr;
    lista->size = 0;

    insert(lista, 10, 0);
    assert(lista->size == 1);
    assert(lista->head->value == 10);

    insert(lista, 20, 1);
    assert(lista->size == 2);
    assert(lista->head->next->value == 20);

    insert(lista, 15, 1);
    assert(lista->size == 3);
    assert(lista->head->next->value == 15);

    cout << "test_insert passed!" << endl;
}

void test_erase() {
    auto lista = make_shared<list>();
    lista->head = nullptr;
    lista->size = 0;

    push_back(lista, 10);
    push_back(lista, 20);
    push_back(lista, 30);

    erase(lista, 1);
    assert(lista->size == 2);
    assert(lista->head->next->value == 30);

    erase(lista, 0);
    assert(lista->size == 1);
    assert(lista->head->value == 30);

    erase(lista, 0);
    assert(lista->size == 0);
    assert(lista->head == nullptr);

    cout << "test_erase passed!" << endl;
}

void test_print_list() {
    auto lista = make_shared<list>();
    lista->head = nullptr;
    lista->size = 0;

    push_back(lista, 10);
    push_back(lista, 20);
    push_back(lista, 30);

    cout << "Expected output: 10->20->30-> nullptr" << endl;
    cout << "Actual output: ";
    print_list(lista);

    cout << "test_print_list passed!" << endl;
}

int main() {
    test_push_front();
    test_push_back();
    test_insert();
    test_erase();
    test_print_list();

    cout << "All tests passed!" << endl;
    return 0;
}