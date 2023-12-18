#include "header.h"

int selectMenu() {
    int input;

    cout << "========== MENU APLIKASI AMBA ==========" << endl;
    cout << "1.  Insert Data                 (Parent)" << endl;
    cout << "2.  Show All Data               (Parent)" << endl;
    cout << "3.  Delete Data                 (Parent)" << endl;
    cout << "4.  Find Data                   (Parent)" << endl;
    cout << "5.  Insert Data                  (Child)" << endl;
    cout << "6.  Show All Data       (Parent & Child)" << endl;
    cout << "7.  Delete Data                  (Child)" << endl;
    cout << "8.  Find Data                    (Child)" << endl;
    cout << "9.  Hubungkan Relasi    (Parent & Child)" << endl;
    cout << "0. EXIT" << endl;
    cout << "========================================" << endl;
    cout << "Pilihan : ";

    cin >> input;
    return input;
}

void createListWaktu(ListWaktu &LW) {
    first(LW) = NULL;
}
void createListKegiatan(ListKegiatan &LK) {
    first(LK) = NULL;
}

adr_waktu alokasiWaktu(infotypeW input) {
    adr_waktu P;

    P = new elementWaktu;
    info(P) = input;
    next(P) = NULL;
    firstE(P) = NULL;
    return P;
}

adr_kegiatan alokasiKegiatan(infotypeK input) {
    adr_kegiatan P;

    P = new elementKegiatan;
    infoK(P) = input;
    nextK(P) = NULL;
    prevK(P) = NULL;
    return P;
}


adr_edge alokasiEdge() {
    adr_edge Q;

    Q = new elementEdge;
    nextE(Q) = NULL;
    nextK(Q) = NULL;
    return Q;
}


void insertLastWaktu(ListWaktu &LW, adr_waktu PW){
    adr_waktu Q;
    Q = first(LW);

    if (Q == NULL) {
        first(LW) = PW;
        next(PW) = NULL;
    } else {
        while (next(Q)!= NULL) {
            Q = next(Q);
        }
        next(Q) = PW;
        next(PW) = NULL;
    }
}

void insertFirstWaktu(ListWaktu &LW, adr_waktu PW){
    adr_waktu Q;
    Q = first(LW);

    if (Q == NULL) {
        first(LW) = PW;
        next(PW) = NULL;
    } else {
        next(PW) = Q;
        first(LW) = PW;
    }
}

void showParent(ListWaktu &LW) {
    adr_waktu PW;
    PW = first(LW);

    if (PW == NULL) {
        cout << "Data Kosong" << endl;
    } else {
        while (PW != NULL) {
            cout << info(PW).bulan << " " << info(PW).tahun << endl;
            PW = next(PW);
        }
    }
}

void procedureInsertWaktu(ListWaktu &LW) {
    int pilihan;
    infotypeW input;

    cout << "============ MASUKKAN  DATA ============" << endl;
    cout << "1. Depan" << endl;
    cout << "2. Belakang" << endl;
    cout << "0. Back" << endl;
    cout << "Pilihan : ";
    cin >> pilihan;
    while (pilihan != 0) {
        switch(pilihan) {
            case 1: {
                cout << endl;
                cout << "Masukkan Bulan : ";
                cin >> input.bulan;
                cout << "Masukkan Tahun : ";
                cin >> input.tahun;
                insertFirstWaktu(LW, alokasiWaktu(input));
                break;
            }

            case 2: {
                cout << endl;
                cout << "Masukkan Bulan : ";
                cin >> input.bulan;
                cout << "Masukkan Tahun : ";
                cin >> input.tahun;
                insertLastWaktu(LW, alokasiWaktu(input));
                break;
            }
        }
        cout << endl;
        cout << "============ MASUKKAN  DATA ============" << endl;
        cout << "1. Depan" << endl;
        cout << "2. Belakang" << endl;
        cout << "0. Back" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;
    }
}

void deleteFirstWaktu(ListWaktu &LW, adr_waktu &PW) {
    adr_waktu QW;

    QW = first(LW);
    if (QW == NULL) {
        cout << "List Kosong" << endl;
    } else if (next(QW) == NULL) {
        first(LW) = NULL;
    } else {
        PW = first(LW);
        first(LW) = next(PW);
        next(PW) = NULL;
    }
}

void deleteWaktu(ListWaktu &LW) {
    adr_waktu QW,hasil;
    QW = first(LW);

    int tahun;
    string bulan;
    showParent(LW);

    if (QW != NULL) {
        cout << "Delete Data Berdasarkan (Bulan, Tahun)" << endl;
        cout << "Masukkan Bulan : ";
        cin >> bulan;
        cout << "Masukkan Tahun : ";
        cin >> tahun;

        hasil = findWaktu(LW,bulan,tahun);
        if (hasil != NULL) {
            if (hasil == first(LW)) {
                deleteFirstWaktu(LW,QW);
            } else if (next(hasil) == NULL) {
                deleteLastWaktu(LW,QW);
            } else {
                deleteAfterWaktu(LW, findPrecWaktu(LW, bulan, tahun),QW);
            }
        } else {
            cout << endl;
            cout << "Data tidak ditemukan" << endl;
        }
    }
}

void deleteLastWaktu(ListWaktu &LW, adr_waktu &PW) {
    adr_waktu QW;

    QW = first(LW);
    if (QW == NULL) {
        cout << "List Kosong" << endl;
    } else if (next(QW) == NULL) {
        first(LW) = NULL;
    } else {
        while (next(next(QW)) != NULL) {
            QW = next(QW);
        }
        next(QW) = NULL;
    }
}

void deleteAfterWaktu(ListWaktu &LW, adr_waktu prec, adr_waktu &PW) {
    PW = next(prec);
    next(prec) = next(PW);
}

adr_waktu findWaktu(ListWaktu LW, string bulan , int tahun) {
    adr_waktu PW;

    PW = first(LW);
    while (PW != NULL) {
        if (info(PW).bulan == bulan && info(PW).tahun == tahun) {
            return PW;
        }
        PW = next(PW);
    }
    return NULL;
}

adr_waktu findPrecWaktu(ListWaktu LW, string bulan , int tahun) {
    adr_waktu PW;

    PW = first(LW);
    while (PW != NULL) {
        if (info(next(PW)).bulan == bulan && info(next(PW)).tahun == tahun) {
            return PW;
        }
        PW = next(PW);
    }
    return NULL;
}

void insertFirstKegiatan(ListKegiatan &LK, adr_kegiatan PK) {
    adr_kegiatan QK;

    QK = first(LK);
     if (QK == NULL) {
        first(LK) = PK;
        last(LK) = PK;
    } else {
        nextK(PK) = first(LK);
        prevK(first(LK)) = PK;
        first(LK) =PK;
    }
}

void insertLastKegiatan(ListKegiatan &LK, adr_kegiatan PK) {
    adr_kegiatan QK;

    QK = first(LK);
     if (QK == NULL) {
        first(LK) = PK;
        last(LK) = PK;
    } else {
        prevK(PK) = last(LK);
        nextK(last(LK)) = PK;
        last(LK) = PK;
    }
}

void procedureInsertKegiatan(ListKegiatan &LK) {
    int pilihan;
    infotypeK input;

    cout << "============ MASUKKAN  DATA ============" << endl;
    cout << "1. Depan" << endl;
    cout << "2. Belakang" << endl;
    cout << "0. Back" << endl;
    cout << "Pilihan : ";
    cin >> pilihan;
    while (pilihan != 0) {
        switch(pilihan) {
            case 1: {
                cout << endl;
                cout << "Masukkan Jenis Kegiatan : ";
                cin >> input.jenis;
                cout << "Masukkan Nominal Pengeluaran : ";
                cin >> input.nominal;
                insertFirstKegiatan(LK, alokasiKegiatan(input));
                break;
            }

            case 2: {
                cout << endl;
                cout << "Masukkan Jenis Kegiatan : ";
                cin >> input.jenis;
                cout << "Masukkan Nominal Pengeluaran : ";
                cin >> input.nominal;
                insertLastKegiatan(LK, alokasiKegiatan(input));
                break;
            }
        }
        cout << endl;
        cout << "============ MASUKKAN  DATA ============" << endl;
        cout << "1. Depan" << endl;
        cout << "2. Belakang" << endl;
        cout << "0. Back" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;
    }
}

void showChild(ListKegiatan &LK) {
    adr_kegiatan PK;
    PK= first(LK);

    if (PK == NULL) {
        cout << "Data Kosong" << endl;
    } else {
        while (PK != NULL) {
            cout << infoK(PK).jenis << " " << infoK(PK).nominal << endl;
            PK = nextK(PK);
        }
    }
}

void deleteKegiatan(ListKegiatan &LK) {
    adr_kegiatan QK,hasil;
    QK = first(LK);

    int nominal;
    string jenis;
    showChild(LK);

    if (QK != NULL) {
        cout << "Delete Data Berdasarkan (Jenis, Nominal)" << endl;
        cout << "Masukkan Jenis Kegiatan : ";
        cin >> jenis;
        cout << "Masukkan Nominal Pengeluaran : ";
        cin >> nominal;

        hasil = findKegiatan(LK,jenis,nominal);
        if (hasil != NULL) {
            if (hasil == first(LK)) {
                deleteFirstKegiatan(LK,QK);
            } else if (nextK(hasil) == NULL) {
                deleteLastKegiatan(LK,QK);
            } else {
                deleteAfterKegiatan(LK, prevK(hasil),QK);
            }
        } else {
            cout << endl;
            cout << "Data tidak ditemukan" << endl;
        }
    }
}

void deleteFirstKegiatan(ListKegiatan &LK, adr_kegiatan &PK) {
    adr_kegiatan QK;

    QK = first(LK);
    if (QK == NULL) {
       cout << "Data Kosong" << endl;
    } else if (first(LK) == last(LK)) {
        PK = first(LK);
        first(LK) = NULL;
        last(LK) = NULL;
    } else {
        PK = first(LK);
        first(LK) = nextK(PK);
        nextK(PK) = NULL;
        prevK(first(LK)) = NULL;
    }

}
void deleteLastKegiatan(ListKegiatan &LK, adr_kegiatan &PK) {
    adr_kegiatan QK;

    QK = first(LK);
    if (QK == NULL) {
       cout << "Data Kosong" << endl;
    } else {
        PK = last(LK);
        last(LK) = prevK(PK);
        nextK(prevK(PK)) = NULL;
        prevK(PK) = NULL;
    }

}

void deleteAfterKegiatan(ListKegiatan &LK, adr_kegiatan prec, adr_kegiatan &PK) {
    adr_kegiatan QK;

    QK = first(LK);
    if (QK == NULL) {
       cout << "Data Kosong" << endl;
    } else {
        PK = nextK(prec);
        nextK(prec) = nextK(PK);
        prevK(nextK(PK)) = prec;
        prevK(PK) = NULL;
        nextK(PK) = NULL;
    }

}

adr_kegiatan findKegiatan(ListKegiatan LK, string jenis , int nominal) {
    adr_kegiatan PK;

    PK = first(LK);
    while (PK != NULL) {
        if (infoK(PK).jenis == jenis && infoK(PK).nominal == nominal) {
            return PK;
        }
        PK = nextK(PK);
    }
    return NULL;
}

void connectRelasi(ListKegiatan &LK, ListWaktu &LW, string bulan, int tahun, string jenis, int nominal) {
    adr_kegiatan PK; //child
    adr_waktu PW; //parent

    PK = findKegiatan(LK, jenis,nominal);
    PW = findWaktu(LW,bulan,tahun);
    if (PK == NULL && PW == NULL) {
        cout << "Data Waktu dan Data Kegiatan Tidak Ada" << endl;
    } else if (PK == NULL && PW != NULL) {
        cout << "Data Kegiatan Tidak Ada" << endl;
    } else if (PK != NULL && PW == NULL) {
        cout << "Data Waktu Tidak Ada" << endl;
    } else {
        info(PW).jmlRelasi++;
        adr_edge PE;
        PE = alokasiEdge();
        if (firstE(PW) == NULL) {
            firstE(PW) = PE;
            nextK(PE) = PK;
        } else {
            adr_edge QE;
            QE = firstE(PW);
            while (nextE(QE) != NULL) {
                QE = nextE(QE);
            }
            nextE(QE) = PE;
            nextK(PE) = PK;
        }

    }
}

void procedureRelasi(ListWaktu &LW, ListKegiatan &LK) {
    string bulan,kegiatan;
    int tahun, nominal;

    cout << "Data Waktu : " << endl;
    showParent(LW);
    cout << endl;
    cout << "Data Kegiatan : " << endl;
    showChild(LK);
    cout << endl;
    cout << "Hubungkan Relasi (Bulan, Tahun) dan (Kegiatan, Nominal)" << endl;
    cout << "Masukkan Bulan : ";
    cin >> bulan;
    cout << "Masukkan Tahun : ";
    cin >> tahun;
    cout << "Masukkan Kegiatan : ";
    cin >> kegiatan;
    cout << "Masukkan Nominal : ";
    cin >> nominal;
    connectRelasi(LK,LW,bulan,tahun,kegiatan,nominal);
}

void showParentChild(ListKegiatan LK, ListWaktu LW) {
    adr_waktu PW;
    adr_edge PE;

    PW = first(LW);

    if (PW != NULL) {
        while (PW != NULL) {
            cout << endl;
            cout << info(PW).bulan << " " << info(PW).tahun << endl;
            cout <<"Dengan relasi : " << endl;

            PE = firstE(PW);
            if (PE != NULL) {
                while (PE != NULL) {
                    cout << infoK(nextK(PE)).jenis << " " << infoK(nextK(PE)).nominal << endl;
                    PE = nextE(PE);
                }
            } else {
                cout << "Data Tidak Memiliki Relasi" << endl;
            }
            cout << "Jumlah Relasi / Child : " <<info(PW).jmlRelasi << endl;
            PW = next(PW);
        }
    } else {
        cout << "Data Kosong" << endl;
    }
}







