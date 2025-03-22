#include <iostream>
using namespace std;



struct tanggal{

    int hari;
    int bulan;
    int tahun;
};
// cara membuat struct
struct mahasiswa{

    string nama;
    int nim;
    string gnder;
    tanggal tanggallahir;

};


// typedef struct
// {
//     /* data */
// }mahasiswa;






int main() {
    
    mahasiswa mhsbaru,mhslama;
    mhsbaru.nama = "Ahnaf";
    mhsbaru.nim = 035;
    mhsbaru.gnder = "Laki-laki";
    mhsbaru.tanggallahir.hari = 8;
    mhsbaru.tanggallahir.bulan = 8;
    mhsbaru.tanggallahir.tahun = 2006;

    cout << mhsbaru.nama << endl;
    cout << mhsbaru.nim << endl;
    cout << mhsbaru.gnder << endl;

    cout<< "tanggal:" <<mhsbaru.tanggallahir.hari<<endl;
    cout<<mhsbaru.tanggallahir.bulan<<endl;
    cout<<mhsbaru.tanggallahir.tahun<<endl;

    cout << mhsbaru.tanggallahir.hari << endl;
    cout << mhsbaru.tanggallahir.bulan << endl;
    cout << mhsbaru.tanggallahir.tahun << endl;


mahasiswa mhsabadi[5];
mhsabadi[0].nama = "Ahnaf";
mhsabadi[1].nama = "sudir";
mhsabadi[2].nama = "ali";
mhsabadi[3].nama = "fali";
mhsabadi[4].nama = "falul";

for (int i=0;i<size(mhsabadi);i++){
    cout<<mhsabadi[i].nama<<endl;
}


    return 0;
}
