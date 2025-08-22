#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Reader {
    int ReaderID;
    string Name;
    int SoSachMuon;
    Reader* next;
};

void initList(Reader*& head) {
    head = nullptr;
}

void addReader(Reader*& head, int id, string name, int soSach) {
    Reader* p = new Reader{id, name, soSach, nullptr};
    if (!head) head = p;
    else {
        Reader* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = p;
    }
}

void printReader(Reader* head, int id) {
    while (head) {
        if (head->ReaderID == id) {
            cout << "ReaderID: " << head->ReaderID
                 << " | Name: " << head->Name
                 << " | So sach muon: " << head->SoSachMuon << endl;
            return;
        }
        head = head->next;
    }
    cout << "Khong tim thay Reader!\n";
}

void deleteReader(Reader*& head, int id) {
    if (!head) return;
    if (head->ReaderID == id) {
        Reader* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Reader* prev = head;
    Reader* curr = head->next;
    while (curr) {
        if (curr->ReaderID == id) {
            prev->next = curr->next;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void sortReaders(Reader*& head) {
    if (!head) return;
    for (Reader* i = head; i && i->next; i = i->next) {
        for (Reader* j = i->next; j; j = j->next) {
            if (i->ReaderID > j->ReaderID) {
                swap(i->ReaderID, j->ReaderID);
                swap(i->Name, j->Name);
                swap(i->SoSachMuon, j->SoSachMuon);
            }
        }
    }
}

void printAll(Reader* head) {
    while (head) {
        cout << head->ReaderID << " | " << head->Name 
             << " | " << head->SoSachMuon << endl;
        head = head->next;
    }
}

void saveToFile(Reader* head, string filename="user.txt") {
    ofstream fout(filename);
    while (head) {
        fout << head->ReaderID << "," << head->Name << "," << head->SoSachMuon << "\n";
        head = head->next;
    }
    fout.close();
}
