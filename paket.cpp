#include "NodeXpress.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

// Fungsi untuk menghasilkan nomor resi unik
string generateNoResi() {
    static int nomorBerikutnya = 1;
    stringstream resi;
    resi << "NXP" << setw(4) << setfill('0') << nomorBerikutnya++;
    return resi.str();
}

// Fungsi untuk menampilkan daftar kurir yang tersedia
void tambahPaket() {
    tampilkanKurir();

    string id = inputTeks("\nPilih ID kurir: ");
    Kurir* kurir = cariKurir(id);

    if (kurir == nullptr) {
        cout << "ID kurir tidak ditemukan.\n";
        return;
    }

    string resi = generateNoResi();
    cout << "Nomor resiASDC: " << resi << '\n';

    string penerima = inputTeks("Nama penerima: ");
    string alamat = inputTeks("Alamat tujuan: ");
    float berat = inputBerat();

    Paket* baru = new Paket{resi, penerima, alamat, berat, nullptr};

    if (kurir->headPaket == nullptr) {
        kurir->headPaket = baru;
    } else {
        Paket* bantu = kurir->headPaket;

        while (bantu->next != nullptr) {
            bantu = bantu->next;
        }

        bantu->next = baru;
    }

    cout << "Paket berhasil ditambahkan ke kurir "
         << kurir->namaKurir << ".\n";
}

// Fungsi untuk menampilkan semua paket yang terdaftar
void lihatPaket() {
    Kurir* kurir = headKurir;
    bool adaPaket = false;

    while (kurir != nullptr) {
        if (kurir->headPaket != nullptr) {
            adaPaket = true;
            cout << "\n========================================\n";
            cout << "ID Kurir   : " << kurir->idKurir << '\n';
            cout << "Nama Kurir : " << kurir->namaKurir << '\n';

            Paket* paket = kurir->headPaket;
            while (paket != nullptr) {
                cout << "Nomor Resi : " << paket->noResi
                     << "\nPenerima   : " << paket->penerima
                     << "\nAlamat     : " << paket->alamat
                     << "\nBerat      : " << paket->berat << " kg\n";
                paket = paket->next;
            }
        }
        kurir = kurir->next;
    }

    if (!adaPaket) {
        cout << "Belum ada paket yang terdaftar.\n";
    }

    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.get();
}

// Fungsi untuk membersihkan memori yang dialokasikan untuk kurir dan paket
void bersihkanMemori() {
    Kurir* kurir = headKurir;

    while (kurir != nullptr) {
        Kurir* kurirBerikutnya = kurir->next;
        Paket* paket = kurir->headPaket;

        while (paket != nullptr) {
            Paket* paketBerikutnya = paket->next;
            delete paket;
            paket = paketBerikutnya;
        }

        delete kurir;
        kurir = kurirBerikutnya;
    }

    headKurir = nullptr;
}
