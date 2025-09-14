// aturan soal genap karena 3 digit nim terakhir adalah 108

#include <iostream>
using namespace std;

int* balikArray(int *arr, int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = *(arr + i);
        *(arr + i) = *(arr + n - 1 - i);
        *(arr + n - 1 - i) = temp;
    }
    return arr;
}

int main () {
    int prima[7] = {19, 23, 29, 31, 37, 41, 43};
    int *ptr = prima;

    cout << "array sebelum dibalik:" << endl;
    for (int i = 0; i < 7; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    ptr = balikArray(ptr, 7);

    cout << "array sesudah dibalik:" << endl;
    for (int i = 0; i < 7; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;
    
    return 0;
}