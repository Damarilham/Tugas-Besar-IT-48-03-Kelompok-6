#include <iostream>
#include "pasien.h"

using namespace std;

void createListPasien(listPasien &LP){
    LP.first = nullptr;
}

adrPasien createElmPasien(string nama, int umur, string keluhan){
    adrPasien P = new elemPasien;
    P->namaPasien = nama;
    P->umurPasien = umur;
    P->keluhan = keluhan;
    P->nextPasien = nullptr;
    return P;
}

void insertPasien(listPasien &LP, adrPasien P){
    if (LP.first == nullptr){
        LP.first = P;
    } else {
        adrPasien Q = LP.first;
        while (Q->nextPasien != nullptr){
            Q = Q->nextPasien;
        }
        Q->nextPasien = P;
    }
}

void deletePasien(listPasien &LP, adrPasien P){
    if (LP.first == nullptr || P == nullptr){
        return;
    }

    if (LP.first == P){
        LP.first = P->nextPasien;
        P->nextPasien = nullptr;
    } else {
        adrPasien Q = LP.first;
        while (Q->nextPasien != nullptr && Q->nextPasien != P){
            Q = Q->nextPasien;
        }

        if (Q->nextPasien == P){
            Q->nextPasien = P->nextPasien;
            P->nextPasien = nullptr;
        }
    }
}

adrPasien findPasien(listPasien LP, string nama){
    adrPasien P = LP.first;
    while (P != nullptr){
        if (P->namaPasien == nama){
            return P;
        }
        P = P->nextPasien;
    }
    return nullptr;
}

void showAllPasien(listPasien LP){
    adrPasien P = LP.first;

    if (P == nullptr){
        cout << "List Pasien Kosong" << endl;
        return;
    }

    cout << "========== DAFTAR PASIEN ==========" << endl;
    while (P != nullptr){
        cout << "Nama    : " << P->namaPasien << endl;
        cout << "Umur    : " << P->umurPasien << endl;
        cout << "Keluhan : " << P->keluhan << endl;
        cout << "===================================" << endl;
        P = P->nextPasien;
    }
}
