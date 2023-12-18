#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>

#define info(P) P->info
#define infoK(P) P->infoK
#define nextE(P) P->nextE
#define firstE(P) P->firstE
#define next(P) P->next
#define nextK(P) P->nextK
#define prevK(P) P->prevK
#define first(L) (L).first
#define last(L) (L).last

using namespace std;

// parent 1
struct Kegiatan {
    string jenis;
    int nominal;
};

struct Waktu {
    int tahun;
    string bulan;
    int jmlRelasi = 0;
};

typedef struct elementKegiatan *adr_kegiatan;
typedef struct Kegiatan infotypeK;
typedef struct elementWaktu *adr_waktu;
typedef struct Waktu infotypeW;
typedef struct elementEdge *adr_edge;

struct elementWaktu {
    infotypeW info;
    adr_waktu next;
    adr_edge firstE;
};

struct elementEdge {
    adr_edge nextE;
    adr_kegiatan nextK;
};

struct elementKegiatan {
    adr_kegiatan nextK;
    adr_kegiatan prevK;
    infotypeK infoK;
    adr_edge nextE;
};

struct ListWaktu {
    adr_waktu first;
};

struct ListKegiatan {
    adr_kegiatan first;
    adr_kegiatan last;
};

void mainProcedure();
int selectMenu();
void createListWaktu(ListWaktu &LW);
void createListKegiatan(ListKegiatan &LK);
adr_waktu alokasiWaktu(infotypeW input);
adr_kegiatan alokasiKegiatan(infotypeK input);
adr_edge alokasiEdge();
void insertFirstWaktu(ListWaktu &Lw,adr_waktu PW);
void insertLastWaktu(ListWaktu &Lw,adr_waktu PW);
void showParent(ListWaktu &LW);
void procedureInsertWaktu(ListWaktu &LW);
void deleteWaktu (ListWaktu &LW);
void deleteFirstWaktu(ListWaktu &LW, adr_waktu &PW);
void deleteLastWaktu(ListWaktu &LW, adr_waktu &PW);
void deleteAfterWaktu(ListWaktu &LW, adr_waktu prec, adr_waktu &PW);
adr_waktu findWaktu(ListWaktu LW, string bulan , int tahun);
adr_waktu findPrecWaktu(ListWaktu LW, string bulan , int tahun);
void insertFirstKegiatan(ListKegiatan &LK, adr_kegiatan PK);
void insertLastKegiatan(ListKegiatan &LK, adr_kegiatan PK);
void procedureInsertKegiatan(ListKegiatan &LK);
void showChild(ListKegiatan &LK);
void deleteKegiatan(ListKegiatan &LK);
void deleteFirstKegiatan(ListKegiatan &LK, adr_kegiatan &PK);
void deleteLastKegiatan(ListKegiatan &LK, adr_kegiatan &PK);
void deleteAfterKegiatan(ListKegiatan &LK, adr_kegiatan prec, adr_kegiatan &PK);
adr_kegiatan findKegiatan(ListKegiatan LK, string jenis , int nominal);
void procedureRelasi(ListWaktu &LW, ListKegiatan &LK);
void connectRelasi(ListKegiatan &LK, ListWaktu &LW, string bulan, int tahun, string jenis, int nominal);
void showParentChild(ListKegiatan LK, ListWaktu LW);

#endif // HEADER_H_INCLUDED
