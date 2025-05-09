#include "adminwindow.h"
#include "ui_adminwindow.h"
#include <QMessageBox>

AdminWindow::AdminWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    libraryData = LibraryData::getInstance();

    // Tampilkan data awal
    libraryData->getDataList()->tampilkanBuku(ui->outputTextEdit);
    libraryData->getDataList()->tampilkanUser(ui->userOutputTextEdit);
    libraryData->getDataList()->tampilkanPeminjaman(ui->peminjamanTextEdit);
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::on_tambahBukuButton_clicked()
{
    QString judul = ui->judulEdit->text();
    QString pengarang = ui->pengarangEdit->text();
    QString kategori = ui->kategoriEdit->text();

    if (judul.isEmpty() || pengarang.isEmpty() || kategori.isEmpty()) {
        QMessageBox::warning(this, "Error", "Semua kolom harus diisi!");
        return;
    }

    libraryData->getDataList()->tambahBuku(judul, pengarang, kategori);
    libraryData->getDataList()->tampilkanBuku(ui->outputTextEdit);

    // Reset field
    ui->judulEdit->clear();
    ui->pengarangEdit->clear();
    ui->kategoriEdit->clear();

    QMessageBox::information(this, "Sukses", "Buku berhasil ditambahkan!");
}

void AdminWindow::on_hapusBukuButton_clicked()
{
    QString judul = ui->judulEdit->text();

    if (judul.isEmpty()) {
        QMessageBox::warning(this, "Error", "Masukkan judul buku yang ingin dihapus!");
        return;
    }

    if (!libraryData->getDataList()->cariBuku(judul)) {
        QMessageBox::warning(this, "Error", "Buku tidak ditemukan!");
        return;
    }

    libraryData->getDataList()->hapusBuku(judul);
    libraryData->getDataList()->tampilkanBuku(ui->outputTextEdit);

    QMessageBox::information(this, "Sukses", "Buku berhasil dihapus!");
}

void AdminWindow::on_cariBukuButton_clicked()
{
    QString judul = ui->judulEdit->text();
    QString pengarang = ui->pengarangEdit->text();
    QString kategori = ui->kategoriEdit->text();

    // Implementasi pencarian sederhana
    if (judul.isEmpty() && pengarang.isEmpty() && kategori.isEmpty()) {
        QMessageBox::warning(this, "Error", "Masukkan setidaknya satu kriteria pencarian!");
        return;
    }

    // Sebagai contoh sederhana, kita hanya gunakan fitur tampilkan semua dulu
    libraryData->getDataList()->tampilkanBuku(ui->outputTextEdit);

    // Note: Untuk implementasi pencarian lebih lanjut, perlu ditambahkan
    // metode pencarian di LinkedList untuk filter berdasarkan kriteria
}

void AdminWindow::on_resetBukuButton_clicked()
{
    ui->judulEdit->clear();
    ui->pengarangEdit->clear();
    ui->kategoriEdit->clear();
    ui->statusComboBox->setCurrentIndex(0);
    libraryData->getDataList()->tampilkanBuku(ui->outputTextEdit);
}

void AdminWindow::on_tambahUserButton_clicked()
{
    QString username = ui->userNameEdit->text();
    QString password = ui->userPasswordEdit->text();
    QString konfirmasi = ui->konfirmasiPasswordEdit->text();
    bool isAdmin = (ui->roleComboBox->currentIndex() == 0); // 0 = Admin, 1 = User

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Error", "Username dan password harus diisi!");
        return;
    }

    if (password != konfirmasi) {
        QMessageBox::warning(this, "Error", "Password dan konfirmasi tidak cocok!");
        return;
    }

    libraryData->getDataList()->tambahUser(username, password, isAdmin);
    libraryData->getDataList()->tampilkanUser(ui->userOutputTextEdit);

    // Reset field
    ui->userNameEdit->clear();
    ui->userPasswordEdit->clear();
    ui->konfirmasiPasswordEdit->clear();
    ui->roleComboBox->setCurrentIndex(1); // Default ke User

    QMessageBox::information(this, "Sukses", "User berhasil ditambahkan!");
}

void AdminWindow::on_hapusUserButton_clicked()
{
    QString username = ui->userNameEdit->text();

    if (username.isEmpty()) {
        QMessageBox::warning(this, "Error", "Masukkan username yang ingin dihapus!");
        return;
    }

    libraryData->getDataList()->hapusUser(username);
    libraryData->getDataList()->tampilkanUser(ui->userOutputTextEdit);

    QMessageBox::information(this, "Sukses", "User berhasil dihapus!");
}

void AdminWindow::on_resetUserButton_clicked()
{
    ui->userNameEdit->clear();
    ui->userPasswordEdit->clear();
    ui->konfirmasiPasswordEdit->clear();
    ui->roleComboBox->setCurrentIndex(1); // Default ke User
    libraryData->getDataList()->tampilkanUser(ui->userOutputTextEdit);
}

void AdminWindow::on_refreshPeminjamanButton_clicked()
{
    libraryData->getDataList()->tampilkanPeminjaman(ui->peminjamanTextEdit);
}
