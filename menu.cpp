#include <ncurses.h>
#include <iostream>
using namespace std;

// Variabel global
int n = 0; // Jumlah elemen data

// Fungsi tukar
void tukar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Fungsi utama
int main() {
    int data[100]; // Array lokal untuk menyimpan data
    int choice;    // Pilihan menu

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    do {
        clear();
        mvprintw(0, 0, "Aplikasi Sorting Bubble");
        mvprintw(1, 0, "1. Masukkan data");
        mvprintw(2, 0, "2. Tampilkan data");
        mvprintw(3, 0, "3. Sorting Ascending");
        mvprintw(4, 0, "4. Sorting Descending");
        mvprintw(5, 0, "5. Exit");
        mvprintw(7, 0, "Masukkan angka: ");
        refresh();

        choice = getch(); // Ambil input menu
        clear();
    } while (choice != '5'); // Ulangi sampai pilihan exit dipilih

    endwin(); // Menutup ncurses

    return 0; 
}
