#include "stack.h"
#include <iostream>

using namespace std;

void printStack(const Stack &S, const string &name) {
    cout << name << " [Top=" << S.top << "]: [";
    for (int i = 0; i <= S.top; i++) {
        cout << S.info[i];
        if (i < S.top) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    Stack S_Aksi, S_Redo;
    create_stack(S_Aksi);
    create_stack(S_Redo);
    
    cout << "Simulasi Game Action (Undo/Redo)\n";
    cout << "================================\n";
    
    string actions[] = {"ATTACK", "ATTACK", "DEFENSE", "ATTACK", "UNDO", "UNDO", "REDO", "DEFENSE"};
    int num_actions = sizeof(actions) / sizeof(actions[0]);

    for (int i = 0; i < num_actions; i++) {
        cout << "\n--- Langkah " << i + 1 << ": " << actions[i] << " ---" << endl;
        manageAction(S_Aksi, S_Redo, actions[i]);
        printStack(S_Aksi, "Stack Aksi");
        printStack(S_Redo, "Stack Redo");
    }

    int damage = 0;
    Stack S_Damage = S_Aksi; 
    totalDamage(S_Damage, damage);
    
    return 0;
}