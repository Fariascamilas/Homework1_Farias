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

shared_ptr<node> create_node(int value);

shared_ptr<list> create_list();

void push_front(shared_ptr<list> l, int val);

void push_back(shared_ptr<list> l, int val);

void insert(shared_ptr<list> l, int val, int pos);

void erase(shared_ptr<list> l, int pos);

void print_list(shared_ptr<list> l);