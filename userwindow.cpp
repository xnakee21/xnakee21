#include "userwindow.h"
#include "ui_userwindow.h"
#include <QMessageBox>
#include <QDate>

UserWindow::UserWindow(QString username, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::UserWindow), currentUser(username)
{
    ui->setupUi(this);
    libraryData = LibraryData::getInstance();

    // Set default date ke hari ini
    QDate today = QDate::currentDate();
    ui->tanggalPinjamEdit->setDate(today);

    // Tampilkan semua buku
    libraryData->getDataList()->tampilkanBuku(ui->outputTextEdit);

    // Tampilkan data peminjaman user ini
    // Note: Fungsi ini perlu ditambahkan di LinkedList.cpp
    // Untuk sementara pakai tampilkanPeminjaman saja
    libraryData->getDataList()->tampilkanPeminjaman(ui->peminjamanTextEdit);
}

UserWindow::~UserWindow()
{
    delete ui;
}

void UserWindow::on_searchButton_clicked()
{
    QString judul = ui->judulSearchEdit->text();
    QString pengarang = ui->pengarangSearchEdit->text();

    // Implementasi pencarian sederhana
    if (judul.isEmpty() && pengarang.isEmpty()) {
        QMessageBox::warning(this, "Error", "Masukkan setidaknya satu kriteria pencarian!");
        return;
    }

    // Sebagai contoh sederhana, kita hanya gunakan fitur tampilkan semua dulu
    libraryData->getDataList()->tampilkanBuku(ui->outputTextEdit);

    // Note: Implementasi pencarian lebih lanjut perlu ditambahkan
}

void UserWindow::on_resetSearchButton_clicked()
{
    ui->judulSearchEdit->clear();
    ui->pengarangSearchEdit->clear();
    libraryData->getDataList()->tampilkanBuku(ui->outputTextEdit);
}

void UserWindow::on_pinjamBukuButton_clicked()
{
    QString judul = ui->judulPinjamEdit->text();
    QDate tanggal = ui->tanggalPinjamEdit->date();

    if (judul.isEmpty()) {
        QMessageBox::warning(this, "Error", "Masukkan judul buku yang ingin dipinjam!");
        return;
    }

    if (!libraryData->getDataList()->cariBuku(judul)) {
        QMessageBox::warning(this, "Error", "Buku tidak ditemukan!");
        return;
    }

    if (!libraryData->getDataList()->bukuTersedia(judul)) {
        QMessageBox::warning(this, "Error", "Buku sudah dipinjam!");
        return;
    }

    libraryData->getDataList()->pinjamBuku(currentUser, judul, tanggal);
    libraryData->getDataList()->tampilkanPeminjaman(ui->peminjamanTextEdit);

    QMessageBox::information(this, "Sukses", "Buku berhasil dipinjam!");
    ui->judulPinjamEdit->clear();
}

void UserWindow::on_refreshPinjamButton_clicked()
{
    libraryData->getDataList()->tampilkanPeminjaman(ui->peminjamanTextEdit);
}
