#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define MAX 25
#define INFO 4
string koleksi[MAX][INFO];
string username, password, ulang;
int percobaan, pilihan, urutan, jumlah = 0;

int main() {
    percobaan = 0;
    while (percobaan < 3) {
        cout << "Masukkan username: ";
        cin >> username;
        cout << "Masukkan password: ";
        cin >> password;
        
        if (username == "Ahnaf" && password == "035") {
            cout << "Berhasil login!\n";
            break;
        } else {
            percobaan++;
            cout << "Gagal login. Username atau password salah. Percobaan ke-" << percobaan << " dari 3.\n";
        }

        if (percobaan == 3) {
            cout << "Anda telah mencoba login 3 kali. Program akan keluar.\n";
            return 0;
        }
    }

    do {
        cout << "\n=== Manajemen Koleksi Barang Antik ===\n";
        cout << "1. Tambah Koleksi\n";
        cout << "2. Lihat Koleksi\n";
        cout << "3. Perbarui Koleksi\n";
        cout << "4. Hapus Koleksi\n";
        cout<<"5. Keluar\n";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                if (jumlah < MAX) {
                    cout << "Masukkan nama koleksi: ";
                    getline(cin, koleksi[jumlah][0]);
                    cout << "Masukkan jenis koleksi: ";
                    getline(cin, koleksi[jumlah][1]);
                    cout << "Masukkan asal koleksi: ";
                    getline(cin, koleksi[jumlah][2]);
                    cout << "Masukkan tahun koleksi: ";
                    getline(cin, koleksi[jumlah][3]);
                    jumlah++;
                } else {
                    cout << "Koleksi sudah penuh\n";
                }
                break;
            
            case 2:
                if (jumlah == 0) {
                    cout << "Koleksi masih kosong\n";
                } else {
                    for (int i = 0; i < jumlah; i++) {
                        cout << "| " << setw(2) << i + 1 << " | "
                        << setw(25) << left << koleksi[i][0] << " | "
                        << setw(20) << left << koleksi[i][1] << " | "
                        << setw(20) << left << koleksi[i][2] << " | "
                        << setw(20) << left << koleksi[i][3] << " |\n";
                    }
                }
                break;
            
            case 3:
                if (jumlah == 0) {
                    cout << "Koleksi masih kosong\n";
                } else {
                    cout << "Masukkan indeks koleksi yang ingin diperbarui (1 - " << jumlah << "): ";
                    cin >> urutan;
                    cin.ignore();
                    if (urutan >= 1 && urutan <= jumlah) {
                        cout << "Masukkan nama baru: ";
                        getline(cin, koleksi[urutan - 1][0]);
                        cout << "Masukkan jenis baru: ";
                        getline(cin, koleksi[urutan - 1][1]);
                        cout << "Masukkan asal baru: ";
                        getline(cin, koleksi[urutan - 1][2]);
                        cout << "Masukkan tahun baru: ";
                        getline(cin, koleksi[urutan - 1][3]);
                    } else {
                        cout << "Indeks tidak valid. Harap masukkan indeks antara 1 hingga " << jumlah << "\n";
                    }
                }
                break;
            
            case 4:
                if (jumlah == 0) {
                    cout << "Koleksi masih kosong\n";
                } else {
                    cout << "Masukkan indeks koleksi yang ingin dihapus (1 - " << jumlah << "): ";
                    cin >> urutan;
                    if (urutan >= 1 && urutan <= jumlah) {
                        for (int i = urutan - 1; i < jumlah - 1; i++) {
                            for (int j = 0; j < INFO; j++) {
                                koleksi[i][j] = koleksi[i + 1][j];
                            }
                        }
                        jumlah--;
                        cout << "Barang berhasil dihapus\n";
                    } else {
                        cout << "Indeks tidak valid. Harap masukkan indeks antara 1 hingga " << jumlah << "\n";
                    }
                }
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program ini\n";
                break;
            default:
                cout << "Pilihan tidak valid\n";
        }
    } while (pilihan != 5);

    return 0;
}