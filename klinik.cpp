#include <iostream>
#include "klinik.h"

void createListDokter(listDokter &L){
    L.first = nullptr;
}

adrDok allocateDokter(infotypedokter x){
    adrDok p;
    p = new elemDok;
    p->idDokter = x;
    p->nextDokter = nullptr;
    createListDokter()
}

adrDok createDokter(int id, string name){
    adrDok D = new elemDok;
    D->idDokter = id;
    D->namaDokter = nama;
    D->nextDokter = nullptr;
    D->firstRelasi = nullptr;
    return D;
}

void createListParent(listDokter &L, adrDok D){
    if (L.first == nullptr){
        L.first = D;
    }else{
        D->nextDokter = L.first;
        L.first = D;
    }
}

