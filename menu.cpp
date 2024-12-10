#include <ncurses.h>
#include <string>
#include <iostream>
using namespace std;

int n;  

// Fungsi tukar
void tukar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort (Ascending)
void bubble_sort_asc(int* data, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            if (*(data + j) < *(data + j - 1)) {
                tukar((data + j), (data + j - 1));
            }
        }
    }
}

// Bubble Sort (Descending)
void bubble_sort_desc(int* data, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (*(data + j) < *(data + j + 1)) {
                tukar((data + j), (data + j + 1));
            }
        }
    }
}

// Fungsi membaca angka dengan pointer
int read_number_with_getch(int y, int x) {
    string input;
    int ch;
    mvprintw(y, x, "");
    while ((ch = getch()) != '\n') {
        if (isdigit(ch)) {
            input += ch;
            mvaddch(y, x++, ch);
        } else if ((ch == KEY_BACKSPACE || ch == 127) && !input.empty()) {
            input.pop_back();
            mvaddch(y, --x, ' ');
            move(y, x);
        }
    }
    return input.empty() ? 0 : stoi(input);
}

int main() {
    int *data = new int[100];

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    do {
        clear();
        mvprintw(0, 0, "Aplikasi Tampilan Menu\n1. Menu Pertama\n2. Menu Kedua\n3. Menu Ketiga\n4. Sorting Array\n5. Exit");
        mvprintw(7, 0, "Masukkan angka: "); 
        refresh();
        
        char *pl = new char;
        *pl = getch();
        clear();

        if (*pl == '4') {
            mvprintw(0, 0, "Masukkan jumlah elemen array: ");
            n = read_number_with_getch(0, 30);
            if (n <= 0) { 
                mvprintw(1, 0, "Jumlah elemen harus lebih dari 0! Tekan tombol untuk kembali...");
                getch();
                continue; 
            }

            for (int i = 0; i < n; i++) {
                mvprintw(2 + i, 0, "Masukkan elemen ke-%d: ", i + 1);
                *(data + i) = read_number_with_getch(2 + i, 25);
            }

            mvprintw(2 + n, 0, "Pilih urutan: 1 = Ascending, 2 = Descending");
            char sort_order = getch();
            clear();

            if (sort_order == '1') {
                bubble_sort_asc(data, n);
                mvprintw(0, 0, "Array setelah diurutkan (Ascending):");
            } else if (sort_order == '2') {
                bubble_sort_desc(data, n);
                mvprintw(0, 0, "Array setelah diurutkan (Descending):");
            } else {
                mvprintw(0, 0, "Pilihan tidak valid. Tekan tombol untuk kembali...");
                getch();
                continue;
            }

            for (int i = 0; i < n; i++) {
                mvprintw(2 + i, 0, "%d", *(data + i));
            }
            mvprintw(2 + n, 0, "Tekan tombol apa saja untuk kembali...");
            getch();
        } else if (*pl == '5') break;
        else {
            mvprintw(0, 0, (*pl >= '1' && *pl <= '3') ? "Hallo saya menu ke-%c" : "Pilihan tidak tersedia", *pl);
            mvprintw(2, 0, "Tekan tombol apa saja untuk melanjutkan...");
            getch();
        }

        delete pl;
    } while (true);

    delete[] data;
    endwin();
    return 0;
}

