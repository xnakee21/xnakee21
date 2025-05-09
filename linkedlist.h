#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <QString>
#include <QTextEdit>
#include <QDate>

// Struktur untuk menyimpan data buku
struct Buku {
    QString judul;
    QString pengarang;
    QString kategori;
    bool tersedia;
    Buku* next;
};

// Struktur untuk menyimpan data pengguna
struct User {
    QString username;
    QString password;
    bool isAdmin;
    User* next;
};

// Struktur untuk menyimpan data peminjaman
struct Peminjaman {
    QString username;
    QString judulBuku;
    QDate tanggalPinjam;
    QDate tanggalKembali;
    Peminjaman* next;
};

class LinkedList {
private:
    Buku* head;
    User* userHead;
    Peminjaman* peminjamanHead;

public:
    LinkedList();
    ~LinkedList();

    // Manajemen buku
    void tambahBuku(const QString& judul, const QString& pengarang, const QString& kategori);
    void hapusBuku(const QString& judul);
    void tampilkanBuku(QTextEdit* output);
    bool cariBuku(const QString& judul);
    void cariBukuLengkap(QTextEdit* output, const QString& judul, const QString& pengarang, const QString& kategori);

    // Manajemen user
    void tambahUser(const QString& username, const QString& password, bool isAdmin);
    void hapusUser(const QString& username);
    void tampilkanUser(QTextEdit* output);
    bool validasiUser(const QString& username, const QString& password, bool& isAdmin);

    // Manajemen peminjaman
    void pinjamBuku(const QString& username, const QString& judulBuku, const QDate& tanggalPinjam);
    void tampilkanPeminjaman(QTextEdit* output);
    void tampilkanPeminjamanUser(QTextEdit* output, const QString& username);
    bool bukuTersedia(const QString& judulBuku);
    void updateStatusBuku(const QString& judulBuku, bool tersedia);


};

#endif // LINKEDLIST_H
