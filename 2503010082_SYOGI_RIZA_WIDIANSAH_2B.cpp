#include <iostream>
using namespace std;

const int MAX = 5;

string queueAnggota[MAX];
int front = 0;
int rear = -1;
int jumlah = 0;

bool isEmpty() {
    return jumlah == 0;
}

bool isFull() {
    return jumlah == MAX;
}

void enqueue(string nama) {
    if (isFull()) {
        cout << "Queue penuh! Tidak bisa menambah anggota.\n";
    } else {
        rear++;
        queueAnggota[rear] = nama;
        jumlah++;

        cout << nama << " masuk ke antrian.\n";
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue kosong! Tidak ada data yang dihapus.\n";
    } else {
        cout << queueAnggota[front]
             << " keluar dari antrian.\n";

        for (int i = front; i < rear; i++) {
            queueAnggota[i] = queueAnggota[i + 1];
        }

        rear--;
        jumlah--;
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Queue kosong!\n";
    } else {
        cout << "Antrian terdepan : "
             << queueAnggota[front] << endl;
    }
}

void tampilkanQueue() {
    if (isEmpty()) {
        cout << "Queue kosong!\n";
    } else {
        cout << "Isi Queue : ";

        for (int i = front; i <= rear; i++) {
            cout << queueAnggota[i];

            if (i < rear) {
                cout << " -> ";
            }
        }

        cout << endl;
    }
}

int main() {

    enqueue("Reza");
    tampilkanQueue();

    enqueue("Mia");
    tampilkanQueue();

    enqueue("Hendra");
    tampilkanQueue();

    peek();

    dequeue();
    tampilkanQueue();

    enqueue("Putri");
    tampilkanQueue();

    return 0;
}
