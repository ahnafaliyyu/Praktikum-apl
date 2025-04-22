#include<iostream>
using namespace std;

struct Orang
{
    string nama;
    int umur;
    
};



int main(){

        int primenumber[6] = {2, 3, 5, 7, 11, 13};
    
        // Perbaikan: pointer ke elemen pertama array
        int (*ptrprimenumber)[6] = &primenumber;
    
        for (int i = 0; i < 6; i++) {
            cout << (*ptrprimenumber)[i] << endl;
        }
        cout << "Pointer yang menunjuk ";
        cout << "ke arah elemen array"<<endl;
        int b[5] = {1,2,3,4,5,};
        int *bPtr = b;
        for (int i = 0; i < 5; i++){
        cout << bPtr <<endl;
        cout << *bPtr <<endl;
        bPtr++;
        }





// Orang orang;
// orang.nama="Budi";
// orang.umur=20;

// Orang *orang2=&orang;
// cout<<orang2->nama<<endl;




// int stack=64;
// int stacksnowball=16;

// int *isi=&stack;

// cout<<"stack "<<isi<<endl;
// cout<<"stack: "<<*isi<<endl;

// stack=16;
// cout<<"setelah diubah; "<<stack<<endl;
// cout<<"stack: "<<*isi<<endl;

// *isi= 10;
// cout<<"stetelah var isi diubah"<<endl;
// cout<<"stack: "<<*isi<<endl;
// cout<<"stack: "<<stack<<endl;

// // int isi=stack;
// // cout<<"STACK"<<isi<<endl;
// // stack=69;
// // cout<<"stack: "<<stack<<endl;

// // cout << "stack: " << stack << endl;
// // cout<<&stack<<endl;
// // cout<<"snowball: "<<stacksnowball<<endl;
// // cout<<&stacksnowball<<endl;




    return 0;
}