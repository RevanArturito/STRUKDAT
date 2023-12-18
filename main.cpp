#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    int pilihan;
    ListWaktu LW;
    ListKegiatan LK;
    createListWaktu(LW);
    createListKegiatan(LK);


    infotypeK inputK;
    inputK.jenis = "a";
    inputK.nominal = 1;

    insertLastKegiatan(LK, alokasiKegiatan(inputK));

    inputK.jenis = "b";
    inputK.nominal = 2;

    insertLastKegiatan(LK, alokasiKegiatan(inputK));

    infotypeW inputW;
    inputW.bulan = "januari";
    inputW.tahun = 2023;

    insertLastWaktu(LW, alokasiWaktu(inputW));

    inputW.bulan = "februari";
    inputW.tahun = 2023;

    insertLastWaktu(LW, alokasiWaktu(inputW));


    pilihan = selectMenu();
    while (pilihan != 0) {
        switch(pilihan) {
            case 1:
            {
                cout << endl;
                procedureInsertWaktu(LW);
                cout << endl;
                break;
            }
            case 2: {
                cout << endl;
                showParent(LW);
                cout <<endl;
                break;
            }
            case 3: {
                 cout << endl;
                 deleteWaktu(LW);
                 cout << endl;
                break;
            }
            case 4: {
                 cout << "4" << endl;
                break;
            }
            case 5: {
                 cout << endl;
                 procedureInsertKegiatan(LK);
                 cout << endl;
                break;
            }
            case 6: {
                 cout << endl;
                 showParentChild(LK,LW);
                 cout << endl;
                break;
            }
            case 7: {
                 cout << endl;
                 deleteKegiatan(LK);
                 cout << endl;
                break;
            }
            case 8: {
                 cout << "8" << endl;
                break;
            }
            case 9: {
                 cout << endl;
                 procedureRelasi(LW, LK);
                 cout << endl;
                break;
            }
        }
        pilihan = selectMenu();
    }
    cout << "endprogram " <<endl;
    return 0;
}




