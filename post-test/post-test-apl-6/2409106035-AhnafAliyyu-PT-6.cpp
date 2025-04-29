#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define MAX 25

struct waktu {
    int tahun; // Diubah dari string menjadi int
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
        cin >> (koleksi + *jumlahKoleksi)->wktu.tahun; // Diubah menjadi input integer
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
        << setw(6) << right << (koleksi + index)->wktu.tahun << " |\n";

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
        cin >> (koleksi + indeks - 1)->wktu.tahun; 
        cin.ignore();
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

// Sorting berdasarkan Nama (Descending) menggunakan Bubble Sort
void sortNamaDescending(rincian* koleksi, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = i + 1; j < jumlah; j++) {
            if ((koleksi + i)->nama < (koleksi + j)->nama) {
                swap(*(koleksi + i), *(koleksi + j));
            }
        }
    }
    cout << "Sorting berdasarkan Nama (Descending) menggunakan Bubble Sort\n";
}

// Sorting berdasarkan Jenis (Descending) menggunakan Selection Sort
void sortJenisDescending(rincian* koleksi, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        int maxx = i;
        for (int j = i + 1; j < jumlah; j++) {
            if ((koleksi + j)->jenis > (koleksi + maxx)->jenis) {
                maxx = j;
            }
        }
        if (maxx != i) {
            swap(*(koleksi + i), *(koleksi + maxx));
        }
    }
    cout << "Sorting berdasarkan Jenis (Descending) menggunakan Selection Sort\n";
}

// QuickSort berdasarkan Tahun (Ascending)
void quickSortTahunAscending(rincian* koleksi, int low, int high) {
    if (low < high) {
        int pivot = koleksi[high].wktu.tahun;
        int i = (low - 1);

        for (int j = low; j < high; j++) {
            if (koleksi[j].wktu.tahun <= pivot) {
                i++;
                swap(koleksi[i], koleksi[j]);
            }
        }
        swap(koleksi[i + 1], koleksi[high]);

        int pi = i + 1;
        quickSortTahunAscending(koleksi, low, pi - 1);
        quickSortTahunAscending(koleksi, pi + 1, high);
    }
}

// Fungsi untuk melihat koleksi berdasarkan Tahun (Ascending)
void lihatKoleksiBerdasarkanTahun(rincian* koleksi, int jumlah) {
    quickSortTahunAscending(koleksi, 0, jumlah - 1);
    lihatKoleksi(koleksi, jumlah);
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
            case 1: 
                tambahKoleksi(koleksi, jumlahKoleksi); 
                break;
            case 2: {
                int subPilihan;
                cout << "\n=== Lihat Koleksi ===\n";
                cout << "1. Tampilkan Koleksi Asli\n";
                cout << "2. Tampilkan Urut Nama (Descending)\n";
                cout << "3. Tampilkan Urut Jenis (Descending)\n";
                cout << "4. Tampilkan Urut Tahun (Ascending)\n";
                cout << "5. Kembali\n";
                cout << "Masukkan pilihan: ";
                cin >> subPilihan;

                switch (subPilihan) {
                    case 1:
                        lihatKoleksi(koleksi, *jumlahKoleksi);
                        break;
                    case 2:
                        // Sorting berdasarkan Nama Descending
                        sortNamaDescending(koleksi, *jumlahKoleksi);
                        lihatKoleksi(koleksi, *jumlahKoleksi);
                        break;
                    case 3:
                        // Sorting berdasarkan Jenis Descending
                        sortJenisDescending(koleksi, *jumlahKoleksi);
                        lihatKoleksi(koleksi, *jumlahKoleksi);
                        break;
                    case 4:
                        // Sorting berdasarkan Tahun Ascending
                        lihatKoleksiBerdasarkanTahun(koleksi, *jumlahKoleksi);
                        break;
                    case 5:
                        // Kembali ke menu koleksi utama
                        break;
                    default:
                        cout << "Pilihan tidak valid.\n";
                }
                break;
            }
            case 3: 
                perbaruiKoleksi(koleksi, *jumlahKoleksi); 
                break;
            case 4: 
                hapusKoleksi(koleksi, jumlahKoleksi); 
                break;
            case 5: 
                cout << "Keluar dari menu koleksi.\n"; 
                return;
            default:
                cout << "Pilihan tidak valid.\n";
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
