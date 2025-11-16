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
    List.last = Nil;
}

address createNewElm(infotype x) { 
    address nodeBaru = new elmList; 
    nodeBaru->url = x;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    if (node != Nil){
        node->next = Nil;
        node->prev = Nil;
        delete node;
    }
}

void tambahData(list &List, address nodeBaru){
    if (isEmpty(List)){
        List.first = List.last = nodeBaru;
    }else{
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
}

address cariRiwayat(list List, infotype cari){
    address nodeBantu =List.first;
    // address nodeCari;
    while (nodeBantu != Nil){
        if (nodeBantu->url == cari){
            return nodeBantu;
        }
        nodeBantu = nodeBantu->next;
    }
    return Nil;
}

void hapusRiwayat(list &List, infotype cari){
    address nodeHapus = cariRiwayat(List, cari);
    if (nodeHapus == Nil){
        cout << "List Kosong" << endl;
        return;
    }

    if (List.first == List.last)
    {
        List.first = Nil;
        List.last = Nil;
    }else if (nodeHapus == List.first)
    {
        List.first = nodeHapus->next;
        List.first->prev = Nil;
    }else if (nodeHapus == List.last)
    {
        List.last = nodeHapus->prev;
        List.last->next = Nil;
    }else{
        nodeHapus->prev->next = nodeHapus->next;
        nodeHapus->next->prev = nodeHapus->prev;
    }
    dealokasi(nodeHapus);
}

void backward(list List, infotype urlAkhir) {
    address nodeAkhir = cariRiwayat(List, urlAkhir);

    if (isEmpty(List)) {
        cout << "Proses backward gagal. Riwayat kosong." << endl;
        return;
    }

    if (nodeAkhir == Nil) {
        cout << "Proses backward gagal. URL akhir '" << urlAkhir << "' tidak ditemukan." << endl;
        return;
    }

    cout << "--- Riwayat Backward (Terbaru: " << urlAkhir << ") ---" << endl;
    address nodeBantu = List.last; 

    while (nodeBantu != Nil) {
        cout << "- " << nodeBantu->url << endl;
        if (nodeBantu == nodeAkhir) {
            break;
        }
        nodeBantu = nodeBantu->prev;
    }
}

void printList(list List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << nodeBantu->url << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}