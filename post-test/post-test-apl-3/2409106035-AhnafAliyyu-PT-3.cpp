#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

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

#define MAX 25

rincian koleksi[MAX];
regis pengguna[MAX]; // Array untuk menyimpan banyak akun

string namaPengguna, kataSandi;
int percobaan, pilihan, urutan, jumlah = 0, jumlahPengguna = 0; // jumlahPengguna untuk menghitung akun terdaftar
bool masukBerhasil = false;
int indeksPenggunaLogin = -1; // Menyimpan indeks pengguna yang login

int main() {
    do {
        cout << "===== PILIHAN MENU =====\n"
            << "1. REGISTRASI\n"
            << "2. LOGIN\n"
            << "3. KELUAR\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: {
                if (jumlahPengguna < MAX) {
                    bool penggunaAda = false;

                    cout << "===== REGISTRASI =====\n";
                    cout << "Masukkan nama pengguna: ";
                    cin >> namaPengguna;

                    // Cek apakah username sudah digunakan
                    for (int i = 0; i < jumlahPengguna; i++) {
                        if (pengguna[i].usr == namaPengguna) {
                            penggunaAda = true;
                            break;
                        }
                    }

                    if (penggunaAda) {
                        cout << "Nama pengguna sudah digunakan. Silakan coba lagi.\n";
                    } else {
                        cout << "Masukkan kata sandi: ";
                        cin >> kataSandi;

                        pengguna[jumlahPengguna].usr = namaPengguna;
                        pengguna[jumlahPengguna].pw = kataSandi;
                        jumlahPengguna++;

                        cout << "Registrasi berhasil!\n";
                    }
                } else {
                    cout << "Batas registrasi telah penuh.\n";
                }
                break;
            }

            case 2: {
                percobaan = 0;
        

                while (percobaan < 3 && !masukBerhasil) {
                    cout << "Masukkan nama pengguna: ";
                    cin >> namaPengguna;
                    cout << "Masukkan kata sandi: ";
                    cin >> kataSandi;

                    for (int i = 0; i < jumlahPengguna; i++) {
                        if (namaPengguna == pengguna[i].usr && kataSandi == pengguna[i].pw) {
                            masukBerhasil = true;
                            indeksPenggunaLogin = i;
                            cout << "Berhasil login!\n";
                            break;
                        }
                    }

                    if (!masukBerhasil) {
                        percobaan++;
                        cout << "Gagal login. Nama pengguna atau kata sandi salah. Percobaan ke-" << percobaan << " dari 3.\n";
                    }

                    if (percobaan == 3 && !masukBerhasil) {
                        cout << "Anda telah mencoba login 3 kali. Program akan kembali ke menu utama.\n";
                    }
                }

                if (masukBerhasil) {
                    do {
                        cout << "\n=== Manajemen Koleksi Barang Antik ===\n";
                        cout << "1. Tambah Koleksi\n";
                        cout << "2. Lihat Koleksi\n";
                        cout << "3. Perbarui Koleksi\n";
                        cout << "4. Hapus Koleksi\n";
                        cout << "5. Keluar\n";
                        cout << "Masukkan nomor menu: ";
                        cin >> pilihan;
                        cin.ignore();

                        switch (pilihan) {
                            case 1: {
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
                            }
                            case 2: {
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
                            }
                            case 3: {
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
                                        cout << "Indeks tidak valid.\n";
                                    }
                                }
                                break;
                            }
                            case 4: {
                                if (jumlah > 0) {
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
                                        cout << "Indeks tidak valid.\n";
                                    }
                                } else {
                                    cout << "Koleksi masih kosong\n";
                                }
                                break;
                            }
                            case 5: {
                                cout << "Logout berhasil!\n";
                                masukBerhasil = false;
                                break;
                            }
                            default:
                                cout << "Pilihan tidak valid\n";
                        }
                    } while (masukBerhasil);
                }
                break;
            }

            case 3:
                cout << "Terima kasih telah menggunakan program ini.\n";
                return 0;

            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (true);

    return 0;
}
