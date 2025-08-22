#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Book {
    int BookID;
    string Title;
    int NamXB;
    Book* left;
    Book* right;
};

void initTree(Book*& root) { root = nullptr; }

void addBook(Book*& root, int id, string title, int year) {
    if (!root) {
        root = new Book{id, title, year, nullptr, nullptr};
        return;
    }
    if (id < root->BookID) addBook(root->left, id, title, year);
    else if (id > root->BookID) addBook(root->right, id, title, year);
}

void printBook(Book* root, int id) {
    if (!root) { cout << "Khong tim thay!\n"; return; }
    if (id == root->BookID) {
        cout << "BookID: " << root->BookID
             << " | Title: " << root->Title
             << " | NamXB: " << root->NamXB << endl;
    } else if (id < root->BookID) printBook(root->left, id);
    else printBook(root->right, id);
}

Book* minValueNode(Book* node) {
    Book* current = node;
    while (current && current->left) current = current->left;
    return current;
}

Book* deleteBook(Book* root, int id) {
    if (!root) return root;
    if (id < root->BookID) root->left = deleteBook(root->left, id);
    else if (id > root->BookID) root->right = deleteBook(root->right, id);
    else {
        if (!root->left) {
            Book* temp = root->right;
            delete root; return temp;
        } else if (!root->right) {
            Book* temp = root->left;
            delete root; return temp;
        }
        Book* temp = minValueNode(root->right);
        root->BookID = temp->BookID;
        root->Title = temp->Title;
        root->NamXB = temp->NamXB;
        root->right = deleteBook(root->right, temp->BookID);
    }
    return root;
}

void LNR(Book* root, Book* arr[], int& n) {
    if (!root) return;
    LNR(root->left, arr, n);
    arr[n++] = root;
    LNR(root->right, arr, n);
}

void sortBooks(Book* arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i]->BookID > arr[j]->BookID)
                swap(arr[i], arr[j]);
        }
    }
}

void printAll(Book* root) {
    if (!root) return;
    printAll(root->left);
    cout << root->BookID << " | " << root->Title << " | " << root->NamXB << endl;
    printAll(root->right);
}

void saveToFile(Book* root, string filename="sach.txt") {
    Book* arr[100]; int n = 0;
    LNR(root, arr, n);
    sortBooks(arr, n);
    ofstream fout(filename);
    for (int i = 0; i < n; i++)
        fout << arr[i]->BookID << "," << arr[i]->Title << "," << arr[i]->NamXB << "\n";
    fout.close();
}
