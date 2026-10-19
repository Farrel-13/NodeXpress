#include "NodeXpress.h"
#include <iostream>

using namespace std;

// Fungsi utama program
int main()
{
    tambahKurir("K01", "Farrel");
    tambahKurir("K02", "Barret");
    tambahKurir("K03", "Acaa");
    tambahKurir("K04", "Julian Cogan");

    int pilihan;

    // Loop utama untuk menampilkan menu dan menangani pilihan pengguna
    do
    {
        cout << "\n========================================\n";
        cout << "               NODEXPRESS\n";
        cout << "    Sistem Manajemen Logistik & Ekspedisi\n";
        cout << "========================================\n";
        cout << "1. Tambah Paket\n";
        cout << "2. Lihat Paket\n";
        cout << "3. Cari Paket\n";
        cout << "4. Update Status\n";
        cout << "5. Hapus Paket\n";
        cout << "6. Hitung Ongkir\n";
        cout << "0. Keluar\n";
        cout << "========================================\n";

        pilihan = inputAngka("Pilih menu: ", 0, 6);

        // Menangani pilihan pengguna
        switch (pilihan)
        {
        case 1:
            tambahPaket();
            break;
        case 2:
            lihatPaket();
            break;
        case 3:
            cout << "Fitur Cari Paket belum tersedia pada Progres 1.\n";
            break;
        case 4:
            cout << "Fitur Update Status belum tersedia pada Progres 1.\n";
            break;
        case 5:
            cout << "Fitur Hapus Paket belum tersedia pada Progres 1.\n";
            break;
        case 6:
            cout << "Fitur Hitung Ongkir belum tersedia pada Progres 1.\n";
            break;
        case 0:
            bersihkanMemori();
            cout << "Program selesai.\n";
            break;
        }
    } while (pilihan != 0);

    return 0;
}
