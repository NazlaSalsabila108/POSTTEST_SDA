#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insertEnd(Node *&head_ref, int data) {
    Node *newNode = new Node{data, nullptr, nullptr};

    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node *tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    tail->next = newNode;
    head_ref->prev = newNode;
}

void printList(Node *head_ref) {
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

void exchangeHeadAndTail(Node *&head_ref) {
    // Jika kosong atau hanya 1 node: tidak perlu apa-apa
    if (head_ref == nullptr || head_ref->next == head_ref) return;

    Node* head = head_ref;
    Node* tail = head_ref->prev;
    Node* headNext = head->next;
    Node* tailPrev = tail->prev;

    // Kasus 2 node: cukup pindah head_ref ke tail 
    if (headNext == tail) {
        head_ref = tail;
        return;
    }

    // Kasus umum (>=3 node):
    // Mau susunan baru: tail, headNext, ..., tailPrev, head

    // 1) hubungkan headNext agar prev menunjuk ke tail (sebelumnya prev=head)
    headNext->prev = tail;

    // 2) hubungkan tailPrev agar next menunjuk ke head (sebelumnya next=tail)
    tailPrev->next = head;

    // 3) set next/prev untuk tail dan head sesuai posisi baru
    tail->next = headNext;  // tail jadi head baru, next -> node setelah head lama
    tail->prev = head;      // tail.prev = head (karena head jadi tail lama)

    head->next = tail;      // head jadi tail baru, next -> head baru (tail)
    head->prev = tailPrev;  // head.prev -> node sebelum tail lama

    // 4) update head_ref ke node tail (sekarang menjadi head baru)
    head_ref = tail;
}

int main() {
    Node *head = nullptr;

    // Buat list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head);

    exchangeHeadAndTail(head);

    cout << "List setelah exchange head dan tail: ";
    printList(head); // Expected: 5 2 3 4 1

    return 0;
}
