#include "list.h"
#include<iostream>
using namespace std;

bool isEmpty(list List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(list &List) {
    List.first = Nil;
}

address createNewElm(infotype x) { 
    address nodeBaru = new elmList; 
    nodeBaru->x.nPanen = x.nPanen;
    nodeBaru->x.bulan = x.bulan;
    nodeBaru->x.jumlah = x.jumlah;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void tambahData(list &List, address nodeBaru){
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

address panenTerbanyak(list &List){
    if (isEmpty(List)){
        return Nil;
    }
    address nodeBantu = List.first;
    address nodeMax;
    int max = 0;
    while (nodeBantu != Nil){
        if (max <= nodeBantu->x.jumlah){
            max = nodeBantu->x.jumlah;
            nodeMax = nodeBantu;
        }
        nodeBantu = nodeBantu->next;
    }
    return nodeMax;
}

void panenBulanan(list List, string bulan){
    if (isEmpty(List)){
        cout << "List Kosong";
    }else{
        address nodeBantu = List.first;
        cout << "Panen pada bulan " << bulan << ": ";
        cout << "' ";
        while (nodeBantu != Nil){
            if (nodeBantu->x.bulan == bulan){
                cout << nodeBantu->x.nPanen << " ";
            }
            nodeBantu = nodeBantu->next;
        }
        cout << "'";
    }
}

void printList(list List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Tanaman: " << nodeBantu->x.nPanen << ", Bulan : " << nodeBantu->x.bulan 
            << ", Jumlah(kg) : " << nodeBantu->x.jumlah << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}