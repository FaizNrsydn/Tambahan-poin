#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

const int N_STACK = 2025;
typedef string infotype;

struct Stack {
    infotype info[N_STACK];
    int top;
};

void create_stack(Stack &S);
bool isEmpty(Stack &S);
bool isFull(Stack &S);
void push(Stack &S, infotype x);
void pop (Stack &S, infotype &p);

void manageAction(Stack &S_Aksi, Stack &S_Redo, const infotype &aksi);
void totalDamage(Stack &S, int &damage);

void printStack(Stack &S, string &namaStack);

#endif