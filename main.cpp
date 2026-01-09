#include <iostream>
#include "dokter.h"
#include "pasien.h"

using namespace std;

listDokter LD;
listPasien LP;

void menuAdmin();
void menuDokter();
void menuPasien();
void menuRelasi();

int main(){
    createListDokter(LD);
    createListPasien(LP);

    menuAdmin();
    return 0;
}

void menuAdmin(){
    int option = -99;

    while(option != 0){
        system("cls");
        cout << "============ MENU ADMIN ============" << endl;
        cout << "|| 1. Dokter (Parent)             ||" << endl;
        cout << "|| 2. Pasien (Child)              ||" << endl;
        cout << "|| 3. Relasi (Kunjungan)          ||" << endl;
        cout << "|| 0. Exit                        ||" << endl;
        cout << "====================================" << endl;
        cout << "Choose option: ";
        cin >> option;

        switch(option){
            case 1: menuDokter(); break;
            case 2: menuPasien(); break;
            case 3: menuRelasi(); break;
        }
    }
}

void menuDokter(){
    int option = -99;

    while(option != 0){
        system("cls");
        cout << "=============  MENU DOKTER  ============" << endl;
        cout << "|| 1. Insert Dokter                   ||" << endl;
        cout << "|| 2. Show All Dokter                 ||" << endl;
        cout << "|| 3. Find Dokter                     ||" << endl;
        cout << "|| 4. Delete Dokter                   ||" << endl;
        cout << "|| 5. Show All Dokter dan pasien      ||" << endl;
        cout << "|| 0. Back                            ||" << endl;
        cout << "========================================" << endl;
        cout << "Choose: ";
        cin >> option;

        switch(option){
        case 1:{
            int id;
            string nama;
            cout << "ID Dokter   : ";
            cin >> id;
            cout << "Nama Dokter : ";
            cin >> nama;

            adrDok D = createElmDokter(id, nama);
            insertDokter(LD, D);
            cout << "Dokter berhasil ditambahkan" << endl;
            break;
        }

        case 2:
            showAllDok(LD);
            system("pause");
            break;

        case 3:{
            int id;
            cout << "ID Dokter : ";
            cin >> id;

            adrDok D = searchDok(LD.first, id);
            if(D != nullptr){
                cout << "Dokter ditemukan: " << D->namaDokter << endl;
            }else{
                cout << "Dokter tidak ditemukan" << endl;
            }
            system("pause");
            break;
        }
        case 4:{
            int id;
            cout << "ID Dokter yang akan dihapus : ";
            cin >> id;

            adrDok D = searchDok(LD.first, id);
            if(D != nullptr){
                deleteDokter(LD, D);
                cout << "Dokter berhasil dihapus " << endl;
            }else{
                cout << "Dokter tidak ditemukan" << endl;
            }
            system("pause");
            break;
        }

        case 5:
            showAllDokterWithPasien(LD);
            system("pause");
            break;
        }
    }
}

void menuPasien(){
    int option = -99;

    while(option != 0){
        system("cls");
        cout << "===========  MENU PASIEN  ===========" << endl;
        cout << "|| 1. Insert Pasien                ||" << endl;
        cout << "|| 2. Show All Pasien              ||" << endl;
        cout << "|| 3. Find Pasien                  ||" << endl;
        cout << "|| 4. delete pasien                ||" << endl;
        cout << "|| 5. Show All Pasien dari dokter  ||" << endl;
        cout << "|| 0. Back                         ||" << endl;
        cout << "=====================================" << endl;
        cout << "Choose: ";
        cin >> option;

        switch(option){
        case 1:{
            string nama, keluhan;
            int umur;

            cout << "Nama Pasien : ";
            cin >> nama;

            cout << "Umur        : ";
            cin >> umur;

            cout << "Keluhan     : ";
            cin >> keluhan;

            adrPasien P = createElmPasien(nama, umur, keluhan);
            insertPasien(LP, P);
            cout << "Pasien berhasil ditambahkan" << endl;
            break;
        }

        case 2:
            showAllPasien(LP);
            system("pause");
            break;

        case 3:{
            string nama;
            cout << "Nama Pasien : ";
            cin >> nama;

            adrPasien P = findPasien(LP, nama);
            if(P != nullptr){
                cout << "=== Pasien ditemukan ===" << endl;
                cout << "Nama    : " << P->namaPasien << endl;
                cout << "Umur    : " << P->umurPasien << endl;
                cout << "Keluhan : " << P->keluhan << endl;
            }else{
                cout << "Pasien tidak ditemukan" << endl;
            }
            system("pause");
            break;
        }
        case 4:{
            string nama;
            cout << "Nama Pasien yang akan dihapus : ";
            cin >> nama;

            adrPasien P = findPasien(LP, nama);
            if (P != nullptr){
                deletePasien(LP, P);
                cout << "Pasien berhasil dihapus" << endl;
            }else{
                cout << "Pasien tidak ditemukan" << endl;
            }
            system("pause");
            break;
        }

        case 5:
            showAllChildWithParent(LD,LP);
            system("pause");
            break;
        }
    }
}

void menuRelasi(){
    int option = -99;

    while(option != 0){
        system("cls");
        cout << "========== MENU RELASI ==========" << endl;
        cout << "|| 1. Insert Relasi            ||" << endl;
        cout << "|| 2. Show Pasien dari Dokter  ||" << endl;
        cout << "|| 3. Show Dokter dari Pasien  ||" << endl;
        cout << "|| 4. Edit Relasi              ||" << endl;
        cout << "|| 5. Delete Relasi            ||" << endl;
        cout << "|| 6. Jumlah Pasien            ||" << endl;
        cout << "|| 0. Back                     ||" << endl;
        cout << "=================================" << endl;
        cout << "Choose: ";
        cin >> option;

        switch(option){
        case 1:{
            int id;
            string namaPasien, tanggal, jam;

            cout << "ID Dokter   : ";
            cin >> id;

            cout << "Nama Pasien : ";
            cin >> namaPasien;

            cout << "Tanggal     : ";
            cin >> tanggal;

            cout << "Jam         : ";
            cin >> jam;

            adrDok D = searchDok(LD.first, id);
            adrPasien P = findPasien(LP, namaPasien);

            if(D != nullptr && P != nullptr){
                insertRelasi(D, P, tanggal, jam);
                cout << "Relasi berhasil ditambahkan" << endl;
            }else{
                cout << "Dokter atau Pasien tidak ditemukan" << endl;
            }
            system("pause");
            break;
        }

        case 2:{
            int id;
            cout << "ID Dokter : ";
            cin >> id;

            adrDok D = searchDok(LD.first, id);
            if(D != nullptr){
                showPasienFromDokter(D);
            }else{
                cout << "Dokter tidak ditemukan" << endl;
            }
            system("pause");
            break;
        }

        case 3:{
            string namaPasien;
            cout << "Nama Pasien : ";
            cin >> namaPasien;

            adrPasien P = findPasien(LP, namaPasien);
            if(P != nullptr){
                showParentFromChild(LD, P);
            }else{
                cout << "Pasien tidak ditemukan" << endl;
            }
            system("pause");
            break;
        }

        case 4:{
            int id;
            string lama, baru;

            cout << "ID Dokter        : ";
            cin >> id;
            cout << "Pasien Lama     : ";
            cin >> lama;
            cout << "Pasien Baru     : ";
            cin >> baru;

            adrDok D = searchDok(LD.first, id);
            adrPasien P_lama = findPasien(LP, lama);
            adrPasien P_baru = findPasien(LP, baru);

            if(D != nullptr && P_lama != nullptr && P_baru != nullptr){
                editRelasi(D, P_lama, P_baru);
            }else{
                cout << "Data tidak valid" << endl;
            }
            system("pause");
            break;
        }

        case 5:{
            int id;
            string namaPasien, tanggal, jam;

            cout << "ID Dokter   : ";
            cin >> id;
            cout << "Nama Pasien : ";
            cin >> namaPasien;
            cout << "Tanggal     : ";
            cin >> tanggal;
            cout << "Jam         : ";
            cin >> jam;

            adrDok D = searchDok(LD.first, id);
            adrPasien P = findPasien(LP, namaPasien);

            if (D != nullptr && P != nullptr){
                adrRelasi R = findRelasi(D, P, tanggal, jam);
                if (R != nullptr){
                    deleteRelasi(D, R);
                    cout << "Relasi berhasil dihapus" << endl;
                }else{
                    cout << "Relasi tidak ditemukan" << endl;
                }
            }else{
                cout << "Dokter / Pasien tidak ditemukan" << endl;
            }
            system("pause");
            break;
        }
        case 6:{
            string nama;
            cout << "Nama Pasien : ";
            cin >> nama;

            adrPasien P = findPasien(LP, nama);
            if (P != nullptr){
                cout << "Jumlah relasi pasien "
                    << P->namaPasien << " = "
                    << countRelasiChild(LD, P) << endl;
            }else{
                cout << "Pasien tidak ditemukan" << endl;
            }
            system("pause");
            break;
        }
        }
    }
}
