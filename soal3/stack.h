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
bool is_empty(Stack S);
bool is_full(Stack S);
void push(Stack &S, infotype x);
void pop (Stack &S, infotype &p);


#endif