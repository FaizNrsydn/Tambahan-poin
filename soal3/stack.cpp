#include "stack.h"
#include <iostream>

using namespace std;

void create_stack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack &S) {
    return S.top == -1;
}

bool isFull(Stack &S) {
    return S.top == N_STACK - 1;
}

void push(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stak Penuh!" << endl;
    }else{
        S.top++;
        S.info[S.top] = x;
    }
}

void pop (Stack &S, infotype &p) {
    if (!isEmpty(S)) {
        p = S.info[S.top];
        S.top--;
    } else {
        cout << "Stack Kosong! Tidak dapat melakukan POP." << endl;
        p = ""; 
    }
}

void manageAction(Stack &S_Aksi, Stack &S_Redo, const infotype &aksi) {
    infotype temp_aksi;

    if (aksi == "UNDO") {
        if (!isEmpty(S_Aksi)) {
            pop(S_Aksi, temp_aksi);
            push(S_Redo, temp_aksi);
            cout << "Aksi di-UNDO: '" << temp_aksi << "'" << endl;
        } else {
            cout << "UNDO GAGAL: Stack Aksi kosong." << endl;
        }
    }else if (aksi == "REDO") {
        if (!isEmpty(S_Redo)) {
            pop(S_Redo, temp_aksi);
            push(S_Aksi, temp_aksi);
            cout << "Aksi di-REDO: '" << temp_aksi << "'" << endl;
        } else {
            cout << "REDO GAGAL: Stack Redo kosong." << endl;
        }
    }else {
        push(S_Aksi, aksi);
        create_stack(S_Redo);
        create_stack(S_Redo); 
        
        cout << "Aksi baru: '" << aksi << "' ditambahkan. Stack Redo direset." << endl;
    }
}

void totalDamage(Stack &S, int &damage) {
    infotype current_action;
    damage = 0;
    
    cout << "\n--- Penghitungan Total Damage ---" << endl;

    while (!isEmpty(S)) {
        pop(S, current_action);
        
        if (current_action == "ATTACK") {
            damage += 30;
            cout << "-> Aksi: ATTACK (+30 Damage). Total: " << damage << endl;
        } else if (current_action == "DEFENSE") {
            damage += 5;
            cout << "-> Aksi: DEFENSE (+5 Damage). Total: " << damage << endl;
        }else{
            cout << "-> Aksi: '" << current_action << "' (+0 Damage)." << endl;
        }
        
    }

    cout << "---------------------------------" << endl;
    cout << "Total Damage Akhir: " << damage << endl;
}

void printStack(Stack &S){
    if(isEmpty(S)){
        cout << "Stack kosong!" << endl;
    }else{
        cout << "[isi stack nya]" << endl;
        for (int i = 0; i <= S.top; i++){
            cout << S.info [i];
            if(i < S.top){
                cout << ", ";
            }
        }
    }
}