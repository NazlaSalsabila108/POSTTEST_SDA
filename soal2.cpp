// aturan soal genap karena 3 digit nim terakhir adalah 108

#include <iostream>
using namespace std;

int main() {
    int matriks[3][3] = {
        {2, 3, 10},
        {9, 4, 12},
        {7, 6, 13}
    };

    cout << "Matriks 3x3:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    int jumlah = 0;
    for (int i = 0; i < 3; i++) {
        if (i % 2 == 0) { // baris genap: 0 dan 2
            for (int j = 0; j < 3; j++) {
                jumlah += matriks[i][j];
            }
        }
    }

    cout << "Jumlah elemen pada baris genap: " << jumlah << endl;

    return 0;
}