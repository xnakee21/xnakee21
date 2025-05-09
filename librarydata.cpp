#include "librarydata.h"

// Inisialisasi static member
LibraryData* LibraryData::instance = nullptr;

LibraryData::LibraryData() {
    // Inisialisasi dengan data default
    dataList.tambahUser("adminmemantau", "123", true);
    dataList.tambahUser("shanum", "123", false);

    // Tambahkan beberapa buku contoh
    dataList.tambahBuku("Shanuman sang penjaga pusaka", "Lermen", "Sejarah");
    dataList.tambahBuku("Khanooman si pencuri", "Ramang", "Dongeng");
    dataList.tambahBuku("Perjalanan para Reza", "Ambatakamm", "Petualangan");
    dataList.tambahBuku("Kisah Diakhir Tahun", "Incex", "Drama");
    dataList.tambahBuku("Mr.Fuad", "Mas azril", "Aksi");
}

LibraryData* LibraryData::getInstance() {
    if (!instance)
        instance = new LibraryData();
    return instance;
}

LinkedList* LibraryData::getDataList() {
    return &dataList;
}
