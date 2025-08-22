#include "reader.h"
#include <cstdlib>
#include <ctime>

int main() {
    Reader* ds;
    initList(ds);

    srand(time(0));
    // Random 5 reader
    for (int i = 1; i <= 5; i++) {
        int id = rand() % 100;
        string name = "User" + to_string(i);
        int soSach = rand() % 10;
        addReader(ds, id, name, soSach);
    }

    cout << "Danh sach Reader:\n";
    printAll(ds);

    cout << "\nSap xep tang dan:\n";
    sortReaders(ds);
    printAll(ds);

    saveToFile(ds);

    return 0;
}
