#include "list.h"
#include<iostream>
using namespace std;

int main(){
    list L;

    createList(L);
    tambahData(L, createNewElm("igracias"));
    tambahData(L, createNewElm("outlook"));
    tambahData(L, createNewElm("chatGPT"));
    tambahData(L, createNewElm("google"));

    hapusRiwayat(L, "igracias");
    printList(L);

    backward(L, "chatGPT");
}