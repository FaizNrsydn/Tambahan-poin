#include "list.h"
#include<iostream>
using namespace std;

int main(){
    infotype A,B,C,D,E;
    list L;

    createList(L);
    A = {"Wortel","Januari", 500};
    B = {"Padi","Februari", 850};
    C = {"Labu","Maret", 550};
    D = {"Jagung","Maret", 790};
    E = {"Padi","Maret", 1000};

    tambahData(L, createNewElm(A));
    tambahData(L, createNewElm(B));
    tambahData(L, createNewElm(C));
    tambahData(L, createNewElm(D));
    tambahData(L, createNewElm(E));

    address terbanyak = panenTerbanyak(L);
    cout << "Panen Terbanyak: " << endl;
    if (terbanyak != Nil) {
        cout << "Nama Tanaman: " << terbanyak->x.nPanen << ", Bulan : " << terbanyak->x.bulan << ", Jumlah(kg) : " << terbanyak->x.jumlah << endl;
    }else{
        cout << "List Kosong" << endl;
    }

    panenBulanan(L, "Maret");
    return 0;
}