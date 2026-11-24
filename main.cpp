#include <ncurses/ncurses.h>
using namespace std;

int main(){
    initscr();
    mvprintw(12, 40, "Testing push");
    refresh();
    getch();
    endwin();
    return 0;
}