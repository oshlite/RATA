#include <ncurses/ncurses.h>
#include <stdlib.h>
#include "C_RATA.h"

struct Objek {
    int posisiX;
    int posisiY;
    unsigned char karakter;
    chtype karakterAsli;
};

#define N 10
struct Objek obj[N] = {};

int wbox = 0;
int lev = 0;

void levDaftar(int *tinggi, int *lebar, int *array, int y, int x, int n) {
    if (n == 0) {
        *tinggi = 7;
        *lebar = 6;
        int peta0[7][6] = {
            {1, 1, 1, 1, 1, 1},
            {1, 0, 2, 1, 1, 1},
            {1, 0, 0, 1, 1, 1},
            {1, 2, 5, 0, 0, 1},
            {1, 4, 0, 4, 0, 1},
            {1, 0, 0, 1, 1, 1},
            {1, 1, 1, 1, 1, 1}
        };
        *array = peta0[y][x];
    } else if (n == 1) {
        *tinggi = 9;
        *lebar = 10;
        int peta1[9][10] = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
            {1, 0, 1, 0, 1, 0, 2, 1, 1, 1},
            {1, 0, 0, 0, 0, 4, 0, 1, 1, 1},
            {1, 1, 1, 0, 1, 4, 2, 0, 0, 1},
            {1, 0, 0, 0, 1, 5, 0, 0, 0, 1},
            {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
        };
        *array = peta1[y][x];
    } else if (n == 2) {
        *tinggi = 9;
        *lebar = 11;
        int peta2[9][11] = {
            {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
            {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
            {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
            {0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
            {1, 1, 0, 0, 0, 0, 0, 1, 2, 0, 1},
            {1, 0, 4, 0, 4, 0, 5, 0, 0, 1, 1},
            {1, 0, 1, 1, 1, 1, 1, 1, 2, 1, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
        };
        *array = peta2[y][x];
    }
}

void palet() {
    init_color(COLOR_BLACK, 0, 0, 0);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);
}

void Level(int n) {
    clear();
    mvprintw(1, 1, "For Your Information, game ini ada 3 level jika anda sudah selesai level 3,");
    mvprintw(2, 1, "Silakan klik || Keluar-Q || Lanjut-L || Refresh-R || Selamat Bermainnnn <3");
    int x = 0, y = 0, tinggi = 1, lebar = 1, peta;
    wbox = 0;

    for (y = 0; y < tinggi; y++) {
        for (x = 0; x < lebar; x++) {
            levDaftar(&tinggi, &lebar, &peta, y, x, n);
            switch (peta) {
                case 0: mvaddch(y + 4, x + 10, '-' | COLOR_PAIR(4)); break;
                case 1: mvaddch(y + 4, x + 10, 'M' | COLOR_PAIR(1)); break;
                case 2: mvaddch(y + 4, x + 10, 'x' | COLOR_PAIR(2)); break;
                case 4:
                    mvaddch(y + 4, x + 10, '-' | COLOR_PAIR(4));
                    wbox += 1;
                    obj[wbox].karakterAsli = mvinch(y + 4, x + 10);
                    obj[wbox].posisiY = y + 4;
                    obj[wbox].posisiX = x + 10;
                    obj[wbox].karakter = '@';
                    mvaddch(obj[wbox].posisiY, obj[wbox].posisiX, obj[wbox].karakter | COLOR_PAIR(5));
                    break;
                case 5:
                    mvaddch(y + 4, x + 10, '-' | COLOR_PAIR(4));
                    obj[0].karakterAsli = mvinch(y + 4, x + 10);
                    obj[0].posisiY = y + 4;
                    obj[0].posisiX = x + 10;
                    obj[0].karakter = 'E';
                    mvaddch(obj[0].posisiY, obj[0].posisiX, obj[0].karakter | COLOR_PAIR(3));
                    break;
            }
        }
    }
    move(obj[0].posisiY, obj[0].posisiX);
}

void Main(int input) {
    bool ulang = FALSE;
    chtype atas, kiri, bawah, kanan, atasAsli, kiriAsli, bawahAsli, kananAsli;
    atas = (mvinch(obj[0].posisiY - 1, obj[0].posisiX) & A_CHARTEXT);
    kiri = (mvinch(obj[0].posisiY, obj[0].posisiX - 1) & A_CHARTEXT);
    bawah = (mvinch(obj[0].posisiY + 1, obj[0].posisiX) & A_CHARTEXT);
    kanan = (mvinch(obj[0].posisiY, obj[0].posisiX + 1) & A_CHARTEXT);
    atasAsli = (mvinch(obj[0].posisiY - 2, obj[0].posisiX) & A_CHARTEXT);
    kiriAsli = (mvinch(obj[0].posisiY, obj[0].posisiX - 2) & A_CHARTEXT);
    bawahAsli = (mvinch(obj[0].posisiY + 2, obj[0].posisiX) & A_CHARTEXT);
    kananAsli = (mvinch(obj[0].posisiY, obj[0].posisiX + 2) & A_CHARTEXT);

    for (int o = 0; o <= wbox; o++) {
        mvaddch(obj[o].posisiY, obj[o].posisiX, obj[o].karakterAsli);
    }

    switch (input) {
        case 'w':
            if (atas != 35) {
                if (atas == 64 && (atasAsli == 45 || atasAsli == 120)) {
                    obj[0].posisiY -= 1;
                    for (int o = 1; o <= wbox; o++) {
                        if ((obj[0].posisiY == obj[o].posisiY) && (obj[0].posisiX == obj[o].posisiX)) {
                            obj[o].posisiY -= 1;
                        }
                    }
                } else if (bawah != 64)
                    obj[0].posisiY -= 1;
            }
            break;
        case 's':
            if (bawah != 35) {
                if (bawah == 64 && (bawahAsli == 45 || bawahAsli == 120)) {
                    obj[0].posisiY += 1;
                    for (int o = 1; o <= wbox; o++) {
                        if ((obj[0].posisiY == obj[o].posisiY) && (obj[0].posisiX == obj[o].posisiX)) {
                            obj[o].posisiY += 1;
                        }
                    }
                } else if (bawah != 64)
                    obj[0].posisiY += 1;
            }
            break;
        case 'a':
            if (kiri != 35) {
                if (kiri == 64 && (kiriAsli == 45 || kiriAsli == 120)) {
                    obj[0].posisiX -= 1;
                    for (int o = 1; o <= wbox; o++) {
                        if ((obj[0].posisiY == obj[o].posisiY) && (obj[0].posisiX == obj[o].posisiX)) {
                            obj[o].posisiX -= 1;
                        }
                    }
                } else if (kiri != 64)
                    obj[0].posisiX -= 1;
            }
            break;
        case 'd':
            if (kanan != 35) {
                if (kanan == 64 && (kananAsli == 45 || kananAsli == 120)) {
                    obj[0].posisiX += 1;
                    for (int o = 1; o <= wbox; o++) {
                        if ((obj[0].posisiY == obj[o].posisiY) && (obj[0].posisiX == obj[o].posisiX)) {
                            obj[o].posisiX += 1;
                        }
                    }
                } else if (kanan != 64)
                    obj[0].posisiX += 1;
            }
            break;
        case 'l':
            ulang = TRUE;
            if (lev < 2)
                lev += 1;
            else
                lev = 0;
            Level(lev);
            break;

        case 'r':
            ulang = TRUE;
            Level(lev);
            break;
        default:
            break;
    }

    if (!ulang) {
        for (int o = 0; o <= wbox; o++) {
            obj[o].karakterAsli = mvinch(obj[o].posisiY, obj[o].posisiX);
            mvaddch(obj[o].posisiY, obj[o].posisiX, obj[o].karakter | ((o == 0) ? COLOR_PAIR(3) : COLOR_PAIR(5)));
        }
        move(obj[0].posisiY, obj[0].posisiX);
    } else
        ulang = FALSE;
}

int main() {
	awalan();
    int ch;
    initscr();
    if (!has_colors()) {
        endwin();
        printf("Error initializing colors.\n");
        exit(1);
    }

    start_color();
    palet();
    Level(lev);
    while ((ch = getch()) != 'q') {
        Main(ch);
    }
    endwin();
    return 0;
}

