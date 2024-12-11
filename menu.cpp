#include <ncurses.h>
#include <iostream>
#include <vector>
using namespace std;

// Fungsi tukar
void tukar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Bubble Sort (Ascending)
void bubble_sort_asc(vector<int> &data) {
    int n = data.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                tukar(data[j], data[j + 1]);
            }
        }
    }
}

// Bubble Sort (Descending)
void bubble_sort_desc(vector<int> &data) {
    int n = data.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] < data[j + 1]) {
                tukar(data[j], data[j + 1]);
            }
        }
    }
}

// Fungsi utama
int main() {
    vector<int> data;
    int choice;

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

        choice = getch() - '0';
        clear();

        switch (choice) {
            case 1: {
                int n;
                mvprintw(0, 0, "Masukkan jumlah elemen: ");
                echo();
                scanw("%d", &n);
                noecho();

                data.clear();
                for (int i = 0; i < n; i++) {
                    int val;
                    mvprintw(1 + i, 0, "Masukkan elemen ke-%d: ", i + 1);
                    echo();
                    scanw("%d", &val);
                    noecho();
                    data.push_back(val);
                }
                break;
            }

            case 2: {
                if (data.empty()) {
                    mvprintw(0, 0, "Data kosong. Masukkan data terlebih dahulu.");
                } else {
                    mvprintw(0, 0, "Data saat ini:");
                    for (size_t i = 0; i < data.size(); i++) {
                        mvprintw(1 + i, 0, "%d", data[i]);
                    }
                }
                mvprintw(data.size() + 2, 0, "Tekan tombol untuk kembali...");
                getch();
                break;
            }

            case 3: {
                if (data.empty()) {
                    mvprintw(0, 0, "Data kosong. Masukkan data terlebih dahulu.");
                } else {
                    bubble_sort_asc(data);
                    mvprintw(0, 0, "Data telah diurutkan secara ascending:");
                    for (size_t i = 0; i < data.size(); i++) {
                        mvprintw(1 + i, 0, "%d", data[i]);
                    }
                }
                mvprintw(data.size() + 2, 0, "Tekan tombol untuk kembali...");
                getch();
                break;
            }

            case 4: {
                if (data.empty()) {
                    mvprintw(0, 0, "Data kosong. Masukkan data terlebih dahulu.");
                } else {
                    bubble_sort_desc(data);
                    mvprintw(0, 0, "Data telah diurutkan secara descending:");
                    for (size_t i = 0; i < data.size(); i++) {
                        mvprintw(1 + i, 0, "%d", data[i]);
                    }
                }
                mvprintw(data.size() + 2, 0, "Tekan tombol untuk kembali...");
                getch();
                break;
            }

            case 5:
                mvprintw(0, 0, "Keluar dari aplikasi. Tekan tombol apa saja...");
                getch();
                break;

            default:
                mvprintw(0, 0, "Pilihan tidak valid. Tekan tombol untuk kembali...");
                getch();
                break;
        }

    } while (choice != 5);

    endwin();
    return 0;
}
