#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

typedef string infotype;
typedef struct elmList *address;

struct elmList{
    infotype url;
    address next, prev;
};

struct list{
    address first, last;
};


bool isEmpty(list List);
void createList(list &List);
address createNewElm(infotype x);
void dealokasi(address &node);
void tambahData(list &List, address nodeBaru);
void printList(list List);
address cariRiwayat(list List, infotype cari);
void hapusRiwayat(list &List, infotype cari);
void backward(list List, infotype urlAkhir);

#endif