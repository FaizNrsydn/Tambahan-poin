#include "stack.h"
#include <iostream>
using namespace std;

void create_stack(Stack &S) {
    S.top = -1;
}

bool is_empty(Stack S) {
    return S.top == -1;
}

bool is_full(Stack S) {
    return S.top == N_STACK - 1;
}

void push(Stack &S, infotype x) {
    if (!is_full(S)) {
        S.top++;
        S.info[S.top] = x;
    } 
}

void pop (Stack &S, infotype &p) {
    
}

