#include <ncurses.h>
#include <iostream>
using namespace std;

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    int choice;

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
    } while (choice != 5);

    endwin();
    return 0;
}
