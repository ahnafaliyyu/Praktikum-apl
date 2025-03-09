#include <iostream>
using namespace std;

float fahrenheit;
float celcius; 
float reamur;
float kelvin;
int suhu;
int percobaan;

string username; 
string password;
string ulang;

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
        }else{
        percobaan++;
        cout << "Gagal login. Username atau password salah. Percobaan ke-" << percobaan << " dari 3.\n";}

        if (percobaan == 3) {
            cout << "Anda telah mencoba login 3 kali. Program akan keluar.\n";
            return 0;
        }
    }

    do {
        while (true) {  
            cout << "Pilih satuan suhu yang ingin dikonversi:\n"
                << "1. Celcius\n"
                << "2. Reamur\n"
                << "3. Fahrenheit\n"
                << "4. Kelvin\n"
                << "Masukkan pilihan: ";
            cin >> suhu;

            if (suhu >= 1 && suhu <= 4) { 
                break;  
            }
            cout << "Pilihan tidak tersedia. Silakan coba lagi!\n";
        }

        if (suhu == 1) {
            cout << "Masukkan suhu dalam Celcius: ";
            cin >> celcius;
            reamur = (4.0 / 5) * celcius;
            fahrenheit = (9.0 / 5) * celcius + 32;
            kelvin = celcius + 273.15;
            cout << "Hasil konversi:\n"
                << "Hasil konverisi suhu ke Reamur adalah : " << reamur << "°R\n"
                << "Hasil konverisi suhu ke Fahrenheit adalah : " << fahrenheit << "°F\n"
                << "Hasil konverisi suhu ke Kelvin adalah : " << kelvin << "K\n";
        } else if (suhu == 2) {
            cout << "Masukkan suhu dalam Reamur: ";
            cin >> reamur;
            celcius = (5.0 / 4) * reamur;
            fahrenheit = (9.0 / 4) * reamur + 32;
            kelvin = (5.0 / 4) * reamur + 273.15;
            cout << "Hasil konversi:\n"
                << "Hasil konverisi suhu ke Celcius adalah : " << celcius << "°C\n"
                << "Hasil konverisi suhu ke Fahrenheit adalah : " << fahrenheit << "°F\n"
                << "Hasil konverisi suhu ke Kelvin adalah : " << kelvin << "K\n";
        } else if (suhu == 3) {
            cout << "Masukkan suhu dalam Fahrenheit: ";
            cin >> fahrenheit;
            celcius = (5.0 / 9) * (fahrenheit - 32);
            reamur = (4.0 / 9) * (fahrenheit - 32);
            kelvin = (5.0 / 9) * (fahrenheit - 32) + 273.15;
            cout << "Hasil konversi:\n"
                << "Hasil konverisi suhu ke Celcius adalah : " << celcius << "°C\n"
                << "Hasil konverisi suhu ke Reamur adalah : " << reamur << "°R\n"
                << "Hasil konverisi suhu ke Kelvin adalah : " << kelvin << "K\n";
        } else if (suhu == 4) {
            cout << "Masukkan suhu dalam Kelvin: ";
            cin >> kelvin;
            celcius = kelvin - 273.15;
            reamur = (4.0 / 5) * (kelvin - 273.15);
            fahrenheit = (9.0 / 5) * (kelvin - 273.15) + 32;
            cout << "Hasil konversi:\n"
                << "Hasil konverisi suhu ke Celcius adalah : " << celcius << "°C\n"
                << "Hasil konverisi suhu ke Reamur adalah : " << reamur << "°R\n"
                << "Hasil konverisi suhu ke Fahrenheit adalah : " << fahrenheit << "°F\n";
        }

        cout << "Apakah ingin konversi lagi? (ya/tidak): ";
        cin >> ulang;

    } while (ulang == "ya" || ulang == "Ya" || ulang == "YA");

            cout << "Terima kasih telah menggunakan program ini!\n";
            return 0; 
}