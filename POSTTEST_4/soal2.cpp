#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) return '\0';
    Node* temp = top;
    char popped = temp->data;
    top = top->next;
    delete temp;
    return popped;
}

bool isMatchingPair(char open, char close) {
    return  (open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']');
}

bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    // 1. Loop setiap karakter dalam string
    for (char c : expr) {
        // 2. Jika karakter adalah kurung buka, push ke stack
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);
        }
        // 3. Jika karakter adalah kurung tutup, cek kecocokannya
        else if (c == ')' || c == '}' || c == ']') {
            if (stackTop == nullptr) return false; // Tidak ada pasangan buka
            char open = pop(stackTop);
            if (!isMatchingPair(open, c)) return false; // Tidak cocok
        }
    }

    // 4. Setelah loop selesai, stack harus kosong agar seimbang
    bool balanced = (stackTop == nullptr);

    // Bersihkan sisa node (jika ada)
    while (stackTop != nullptr) pop(stackTop);

    return balanced;
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " 
         << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr2 = "{[(])}";
    cout << expr2 << " -> " 
         << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr3 = "([{}])";
    cout << expr3 << " -> " 
         << (areBracketsBalanced(expr3) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}
