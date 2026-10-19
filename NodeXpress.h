#ifndef NODEXPRESS_H
#define NODEXPRESS_H

#include <string>
using namespace std;

// Struktur data untuk Paket
struct Paket
{
    string noResi;
    string penerima;
    string alamat;
    float berat;
    Paket *next;
};

// Struktur data untuk Kurir
struct Kurir
{
    string idKurir;
    string namaKurir;
    Kurir *next;
    Paket *headPaket;
};

extern Kurir *headKurir;

// Fungsi-fungsi yang digunakan dalam program
void bersihkanInput();
int inputAngka(const string &pesan, int minimum, int maksimum);
float inputBerat();
string inputTeks(const string &pesan);

void tambahKurir(const string &id, const string &nama);
Kurir *cariKurir(const string &id);
void tampilkanKurir();

void tambahPaket();
void lihatPaket();
void bersihkanMemori();

#endif
