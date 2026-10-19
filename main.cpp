#include <iostream>
#include "kurir.h"
#include "paket.h"
#include "bst.h"
#include "input.h"

using namespace std;

void menuKurir();
void tambahPaket();
void lihatPaket();
void cariPaket();
void updateStatus();
void hapusPaket();
void hitungOngkir();
void hapusSemua();

int main()
{
    int pilihan;

    do
    {
        cout << "\n========================================\n";
        cout << "               NODEXPRESS\n";
        cout << "    Sistem Manajemen Logistik & Ekspedisi\n";
        cout << "========================================\n";
        cout << "1. Manajemen Kurir\n";
        cout << "2. Tambah Paket\n";
        cout << "3. Lihat Paket\n";
        cout << "4. Cari Paket (BST)\n";
        cout << "5. Update Status\n";
        cout << "6. Hapus Paket\n";
        cout << "7. Hitung Ongkir\n";
        cout << "0. Keluar\n";
        cout << "========================================\n";

        pilihan = inputAngka("Pilih menu: ", 0, 7);

        switch (pilihan)
        {
        case 1:
            menuKurir();
            break;
        case 2:
            tambahPaket();
            break;
        case 3:
            lihatPaket();
            break;
        case 4:
            cariPaket();
            break;
        case 5:
            updateStatus();
            break;
        case 6:
            hapusPaket();
            break;
        case 7:
            hitungOngkir();
            break;
        case 0:
            cout << "Terima kasih telah menggunakan NodeXpress.\n";
            break;
        }
    } while (pilihan != 0);

    hapusSemua();
    return 0;
}
