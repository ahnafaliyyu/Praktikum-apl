#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct waktu
{
    string tahun;
};
struct rincian
{
    string jenis, asal, nama;
    waktu wktu;
};

struct regis{
string usr,pw;};

regis pengguna;

#define MAX 25

rincian koleksi[MAX];
string username, password, ulang;
int percobaan, pilihan, urutan, jumlah = 0;

int main() {
    cout << "===== REGISTRASI =====\n";
    cout << "Masukkan username: ";
    cin >> pengguna.usr;
    cout << "Masukkan password: ";
    cin >> pengguna.pw;
    cout << "Registrasi berhasil!\n\n";

    percobaan = 0;
    while (percobaan < 3) {
        cout << "Masukkan username: ";
        cin >> username;
        cout << "Masukkan password: ";
        cin >> password;
        
        if (username == pengguna.usr && password == pengguna.pw ) {
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
        cout << "Masukkan nomor menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                if (jumlah < MAX) {
                    cout << "Masukkan nama koleksi: ";
                    getline(cin, koleksi[jumlah].nama);
                    cout << "Masukkan jenis koleksi: ";
                    getline(cin, koleksi[jumlah].asal);
                    cout << "Masukkan asal koleksi: ";
                    getline(cin, koleksi[jumlah].jenis);
                    cout << "Masukkan tahun koleksi: ";
                    getline(cin, koleksi[jumlah].wktu.tahun);
                    jumlah++;
                } else {
                    cout << "Koleksi sudah penuh\n";
                }
                break;
            
            case 2:
                if (jumlah == 0) {
                    cout << "Koleksi masih kosong\n";
                } else {
                    cout << setw(70) << "========== Koleksi Barang Antik ==========\n";
                    cout << setfill('=') << setw(83) << "=" << endl;
                    cout << "| No | " << setw(25) << left << "Nama"
                    << "| " << setw(20) << left << "Asal"
                    << "| " << setw(20) << left << "Jenis"
                    << "| Tahun |\n";
                    cout << setfill('=') << setw(83) << "=" << endl;
                    cout << setfill(' ');
                    for (int i = 0; i < jumlah; i++) {
                        cout << "| " << setw(2) << right << i + 1 << " | "
                            << setw(25) << left << koleksi[i].nama << "| "
                            << setw(20) << left << koleksi[i].asal << "| "
                            << setw(20) << left << koleksi[i].jenis << "| "
                            << setw(6) << koleksi[i].wktu.tahun << " |\n";
                    }

                    cout << setfill('=') << setw(83) << "=" << endl;
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
                        getline(cin, koleksi[urutan - 1].nama);
                        cout << "Masukkan jenis baru: ";
                        getline(cin, koleksi[urutan - 1].asal);
                        cout << "Masukkan asal baru: ";
                        getline(cin, koleksi[urutan - 1].jenis);
                        cout << "Masukkan tahun baru: ";
                        getline(cin, koleksi[urutan - 1].wktu.tahun);
                        cout << "Barang berhasil diperbarui\n";
                    } else {
                        cout << "Indeks tidak valid. Harap masukkan indeks antara 1 hingga " << jumlah << "\n";
                    }
                }
                break;
            
            case 4:
                if (jumlah>0){
                    cout << setw(70) << "========== Koleksi Barang Antik ==========\n";
                    cout << setfill('=') << setw(83) << "=" << endl;
                    cout << "| No | " << setw(25) << left << "Nama"
                        << "| " << setw(20) << left << "Asal"
                        << "| " << setw(20) << left << "Jenis"
                        << "| Tahun |\n";
                    cout << setfill('=') << setw(83) << "=" << endl;
                    cout << setfill(' ');
                    for (int i = 0; i < jumlah; i++) {
                        cout << "| " << setw(2) << right << i + 1 << " | "
                            << setw(25) << left << koleksi[i].nama << "| "
                            << setw(20) << left << koleksi[i].asal << "| "
                            << setw(20) << left << koleksi[i].jenis << "| "
                            << setw(6) << koleksi[i].wktu.tahun << " |\n";
                    }
            
                    cout << setfill('=') << setw(83) << "=" << endl;
                
                cout << "Masukkan indeks koleksi yang ingin dihapus (1 - " << jumlah << "): ";
                cin >> urutan;
                cin.ignore();
                if (urutan >= 1 && urutan <= jumlah) {
                    for (int i = urutan - 1; i < jumlah - 1; i++) {
                        koleksi[i] = koleksi[i + 1];
                    }
                    jumlah--;
                    cout << "Barang berhasil dihapus\n";
                } else {
                    cout << "Indeks tidak valid. Harap masukkan indeks antara 1 hingga " << jumlah << "\n";
                }}
                else {
                    cout << "Koleksi masih kosong\n";
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