#ifndef DOKTER_H_INCLUDED
#define DOKTER_H_INCLUDED

#include <string>
#include "relasi.h"

using namespace std;

typedef int infotypedokter;
typedef struct elemDok *adrDok;

struct elemDok{
    infotypedokter idDokter;
    string namaDokter;
    adrDok nextDokter;
    adrRelasi firstRelasi;
};

struct listDokter{
    adrDok first;
};

void createListDokter(listDokter &LD);
adrDok createElmDokter(int id, string &nama);
void insertDokter(listDokter &LD, adrDok D);
void deleteDokter(listDokter &LD, adrDok D);
adrDok searchDok(adrDok D,infotypedokter id);
void showAllDok(listDokter LD);
void showPasienFromDokter(adrDok D);
int countPasienFromDokter(adrDok D);
void showParentFromChild(listDokter LD, adrPasien P);
adrRelasi findRelasi(adrDok D, adrPasien P);
void editRelasi(adrDok D, adrPasien P_lama, adrPasien P_baru);
int countRelasiChild(listDokter LD, adrPasien P);
void showAllChildWithParent(listDokter LD, listPasien LP);
void insertRelasi(adrDok D, adrPasien P, string tanggal, string jam);
adrRelasi findRelasi(adrDok D, adrPasien P, string tanggal, string jam);
void deleteRelasi(adrDok D, adrRelasi R);
void showRelasiDokter(adrDok D);
void showAllDokterWithPasien(listDokter LD);


#endif // DOKTER_H_INCLUDED
