// Ahad-23-Feb 18:58:45 2025 🐬 || anonvict

#include <ncurses.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

bool show_message = true;
void exit_gracefully(int signum) {
    int rows, cols;
    getmaxyx(stdscr, rows, cols);
    mvaddstr(rows / 2, cols / 2 - strlen("haha") / 2, "haha");
    refresh();
}
void ignore_tstp(int signum) {
    int rows, cols;
    getmaxyx(stdscr, rows, cols);
    mvaddstr(rows / 2, cols / 2 - strlen("haha") / 2, "haha");
    refresh();
}
void ignore_quit(int signum) {
    int rows, cols;
    getmaxyx(stdscr, rows, cols);
    mvaddstr(rows / 2, cols / 2 - strlen("haha") / 2, "haha");
    refresh();
}
int main() {
    srand(time(NULL));
    initscr();
    curs_set(0);
    nodelay(stdscr, TRUE);
    noecho();
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    char message[] = "THIS SESSION HAS BEEN LOCKED !!";
    char user_input[256] = "";
    int input_char;
    system("while true; do play-audio prank.mp3; done &");
    usleep(20000);
    system("while true; do play-audio prank.mp3; done &");
    usleep(40000);
    system("while true; do play-audio prank.mp3; done &");
    usleep(60000);
    system("while true; do play-audio prank.mp3; done &");
    usleep(80000);
    system("while true; do play-audio prank.mp3; done &");
    usleep(100000);
    system("while true; do play-audio prank.mp3; done &");
    usleep(20000);
    system("while true; do play-audio prank.mp3; done &");
    usleep(40000);
    system("while true; do play-audio prank.mp3; done &");
    usleep(60000);
    system("while true; do play-audio prank.mp3; done &");
    usleep(80000);
    system("while true; do play-audio prank.mp3; done &");
    usleep(100000);

    signal(SIGINT, exit_gracefully);
    signal(SIGTSTP, ignore_tstp);
    signal(SIGQUIT, ignore_quit);

    const char* emoji = "😂";
    int emoji_x = 0;
    int emoji_y = 0;
    int emoji_x_direction = 1;
    int emoji_y_direction = 1;

    while (1) {
        int rows, cols;
        getmaxyx(stdscr, rows, cols);

        int x = cols / 2 - strlen(message) / 2;
        int y = rows / 2;

        if (show_message) {
            attron(COLOR_PAIR(1) | A_BOLD);
            mvaddstr(y, x, message);
            attroff(COLOR_PAIR(1) | A_BOLD);
        }

        mvaddstr(emoji_y, emoji_x, emoji);

        emoji_x += emoji_x_direction;
        emoji_y += emoji_y_direction;

        if (emoji_x >= cols - strlen(emoji) || emoji_x < 0) {
            emoji_x_direction *= -1;
        }
        if (emoji_y >= rows || emoji_y < 0) {
            emoji_y_direction *= -1;
        }

        refresh();

        input_char = getch();
        if (input_char != ERR) {
            if (input_char == 'I') {
              endwin();
                exit(0);
            }
        }

        usleep(50000);
        show_message = !show_message;
    }

    endwin();
    return 0;
}
