#ifndef PASIEN_H_INCLUDED
#define PASIEN_H_INCLUDED

#include <string>
using namespace std;

typedef int infotypepasien;
typedef struct elemPasien *adrPasien;

struct elemPasien{
    string namaPasien;
    infotypepasien umurPasien;
    string keluhan;
    adrPasien nextPasien;
};

struct listPasien{
    adrPasien first;
};

void createListPasien(listPasien &LP);
adrPasien createElmPasien(string nama, int umur, string keluhan);
void insertPasien(listPasien &LP, adrPasien P);
void deletePasien(listPasien &LP, adrPasien P);
adrPasien findPasien(listPasien LP, string nama);
void showAllPasien(listPasien LP);


#endif // PASIEN_H_INCLUDED
