#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define MAX 25

struct waktu {
    string tahun;
};

struct rincian {
    string jenis, asal, nama;
    waktu wktu;
};

struct regis {
    string usr, pw;
};

rincian koleksi[MAX];
regis pengguna[MAX];

int jumlahKoleksi = 0;
int jumlahPengguna = 0;
int percobaan = 0;
bool masukBerhasil = false;
int indeksPenggunaLogin = -1;

void registrasi(regis* pengguna, int* jumlahPengguna) {
    string namaPengguna, kataSandi;
    bool penggunaAda = false;

    cout << "===== REGISTRASI =====\n";
    cout << "Masukkan nama pengguna: ";
    cin >> namaPengguna;

    for (int i = 0; i < *jumlahPengguna; i++) {
        if ((pengguna + i)->usr == namaPengguna) {
            penggunaAda = true;
            break;
        }
    }

    if (penggunaAda) {
        cout << "Nama pengguna sudah digunakan.\n";
    } else {
        cout << "Masukkan kata sandi: ";
        cin >> kataSandi;

        (pengguna + *jumlahPengguna)->usr = namaPengguna;
        (pengguna + *jumlahPengguna)->pw = kataSandi;
        (*jumlahPengguna)++;

        cout << "Registrasi berhasil!\n";
    }
}

bool login(regis* pengguna, int jumlahPengguna, int* indeksPenggunaLogin) {
    string namaPengguna, kataSandi;
    bool berhasil = false;
    percobaan = 0;

    while (percobaan < 3 && !berhasil) {
        cout << "Masukkan nama pengguna: ";
        cin >> namaPengguna;
        cout << "Masukkan kata sandi: ";
        cin >> kataSandi;

        for (int i = 0; i < jumlahPengguna; i++) {
            if ((pengguna + i)->usr == namaPengguna && (pengguna + i)->pw == kataSandi) {
                berhasil = true;
                *indeksPenggunaLogin = i;
                cout << "Login berhasil!\n";
                break;
            }
        }

        if (!berhasil) {
            percobaan++;
            cout << "Gagal login. Percobaan ke-" << percobaan << " dari 3.\n";
        }

        if (percobaan == 3 && !berhasil) {
            cout << "Anda telah mencoba login 3 kali.\n";
        }
    }

    return berhasil;
}

void tambahKoleksi(rincian* koleksi, int* jumlahKoleksi) {
    if (*jumlahKoleksi < MAX) {
        cout << "Masukkan nama koleksi: ";
        cin.ignore();
        getline(cin, (koleksi + *jumlahKoleksi)->nama);
        cout << "Masukkan jenis koleksi: ";
        getline(cin, (koleksi + *jumlahKoleksi)->jenis);
        cout << "Masukkan asal koleksi: ";
        getline(cin, (koleksi + *jumlahKoleksi)->asal);
        cout << "Masukkan tahun koleksi: ";
        getline(cin, (koleksi + *jumlahKoleksi)->wktu.tahun);
        (*jumlahKoleksi)++;
    } else {
        cout << "Koleksi penuh.\n";
    }
}

void tampilkanKoleksiRekursif(rincian* koleksi, int index, int jumlah) {
    if (index >= jumlah) {
        cout << setfill('=') << setw(83) << "=" << endl;
        return;
    }

    cout << "| " << setw(2) << right << index + 1 << " | "
        << setw(25) << left << (koleksi + index)->nama << "| "
        << setw(20) << left << (koleksi + index)->asal << "| "
        << setw(20) << left << (koleksi + index)->jenis << "| "
        << setw(6) << (koleksi + index)->wktu.tahun << " |\n";

    tampilkanKoleksiRekursif(koleksi, index + 1, jumlah);
}

void lihatKoleksi(rincian* koleksi, int jumlah) {
    if (jumlah == 0) {
        cout << "Koleksi kosong\n";
    } else {
        cout << setw(70) << "========== Koleksi Barang Antik ==========\n";
        cout << setfill('=') << setw(83) << "=" << endl;
        cout << "| No | " << setw(25) << left << "Nama"
            << "| " << setw(20) << left << "Asal"
            << "| " << setw(20) << left << "Jenis"
            << "| Tahun |\n";
        cout << setfill('=') << setw(83) << "=" << endl;
        cout << setfill(' ');
        tampilkanKoleksiRekursif(koleksi, 0, jumlah);
    }
}

void perbaruiKoleksi(rincian* koleksi, int jumlah) {
    if (jumlah == 0) {
        cout << "Koleksi kosong\n";
        return;
    }

    lihatKoleksi(koleksi, jumlah);
    int indeks;
    cout << "Masukkan indeks koleksi yang ingin diperbarui: ";
    cin >> indeks;
    cin.ignore();

    if (indeks >= 1 && indeks <= jumlah) {
        cout << "Masukkan nama baru: ";
        getline(cin, (koleksi + indeks - 1)->nama);
        cout << "Masukkan jenis baru: ";
        getline(cin, (koleksi + indeks - 1)->jenis);
        cout << "Masukkan asal baru: ";
        getline(cin, (koleksi + indeks - 1)->asal);
        cout << "Masukkan tahun baru: ";
        getline(cin, (koleksi + indeks - 1)->wktu.tahun);
        cout << "Data berhasil diperbarui.\n";
    } else {
        cout << "Indeks tidak valid.\n";
    }
}

void hapusKoleksi(rincian* koleksi, int* jumlah) {
    if (*jumlah == 0) {
        cout << "Koleksi kosong\n";
        return;
    }

    int indeks;
    cout << "Masukkan indeks koleksi yang ingin dihapus: ";
    cin >> indeks;

    if (indeks >= 1 && indeks <= *jumlah) {
        for (int i = indeks - 1; i < *jumlah - 1; i++) {
            *(koleksi + i) = *(koleksi + i + 1);
        }
        (*jumlah)--;
        cout << "Data berhasil dihapus.\n";
    } else {
        cout << "Indeks tidak valid.\n";
    }
}

void menuKoleksi(rincian* koleksi, int* jumlahKoleksi) {
    int pilihan;
    do {
        cout << "\n=== Manajemen Koleksi ===\n";
        cout << "1. Tambah Koleksi\n";
        cout << "2. Lihat Koleksi\n";
        cout << "3. Perbarui Koleksi\n";
        cout << "4. Hapus Koleksi\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahKoleksi(koleksi, jumlahKoleksi); break;
            case 2: lihatKoleksi(koleksi, *jumlahKoleksi); break;
            case 3: perbaruiKoleksi(koleksi, *jumlahKoleksi); break;
            case 4: hapusKoleksi(koleksi, jumlahKoleksi); break;
            case 5: cout << "Keluar dari menu koleksi.\n"; return;
            default: cout << "Pilihan tidak valid.\n";
        }
    } while (true);
}

int main() {
    int pilihan;

    do {
        cout << "\n===== MENU UTAMA =====\n";
        cout << "1. Registrasi\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                registrasi(pengguna, &jumlahPengguna);
                break;
            case 2:
                if (login(pengguna, jumlahPengguna, &indeksPenggunaLogin)) {
                    menuKoleksi(koleksi, &jumlahKoleksi);
                }
                break;
            case 3:
                cout << "Terima kasih!\n";
                return 0;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (true);
}
