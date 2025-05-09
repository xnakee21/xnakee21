#include "linkedlist.h"

LinkedList::LinkedList() : head(nullptr), userHead(nullptr), peminjamanHead(nullptr) {}

LinkedList::~LinkedList() {
    // Hapus semua buku
    while (head != nullptr) {
        Buku* temp = head;
        head = head->next;
        delete temp;
    }

    // Hapus semua user
    while (userHead != nullptr) {
        User* temp = userHead;
        userHead = userHead->next;
        delete temp;
    }

    // Hapus semua data peminjaman
    while (peminjamanHead != nullptr) {
        Peminjaman* temp = peminjamanHead;
        peminjamanHead = peminjamanHead->next;
        delete temp;
    }
}

// Manajemen Buku
void LinkedList::tambahBuku(const QString& judul, const QString& pengarang, const QString& kategori) {
    Buku* baru = new Buku{judul, pengarang, kategori, true, head};
    head = baru;
}

void LinkedList::hapusBuku(const QString& judul) {
    Buku* current = head;
    Buku* previous = nullptr;

    while (current != nullptr && current->judul != judul) {
        previous = current;
        current = current->next;
    }

    if (current != nullptr) {
        if (previous == nullptr)
            head = current->next;
        else
            previous->next = current->next;
        delete current;
    }
}

void LinkedList::tampilkanBuku(QTextEdit* output) {
    output->clear();
    Buku* current = head;

    if (current == nullptr) {
        output->append("Tidak ada buku dalam daftar");
        return;
    }

    while (current != nullptr) {
        output->append("Judul: " + current->judul);
        output->append("Pengarang: " + current->pengarang);
        output->append("Kategori: " + current->kategori);
        output->append("Status: " + QString(current->tersedia ? "Tersedia" : "Dipinjam") + "\n");
        current = current->next;
    }
}

bool LinkedList::cariBuku(const QString& judul) {
    Buku* current = head;

    while (current != nullptr) {
        if (current->judul == judul)
            return true;
        current = current->next;
    }

    return false;
}

// Manajemen User
void LinkedList::tambahUser(const QString& username, const QString& password, bool isAdmin) {
    User* baru = new User{username, password, isAdmin, userHead};
    userHead = baru;
}

void LinkedList::hapusUser(const QString& username) {
    User* current = userHead;
    User* previous = nullptr;

    while (current != nullptr && current->username != username) {
        previous = current;
        current = current->next;
    }

    if (current != nullptr) {
        if (previous == nullptr)
            userHead = current->next;
        else
            previous->next = current->next;
        delete current;
    }
}

void LinkedList::tampilkanUser(QTextEdit* output) {
    output->clear();
    User* current = userHead;

    if (current == nullptr) {
        output->append("Tidak ada user dalam daftar");
        return;
    }

    while (current != nullptr) {
        output->append("Username: " + current->username);
        output->append("Role: " + QString(current->isAdmin ? "Administrator" : "User") + "\n");
        current = current->next;
    }
}

bool LinkedList::validasiUser(const QString& username, const QString& password, bool& isAdmin) {
    User* current = userHead;

    while (current != nullptr) {
        if (current->username == username && current->password == password) {
            isAdmin = current->isAdmin;
            return true;
        }
        current = current->next;
    }

    return false;
}

// Manajemen Peminjaman
void LinkedList::pinjamBuku(const QString& username, const QString& judulBuku, const QDate& tanggalPinjam) {
    // Cek apakah buku tersedia
    if (!bukuTersedia(judulBuku))
        return;

    // Perbarui status buku menjadi dipinjam
    updateStatusBuku(judulBuku, false);

    // Tambahkan data peminjaman
    QDate tanggalKembali = tanggalPinjam.addDays(7); // Peminjaman selama 7 hari
    Peminjaman* baru = new Peminjaman{username, judulBuku, tanggalPinjam, tanggalKembali, peminjamanHead};
    peminjamanHead = baru;
}

void LinkedList::tampilkanPeminjaman(QTextEdit* output) {
    output->clear();
    Peminjaman* current = peminjamanHead;

    if (current == nullptr) {
        output->append("Tidak ada data peminjaman");
        return;
    }

    while (current != nullptr) {
        output->append("Username: " + current->username);
        output->append("Judul Buku: " + current->judulBuku);
        output->append("Tanggal Pinjam: " + current->tanggalPinjam.toString("dd/MM/yyyy"));
        output->append("Tanggal Kembali: " + current->tanggalKembali.toString("dd/MM/yyyy") + "\n");
        current = current->next;
    }
}

bool LinkedList::bukuTersedia(const QString& judulBuku) {
    Buku* current = head;

    while (current != nullptr) {
        if (current->judul == judulBuku)
            return current->tersedia;
        current = current->next;
    }

    return false;
}

void LinkedList::updateStatusBuku(const QString& judulBuku, bool tersedia) {
    Buku* current = head;

    while (current != nullptr) {
        if (current->judul == judulBuku) {
            current->tersedia = tersedia;
            return;
        }
        current = current->next;
    }
}
