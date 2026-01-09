#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <string>
#include "pasien.h"

using namespace std;

typedef struct elemRelasi *adrRelasi;

struct elemRelasi{
    adrPasien child;
    string tanggal;
    string jam;
    adrRelasi nextRelasi;
};

struct listRelasi{
    adrRelasi first;
};

#endif // RELASI_H_INCLUDED
