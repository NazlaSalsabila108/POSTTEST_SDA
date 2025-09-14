// aturan soal genap karena 3 digit nim terakhir adalah 108

#include <iostream>
using namespace std;

void tukar(int *&a, int *&b) {
    int *temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    int *px = &x, *py = &y;

    cout << "sebelum ditukar:" << endl;
    cout << "x = " << *px << ", y = " << *py << endl;

    tukar(px, py);

    cout << "sesudah ditukar:" << endl;
    cout << "x = " << *px << ", y = " << *py << endl;

    return 0;
}