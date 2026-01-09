#include <iostream>
#include "dokter.h"
#include "relasi.h"
#include "pasien.h"

using namespace std;

void createListDokter(listDokter &LD){
    LD.first = nullptr;
}

adrDok createElmDokter(int id, string &nama){
    adrDok p = new elemDok;
    p->idDokter = id;
    p->namaDokter = nama;
    p->nextDokter = nullptr;
    p->firstRelasi = nullptr;
    return p;
}

void insertDokter(listDokter &LD, adrDok D){
    if(LD.first == nullptr){
        LD.first = D;
    } else {
        adrDok p = LD.first;
        while (p->nextDokter != nullptr){
            p = p->nextDokter;
        }
        p->nextDokter = D;
    }
}

void deleteDokter(listDokter &LD, adrDok D){
    adrDok Q;
    if(LD.first->nextDokter == nullptr){
        LD.first = nullptr;
    }else if(LD.first == D){
        LD.first = D->nextDokter;
        D->nextDokter = nullptr;
    }else if(D->nextDokter == nullptr){
        Q = LD.first;
        while(Q->nextDokter != D){
            Q = Q->nextDokter;
        }
        Q->nextDokter = nullptr;
    }else{
        Q = LD.first;
        while(Q->nextDokter != D){
            Q = Q->nextDokter;
        }
        Q->nextDokter = D->nextDokter;
        D->nextDokter = nullptr;
    }
}

adrDok searchDok(adrDok D,infotypedokter id){
    if(D == nullptr){
        return nullptr;
    }
    if(D->idDokter == id){
        return D;
    }
    return searchDok(D->nextDokter, id);
}

void showAllDok(listDokter LD){
    adrDok p = LD.first;
    if(p == nullptr){
        cout << "List Dokter Kosong." << endl;
    }
    cout << "===========Daftar Dokter===========" << endl;
    while(p!=nullptr){
        cout << "ID Dokter   : " << p->idDokter << endl;
        cout << "Nama Dokter : " << p->namaDokter << endl;
        cout << "===================================" << endl;
        p = p->nextDokter;
    }
}

void showPasienFromDokter(adrDok D){
    adrRelasi R = D->firstRelasi;

    if (D == nullptr){
        cout << "Dokter tidak ditemukan" << endl;
    }

    if (R == nullptr){
        cout << "Dokter ini belum punya pasien" << endl;
    }

    cout << "Dokter : " << D->namaDokter << endl;
    while (R != nullptr){
        cout << "Nama Pasien : " << R->child->namaPasien << endl;
        cout << "Umur        : " << R->child->umurPasien << endl;
        cout << "Keluhan     : " << R->child->keluhan << endl;

        R = R->nextRelasi;
    }
}

int countPasienFromDokter(adrDok D){
    int Count = 0;
    adrRelasi R = D->firstRelasi;

    while (R != nullptr){
        Count++;
        R = R->nextRelasi;
    }
    return Count;
}

void showParentFromChild(listDokter LD, adrPasien P){
    adrDok D = LD.first;
    bool found = false;

    while (D != nullptr){
        adrRelasi R = D->firstRelasi;

        while (R != nullptr){
            if (R->child == P){
                cout << "Dokter : " << D->namaDokter << endl;
                found = true;
            }
            R = R->nextRelasi;
        }
        D = D->nextDokter;
    }

    if (!found){
        cout << "Pasien tidak memiliki relasi dengan dokter manapun" << endl;
    }
}

adrRelasi findRelasi(adrDok D, adrPasien P){
    if (D == nullptr || P == nullptr){
        return nullptr;
    }

    adrRelasi R = D->firstRelasi;

    while (R != nullptr){
        if (R->child == P){
            return R;
        }
        R = R->nextRelasi;
    }
    return nullptr;
}

void editRelasi(adrDok D, adrPasien P_lama, adrPasien P_baru){
    if (D == nullptr || P_lama == nullptr || P_baru == nullptr){
        cout << "Data tidak valid" << endl;
        return;
    }

    adrRelasi R = findRelasi(D, P_lama);

    if (R == nullptr){
        cout << "Relasi tidak ditemukan" << endl;
        return;
    }

    R->child = P_baru;

    cout << "Relasi berhasil diubah";
}

int countRelasiChild(listDokter LD, adrPasien P){
    if (P == nullptr){
        return 0;
    }

    int count = 0;
    adrDok D = LD.first;

    while (D != nullptr){
        adrRelasi R = D->firstRelasi;

        while (R != nullptr){
            if (R->child == P){
                count++;
            }
            R = R->nextRelasi;
        }
        D = D->nextDokter;
    }
    return count;
}

void showAllChildWithParent(listDokter LD, listPasien LP){
    adrPasien P = LP.first;

    if (P == nullptr){
        cout << "List pasien kosong" << endl;
        return;
    }

    while (P != nullptr){
        cout << "Pasien : " << P->namaPasien << endl;

        adrDok D = LD.first;
        bool found = false;

        while (D != nullptr){
            adrRelasi R = D->firstRelasi;

            while (R != nullptr){
                if (R->child == P){
                    cout << "  Dokter : " << D->namaDokter << endl;
                    found = true;
                }
                R = R->nextRelasi;
            }
            D = D->nextDokter;
        }

        if (!found){
            cout << "Belum memiliki dokter" << endl;
        }

        cout << "----------------------------" << endl;
        P = P->nextPasien;
    }
}

void insertRelasi(adrDok D, adrPasien P, string tanggal, string jam){
    if (D == nullptr || P == nullptr) return;

    adrRelasi R = new elemRelasi;
    R->child = P;
    R->tanggal = tanggal;
    R->jam = jam;
    R->nextRelasi = nullptr;

    if (D->firstRelasi == nullptr){
        D->firstRelasi = R;
    } else {
        adrRelasi Q = D->firstRelasi;
        while (Q->nextRelasi != nullptr){
            Q = Q->nextRelasi;
        }
        Q->nextRelasi = R;
    }
}

adrRelasi findRelasi(adrDok D, adrPasien P, string tanggal, string jam){
    if (D == nullptr){
        return nullptr;
    }

    adrRelasi R = D->firstRelasi;
    while (R != nullptr){
        if (R->child == P && R->tanggal == tanggal && R->jam == jam){
            return R;
        }
        R = R->nextRelasi;
    }
    return nullptr;
}

void deleteRelasi(adrDok D, adrRelasi R){
    if (D == nullptr || R == nullptr) return;

    if (D->firstRelasi == R){
        D->firstRelasi = R->nextRelasi;
        R->nextRelasi = nullptr;
    } else {
        adrRelasi Q = D->firstRelasi;
        while (Q->nextRelasi != R){
            Q = Q->nextRelasi;
        }
        Q->nextRelasi = R->nextRelasi;
        R->nextRelasi = nullptr;
    }
}

void showRelasiDokter(adrDok D){
    if (D == nullptr) return;

    adrRelasi R = D->firstRelasi;
    while (R != nullptr){
        cout << "Pasien  : " << R->child->namaPasien << endl;
        cout << "Tanggal : " << R->tanggal << endl;
        cout << "Jam     : " << R->jam << endl;
        cout << "----------------------" << endl;
        R = R->nextRelasi;
    }
}

void showAllDokterWithPasien(listDokter LD){
    adrDok D = LD.first;

    if (D == nullptr){
        cout << "List dokter kosong" << endl;
        return;
    }

    while (D != nullptr){
        cout << "Dokter : " << D->namaDokter << endl;

        adrRelasi R = D->firstRelasi;
        if (R == nullptr){
            cout << "  Belum memiliki pasien" << endl;
        }

        while (R != nullptr){
            cout << "  Pasien  : " << R->child->namaPasien << endl;
            cout << "  Tanggal : " << R->tanggal << endl;
            cout << "  Jam     : " << R->jam << endl;
            R = R->nextRelasi;
        }

        cout << "-----------------------------" << endl;
        D = D->nextDokter;
    }
}
