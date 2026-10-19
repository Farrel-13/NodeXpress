#include "NodeXpress.h"
#include <iostream>
#include <limits>

using namespace std;

Kurir *headKurir = nullptr;

// Fungsi untuk membersihkan input buffer
void bersihkanInput()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Fungsi untuk meminta input angka dari pengguna dengan validasi
int inputAngka(const string &pesan, int minimum, int maksimum)
{
    int nilai;

    while (true)
    {
        cout << pesan;
        if (cin >> nilai && nilai >= minimum && nilai <= maksimum)
        {
            bersihkanInput();
            return nilai;
        }

        cout << "Input tidak valid. Silakan coba lagi.\n";
        cin.clear();
        bersihkanInput();
    }
}
// Fungsi untuk meminta input berat paket dari pengguna dengan validasi
float inputBerat()
{
    float berat;

    while (true)
    {
        cout << "Berat paket (kg): ";
        if (cin >> berat && berat > 0)
        {
            bersihkanInput();
            return berat;
        }

        cout << "Berat harus lebih dari 0.\n";
        cin.clear();
        bersihkanInput();
    }
}

// Fungsi untuk meminta input teks dari pengguna dengan validasi
string inputTeks(const string &pesan)
{
    string teks;

    cout << pesan;
    getline(cin, teks);

    while (teks.empty())
    {
        cout << "Data tidak boleh kosong. " << pesan;
        getline(cin, teks);
    }

    return teks;
}

// Fungsi untuk menambahkan kurir baru ke dalam daftar
void tambahKurir(const string &id, const string &nama)
{
    Kurir *baru = new Kurir{id, nama, nullptr, nullptr};

    if (headKurir == nullptr)
    {
        headKurir = baru;
        return;
    }

    Kurir *bantu = headKurir;
    while (bantu->next != nullptr)
    {
        bantu = bantu->next;
    }

    bantu->next = baru;
}
// Fungsi untuk mencari kurir berdasarkan ID
Kurir *cariKurir(const string &id)
{
    Kurir *bantu = headKurir;

    while (bantu != nullptr)
    {
        if (bantu->idKurir == id)
        {
            return bantu;
        }
        bantu = bantu->next;
    }

    return nullptr;
}

// Fungsi untuk menampilkan daftar kurir yang tersedia
void tampilkanKurir()
{
    Kurir *bantu = headKurir;

    cout << "\n--- DAFTAR KURIR ---\n";
    while (bantu != nullptr)
    {
        cout << bantu->idKurir << " - " << bantu->namaKurir << '\n';
        bantu = bantu->next;
    }
}
