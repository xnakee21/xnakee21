#ifndef LIBRARYDATA_H
#define LIBRARYDATA_H

#include "linkedlist.h"

class LibraryData {
private:
    static LibraryData* instance;
    LinkedList dataList;

    // Private constructor
    LibraryData();

public:
    static LibraryData* getInstance();
    LinkedList* getDataList();
};

#endif // LIBRARYDATA_H
