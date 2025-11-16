#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct tPanen{
    string nPanen;
    string bulan;
    int jumlah;
};

typedef tPanen infotype;
typedef struct elmList *address;

struct elmList{
    infotype x;
    address next;
};

struct list{
    address first;
};


bool isEmpty(list List);
void createList(list &List);
address createNewElm(infotype x);
void dealokasi(address &node);
void tambahData(list &List, address nodeBaru);
address panenTerbanyak(list &List);
void printList(list List);
void panenBulanan(list List, string bulan);

#endif