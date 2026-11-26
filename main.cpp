#include <ncurses/ncurses.h>
char papan[3][3];

void resetPapan() {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            papan[r][c] = ' ';
        }
    }
}

void gambarPapan() {
    erase();

    mvprintw(1, 4, "=== XOX ARENA ===");

    int startY = 3;
    int startX = 6;

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            int y = startY + r * 2;
            int x = startX + c * 7;

            if (papan[r][c] == ' ') {
                mvprintw(y, x, "[ . ]");
            } else {
                mvprintw(y, x, "[ %c ]", papan[r][c]);
            }
        }
    }

    mvprintw(10, 4, "Tekan Q untuk keluar.");
    refresh();
}

int main() {
    if (initscr() == NULL) {
        return 1;
    }

    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);

    resetPapan();

    papan[0][0] = 'X';
    papan[1][1] = 'O';

    bool selesai = false;

    while (!selesai) {
        gambarPapan();
        int ch = getch();

        if (ch == 'q' || ch == 'Q') {
            selesai = true;
        }
    }

    endwin();
    return 0;
}
