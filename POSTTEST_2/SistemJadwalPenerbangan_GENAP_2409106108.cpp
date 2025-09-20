#include <iostream>
#include <string>
using namespace std;

struct JadwalPenerbangan {
    string kodePenerbangan;
    string tujuan;
    string status;
    JadwalPenerbangan* next;
};
    const string RESET = "\033[0m";
    const string BLUE = "\033[34m";
    const string GREEN = "\033[32m";
    const string YELLOW = "\033[33m";
    const string RED = "\033[31m";

JadwalPenerbangan* head = nullptr;
int urutan = 1; //untuk kode penerbangan yang unik 

string generateKodePenerbangan() {
    // personalisasi nim genap : 2409106108
    return "FLIGHT_108_" + to_string(urutan++);
}

void tambahJadwal() {
    JadwalPenerbangan* baru = new JadwalPenerbangan();
    baru->kodePenerbangan = generateKodePenerbangan();
    cout << "Masukkan Tujuan: ";
    getline(cin, baru->tujuan);
    cout << "Masukkan Status: ";
    getline(cin, baru->status);
    baru->next = nullptr;

    if (!head) {
        head = baru;
    } else {
        JadwalPenerbangan* temp = head;
        while (temp->next) temp = temp->next; 
        temp->next = baru;
    }
    cout << GREEN << "Jadwal berhasil ditambahkan! \n" << RESET;
}


void sisipJadwal(){
    int posisi = 9; //karena digit terakhir adalah nim (8) + 1
    cout << "Posisi penyisipan otomatis : " << posisi << endl;
    JadwalPenerbangan* baru = new Jadwal Penerbangan();
    baru->kodePenerbangan = generateKodePenerbangan();
    cout << "Masukkan Tujuan: ";
    getline(cin, baru->tujuan);
    cout << "Masukkan Status: "; 
    getline(cin, baru->status);
    baru->next = nullptr

    if (posisi <= 1 || !head) {
        baru->next = head;
        head = baru;
    } else {
        JadwalPenerbangan* temp = head;
        int idx = 1; 
        while (temp->next && idx < posisi - 1) {
            temp = temp->next;
            idx++;
        }
        baru->next = temp->next;
        temp->next = baru;
    }
    cout << GREEN << "Jadwal berhasil disisipkan!\n" << RESET;
}
 void hapusJadwalAwal() {
    if (!head) {
        cout << RED << "Tidak Ada Jadwal Untuk Dihapus. \n" << RESET;
        return; 
    }
    JadwalPenerbangan* hapus = head;
    head = head->next;
    delete hapus;
    cout << GREEN << "Jadwal Paling Awal Berhasil Dihapus! \n" << RESET;
 }

 void updateStatus() {
    string kode;
    cout << "Masukkan kode penerbangan yang akan diupdate: ";
    getline(cin, kode);
    JadwalPenerbangan* temp = head;
    while (temp) {
        if (temp->kodePenerbangan == kode) {
            cout << "Status lama: " << temp->status << endl;
            cout << "Masukkan status baru: ";
            getline(cin, temp->status);
            cout << GREEN << "Status berhasil diupdate! \n" << RESET;
            return;
        }
        temp = temp->next;

    }
    cout << RED << "Kode penerbangan tidak ditemukan.\n" << RESET;
}

 void tampilkanJadwal() {
    if (!head) {
        cout << BLUE << "Belum ada jadwal penerbangan. \n" << RESET;
        return;
    }
    JadwalPenerbangan* temp = head;
    cout << "Jadwal penerbangan:\n";
    while (temp) {
        cout << YELLOW << "Kode : " << temp->kodePenerbangan
            << YELLOW << " | Tujuan: " << temp->tujuan
            << YELLOW << " | Status: " << temp->status << endl;
        temp = temp->next;
    }
}


int main () {
    int pilihan;
    do {

    cout << BLUE << "\n+----+------------------------------------------+\n";
    cout << "| No | FLIGHT SCHEDULE SYSTEM                   |\n";
    cout << "|    | [NAZLA SALSABILA - 2409106108]           |\n";
    cout << "+----+------------------------------------------+\n" << RESET;
    cout << YELLOW << "| 1  " << GREEN << "| Tambah Jadwal Penerbangan                |\n" << RESET;
    cout << YELLOW << "| 2  " << GREEN << "| Sisipkan Jadwal Penerbangan              |\n" << RESET;
    cout << YELLOW << "| 3  " << GREEN << "| Hapus Jadwal Paling Awal                 |\n" << RESET;
    cout << YELLOW << "| 4  " << GREEN << "| Update Status Penerbangan                |\n" << RESET;
    cout << YELLOW << "| 5  " << GREEN << "| Tampilkan Semua Jadwal Penerbangan       |\n" << RESET;
    cout << YELLOW << "| 0  " << GREEN << "| Keluar                                   |\n" << RESET;
    cout << BLUE << "+----+------------------------------------------+\n" << RESET;
        cout << "Pilih Menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: tambahJadwal(); break;
            case 2: sisipJadwal(); break;
            case 3: hapusJadwalAwal(); break;
            case 4: updateStatus(); break;
            case 5: tampilkanJadwal(); break;
            case 0: cout << BLUE << "Anda keluar dari program.\n" << RESET; break;
            default: cout << RED << "Pilihan tidak valid. Silakan coba lagi.\n" << RESET;
        }

    } while (pilihan !=0);

    // bersih memori 
    while (head) {
        JadwalPenerbangan* hapus = head;
        head = head->next;
        delete hapus;
    }
    return 0;
}

 

