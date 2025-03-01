// Ahad-23-Feb 18:57:12 2025 🐬 || anonvict

#include <ncurses.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define EMOJI "😂"
typedef struct {
    int x, y;
    int dx, dy;
} Emoji;

bool tampilkan_pesan = true;
int jumlah_emoji = 100;
Emoji emojis[100];
char kisi[256][256];

void keluar_dengan_aman(int sinyal) {
    endwin();
    exit(0);
}
void abaikan_sinyal(int sinyal) {}
int main() {
    srand(time(NULL));
    initscr();
    curs_set(0);
    nodelay(stdscr, TRUE);
    noecho();
    cbreak();
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);

    char pesan[] = "THIS SESSION HAS BEEN LOCKED !!";

    int baris, kolom;
    getmaxyx(stdscr, baris, kolom);
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            kisi[i][j] = ' ';
        }
    }

    for (int i = 0; i < jumlah_emoji; i++) {
        do {
            emojis[i].x = rand() % kolom;
            emojis[i].y = rand() % baris;
        } while (kisi[emojis[i].y][emojis[i].x] != ' ');

        kisi[emojis[i].y][emojis[i].x] = 'E';
        emojis[i].dx = (rand() % 3) - 1;
        emojis[i].dy = (rand() % 3) - 1;
    }
    system("while true; do play-audio prank.mp3; done &");
    usleep(10000);
    system("while true; do play-audio prank.mp3; done &");
    usleep(900000);
    system("while true; do play-audio prank.mp3; done &");
    usleep(1000);
    cbreak();
    signal(SIGINT, abaikan_sinyal);
    signal(SIGTSTP, abaikan_sinyal);
    signal(SIGQUIT, abaikan_sinyal);
    while (1) {
        clear();
        getmaxyx(stdscr, baris, kolom);
        for (int i = 0; i < baris; i++) {
            for (int j = 0; j < kolom; j++) {
                kisi[i][j] = ' ';
            }
        }
        int x = kolom / 2 - strlen(pesan) / 2;
        int y = baris / 2;

        if (tampilkan_pesan) {
            attron(COLOR_PAIR(1) | A_BOLD);
            mvaddstr(y, x, pesan);
            attroff(COLOR_PAIR(1) | A_BOLD);
        }

        for (int i = 0; i < jumlah_emoji; i++) {
            kisi[emojis[i].y][emojis[i].x] = ' ';

            emojis[i].x += emojis[i].dx;
            emojis[i].y += emojis[i].dy;

            if (emojis[i].x <= 0 || emojis[i].x >= kolom - 1 || kisi[emojis[i].y][emojis[i].x] != ' ') {
                emojis[i].dx *= -1;
            }
            if (emojis[i].y <= 0 || emojis[i].y >= baris - 1 || kisi[emojis[i].y][emojis[i].x] != ' ') {
                emojis[i].dy *= -1;
            }

            emojis[i].x = (emojis[i].x < 0) ? 0 : (emojis[i].x >= kolom - 1 ? kolom - 2 : emojis[i].x);
            emojis[i].y = (emojis[i].y < 0) ? 0 : (emojis[i].y >= baris - 1 ? baris - 2 : emojis[i].y);

            mvaddstr(emojis[i].y, emojis[i].x, EMOJI);

            if (emojis[i].x >= 0 && emojis[i].x < kolom && emojis[i].y >= 0 && emojis[i].y < baris) {
                kisi[emojis[i].y][emojis[i].x] = 'E';
            }
        }

        refresh();

        if (getch() == 'I') {
            endwin();
            exit(0);
        }

        usleep(60000);
        tampilkan_pesan = !tampilkan_pesan;
    }

    endwin();
    return 0;
}
