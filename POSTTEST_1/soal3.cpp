// aturan soal genap karena 3 digit nim terakhir adalah 108

#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

int main() {
    Mahasiswa mhs[4];


    for (int i = 0; i < 4; i++) {
        cout << "Mahasiswa ke-" << i+1 << endl;
        cout << "Nama: ";
        getline(cin, mhs[i].nama);
        cout << "Nim: ";
        getline(cin, mhs[i].nim);
        cout << "Ipk: ";
        cin >> mhs[i].ipk;
        cin.ignore(); 
    }

    // sorting berdasarkan Ipk
    for (int i = 0; i < 3; i++) {
        for (int j = i+1; j < 4; j++) {
            if (mhs[i].ipk > mhs[j].ipk) {
                Mahasiswa temp = mhs[i];
                mhs[i] = mhs[j];
                mhs[j] = temp;
            }
        }
    }


    cout << "\nData Mahasiswa setelah diurutkan berdasarkan Ipk:\n";
    for (int i = 0; i < 4; i++) {
        cout << "Nama: " << mhs[i].nama << endl;
        cout << "NIM: " << mhs[i].nim << endl;
        cout << "IPK: " << mhs[i].ipk << endl;
        cout << "--------------------------" << endl;
    }

    return 0;
}