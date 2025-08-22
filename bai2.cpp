#include "book.h"
#include <cstdlib>
#include <ctime>

int main() {
    Book* tree;
    initTree(tree);

    srand(time(0));
    // Random 5 book
    for (int i = 1; i <= 5; i++) {
        int id = rand() % 100;
        string title = "Book" + to_string(i);
        int year = 2000 + rand() % 25;
        addBook(tree, id, title, year);
    }

    cout << "Danh sach Book (LNR):\n";
    printAll(tree);

    tree = deleteBook(tree, 50); // test xóa

    saveToFile(tree);

    return 0;
}
