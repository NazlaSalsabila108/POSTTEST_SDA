// mengubah program sebelumnya dari single linked list menjadi double linked list

#include <iostream>
#include <string>
using namespace std;

struct JadwalPenerbangan {
    string kodePenerbangan;
    string tujuan;
    string status;
    JadwalPenerbangan* prev;
    JadwalPenerbangan* next;
};
const string RESET = "\033[0m";
const string BLUE = "\033[34m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string RED = "\033[31m";

JadwalPenerbangan* head = nullptr;
JadwalPenerbangan* tail = nullptr;
int urutan = 1; 

string generateKodePenerbangan() {
    // nim genap : 2409106108
    return "NS_108_" + to_string(urutan++);
}

void tambahJadwal() {
    JadwalPenerbangan* baru = new JadwalPenerbangan();
    baru->kodePenerbangan = generateKodePenerbangan();
    cout << "Masukkan Tujuan: ";
    getline(cin, baru->tujuan);
    cout << "Masukkan Status: ";
    getline(cin, baru->status);
    baru->next = nullptr;
    baru->prev = nullptr;

    if (!head) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
    cout << GREEN << "Jadwal berhasil ditambahkan! \n" << RESET;
}

void sisipJadwal(){
    int posisi = 9; // karena digit terakhir nim adalah (8) + 1 = 9
    cout << "Posisi penyisipan otomatis : " << posisi << endl;
    JadwalPenerbangan* baru = new JadwalPenerbangan();
    baru->kodePenerbangan = generateKodePenerbangan();
    cout << "Masukkan Tujuan: ";
    getline(cin, baru->tujuan);
    cout << "Masukkan Status: "; 
    getline(cin, baru->status);
    baru->next = nullptr;
    baru->prev = nullptr;

    if (!head || posisi <= 1) {
        // sisip di awal
        baru->next = head;
        if (head) head->prev = baru;
        head = baru;
        if (!tail) tail = baru;
    } else {
        JadwalPenerbangan* temp = head;
        int idx = 1; 
        while (temp->next && idx < posisi - 1) {
            temp = temp->next;
            idx++;
        }
        baru->next = temp->next;
        baru->prev = temp;
        if (temp->next) {
            temp->next->prev = baru;
        } else {
            tail = baru;
        }
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
    if (head) head->prev = nullptr;
    else tail = nullptr;
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

void tampilDariBelakang() {
    if (!tail) {
        cout << BLUE << "Belum ada jadwal penerbangan. \n" << RESET;
        return;
    }
    JadwalPenerbangan* temp = tail;
    cout << "Jadwal penerbangan (dari belakang):\n";
    while (temp) {
        cout << YELLOW << "Kode : " << temp->kodePenerbangan
            << YELLOW << " | Tujuan: " << temp->tujuan
            << YELLOW << " | Status: " << temp->status << endl;
        temp = temp->prev;
    }
}

void tampilkanDetail() {
    cout << "Silahkan cari berdasarkan [1] Kode Penerbangan, [2] Tujuan: ";
    int pilihan;
    cin >> pilihan;
    cin.ignore();
    if (pilihan == 1) {
        string kode;
        cout << "Masukkan kode penerbangan: ";
        getline(cin, kode);
        JadwalPenerbangan* temp = head;
        while (temp) {
            if (temp->kodePenerbangan == kode) {
                cout << GREEN << "Detail Jadwal:\n";
                cout << "Kode: " << temp->kodePenerbangan << endl;
                cout << "Tujuan: " << temp->tujuan << endl;
                cout << "Status: " << temp->status << RESET << endl;
                return;
            }
            temp = temp->next;
        }
        cout << RED << "Kode penerbangan tidak ditemukan.\n" << RESET;
    } else if (pilihan == 2) {
        string tujuan;
        cout << "Masukkan tujuan: ";
        getline(cin, tujuan);
        JadwalPenerbangan* temp = head;
        bool found = false;
        while (temp) {
            if (temp->tujuan == tujuan) {
                cout << GREEN << "Detail Jadwal:\n";
                cout << "Kode: " << temp->kodePenerbangan << endl;
                cout << "Tujuan: " << temp->tujuan << endl;
                cout << "Status: " << temp->status << RESET << endl;
                found = true;
            }
            temp = temp->next;
        }
        if (!found) cout << RED << "Jadwal dengan tujuan tersebut tidak ditemukan.\n" << RESET;
    } else {
        cout << RED << "Pilihan tidak valid.\n" << RESET;
    }
}

void hapusJadwalAkhir(){
    if(!tail) {
        cout << RED << "Tidak ada jadwal untuk dihapus.\n" << RESET;
        return;
    }
    JadwalPenerbangan* hapus = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;
    delete hapus;
    cout << GREEN << "Jadwal paling akhir berhasil dihapus!\n" << RESET;

}

void hapusJadwalPosisi() {
    int posisi;
    cout << "Masukkan posisi yang ingin dihapus:";
    cin >> posisi;
    cin.ignore();

    if (!head) {
        cout << RED << "Tidak ada jadwal untuk dihapus.\n" << RESET;
        return;
    }

    JadwalPenerbangan* temp = head;
    int idx = 1;
    while (temp && idx < posisi) {
        temp = temp->next;
        idx++;
    }

    if(!temp) {
        cout << RED << "Posisi tidak dapat ditemukan.\n" << RESET;
        return;
    }

    if (temp == head) {
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
    }

    else if (temp==tail) {
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
    }

    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    delete temp;
    cout << GREEN << "Jadwal pada posisi"  << posisi <<  "berhasil dihapus!\n" << RESET;
}

int main () {
    int pilihan;
    do {
        cout << YELLOW << "\n+----+------------------------------------------+\n";
        cout << "| No |         FLIGHT SCHEDULE SYSTEM           |\n";
        cout << "|    |     [NAZLA SALSABILA - 2409106108]       |\n";
        cout << "+----+------------------------------------------+\n" << RESET;
        cout << GREEN  << "| 1  " << GREEN << "| Tambah Jadwal Penerbangan                |\n" << RESET;
        cout << GREEN  << "| 2  " << GREEN << "| Sisipkan Jadwal Penerbangan              |\n" << RESET;
        cout << GREEN  << "| 3  " << GREEN << "| Hapus Jadwal Paling Awal                 |\n" << RESET;
        cout << GREEN  << "| 4  " << GREEN << "| Update Status Penerbangan                |\n" << RESET;
        cout << GREEN  << "| 5  " << GREEN << "| Tampilkan Semua Jadwal Penerbangan       |\n" << RESET;
        cout << GREEN  << "| 6  " << GREEN << "| Tampilkan Jadwal (Dari Belakang)         |\n" << RESET;
        cout << GREEN  << "| 7  " << GREEN << "| Tampilkan Detail Jadwal                  |\n" << RESET;
        cout << GREEN  << "| 8  " << GREEN << "| Hapus Jadwal Paling Akhir                |\n" << RESET;
        cout << GREEN  << "| 9  " << GREEN << "| Hapus Jadwal Pada Posisi Tertentu        |\n" << RESET;
        cout << GREEN  << "| 0  " << GREEN << "| Keluar                                   |\n" << RESET;
        cout << YELLOW << "+----+------------------------------------------+\n" << RESET;

        while (true) {
            cout << "Pilih Menu: ";
            if (cin >> pilihan && pilihan >= 0 && pilihan <= 9) {
                cin.ignore(); 
                break;
            } else {
                cout << RED << "Input tidak valid. Silakan masukkan angka antara 0-9.\n" << RESET;
                cin.clear();
                cin.ignore(100,'\n');
            }
        }
    
        switch (pilihan) {
            case 1: tambahJadwal(); break;
            case 2: sisipJadwal(); break;
            case 3: hapusJadwalAwal(); break;
            case 4: updateStatus(); break;
            case 5: tampilkanJadwal(); break;
            case 6: tampilDariBelakang(); break;
            case 7: tampilkanDetail(); break;
            case 8: hapusJadwalAkhir(); break;
            case 9: hapusJadwalPosisi(); break;
            case 0: cout << BLUE << "Anda keluar dari program. Terimakasih ^^ \n" << RESET; break;
            default: cout << RED << "Pilihan tidak valid. Silakan coba lagi.\n" << RESET;
        }

    } while (pilihan !=0);

    while (head) {
        JadwalPenerbangan* hapus = head;
        head = head->next;
        delete hapus;
    }
return 0;
}