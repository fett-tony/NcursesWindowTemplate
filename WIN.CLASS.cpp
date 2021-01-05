#include <MENU.CLASS.h>
#include <WIN.CLASS.h>
#include <TOOL.BOX.CLASS.h>
#include <FILE.FOLDER.CLASS.h>

using namespace std;

FENSTER WinClass::START;
int WinClass::max_xc = 79;
int WinClass::max_yr = 23;

void WinClass::Start_Win() {
    setlocale(LC_CTYPE,"de_DE.UTF-8");
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    //raw();
    //(void) nonl();
    //clear();
    //syncok(stdscr,true);
}

void WinClass::Stop_Win() {
    endwin();
}

void WinClass::AppColor() {
    start_color();
    short MY_MARIN_BLUE=240, MY_LIGHT_BLUE=250;
    short R=0,G=0;//,B=0;
    init_color(MY_MARIN_BLUE, R, G, static_cast<short int>(300));
    init_color(MY_LIGHT_BLUE, R, G, static_cast<short int>(850));

    /* hintergrund Blau */
    init_pair(01, COLOR_WHITE, COLOR_BLUE);
    init_pair(02, COLOR_MAGENTA,COLOR_BLUE);
    init_pair(03, COLOR_RED,COLOR_BLUE);
    init_pair(04, COLOR_BLACK,COLOR_BLUE);
    init_pair(05, COLOR_YELLOW,COLOR_BLUE);
    init_pair(06, MY_MARIN_BLUE,COLOR_BLUE);
    /* hintergrund Schwarz */
    init_pair(11, COLOR_WHITE,COLOR_BLACK);
    init_pair(12, COLOR_RED,COLOR_BLACK);
    init_pair(13, COLOR_YELLOW,COLOR_BLACK);
    init_pair(14, COLOR_GREEN,COLOR_BLACK);
    init_pair(15, COLOR_CYAN,COLOR_BLACK);
    /* hintergrund gelb */
    init_pair(21, COLOR_BLUE, COLOR_YELLOW);
    init_pair(22, COLOR_BLACK,COLOR_YELLOW);
    init_pair(23, COLOR_GREEN,COLOR_YELLOW);
    /* hintergrund weiß */
    init_pair(31, COLOR_RED,COLOR_WHITE);
    init_pair(32, COLOR_BLACK,COLOR_WHITE);
    init_pair(33, COLOR_BLUE,COLOR_WHITE);
    init_pair(34, COLOR_YELLOW,COLOR_WHITE);
    init_pair(35, MY_MARIN_BLUE,COLOR_WHITE);
    /* hintergrund Rot */
    init_pair(41, COLOR_BLACK,COLOR_RED);
    init_pair(42, COLOR_WHITE,COLOR_RED);
    /* hintergrund Cyan */
    init_pair(51, COLOR_WHITE,COLOR_CYAN);
    init_pair(52, COLOR_YELLOW,COLOR_CYAN);
    init_pair(53, COLOR_RED,COLOR_CYAN);
    /* hintergrund Marin Blau */
    init_pair(61, COLOR_WHITE,MY_MARIN_BLUE);
    init_pair(62, COLOR_YELLOW,MY_MARIN_BLUE);
    init_pair(63, COLOR_RED,MY_MARIN_BLUE);
    /* Light Blue hintergrund */
    init_pair(71, COLOR_WHITE,MY_LIGHT_BLUE);
    init_pair(72, COLOR_YELLOW,MY_LIGHT_BLUE);
    init_pair(73, COLOR_RED,MY_LIGHT_BLUE);
} /*---------Programm_Farben------------------------*/

void WinClass::FensterDesign(void)
{
    WinClass::START.FEID = 0;
    WinClass::START.FENAME = string("VARSYSMAN");
    WinClass::START.TMPWin1 = newwin(1, WinClass::max_xc, 0, 0);
    MenuClass::MENEU.HMWin = derwin(WinClass::START.TMPWin1, 1, WinClass::max_xc, 0, 0);
    WinClass::START.TMPWin2 = newwin(WinClass::max_yr-1, WinClass::max_xc, 1, 0);
    WinClass::START.TMPWin3 = newwin(WinClass::max_yr-3, WinClass::max_xc-2, 2, 1);
    //WinClass::START.TMPWin3 = subwin(WinClass::START.TMPWin2, WinClass::max_yr-3, WinClass::max_xc-2, 2, 1);
    //WinClass::START.TMPWin4 = derwin(WinClass::START.TMPWin2, WinClass::max_yr-3, WinClass::max_xc-2, 2, 1);
    wbkgd(WinClass::START.TMPWin1, COLOR_PAIR(ToolBoxClass::HaMeFe_HG));
    wbkgd(WinClass::START.TMPWin2, COLOR_PAIR(61));
    wbkgd(WinClass::START.TMPWin3, COLOR_PAIR(61));

    box(WinClass::START.TMPWin2, 0,0);
    box(WinClass::START.TMPWin3, 0,0);

    wsetscrreg(WinClass::START.TMPWin2,0,WinClass::max_yr-3);
    scrollok(WinClass::START.TMPWin2,true);
    //scroll(WinClass::START.TMPWin2);

    refresh();
    wrefresh(WinClass::START.TMPWin1);
    touchwin(WinClass::START.TMPWin1);
    wrefresh(MenuClass::MENEU.HMWin);
    touchwin(MenuClass::MENEU.HMWin);
    wrefresh(WinClass::START.TMPWin2);
    touchwin(WinClass::START.TMPWin2);
    wrefresh(WinClass::START.TMPWin3);
    touchwin(WinClass::START.TMPWin3);
} /*---------Fenster sub----------------------------*/

void WinClass::ScrollPad(WINDOW * SubWin, int StartY, int StartX, int Height, int Width, int PadHeight)
{
    int Choice = 0, Key = 0;
    keypad(SubWin, true);
    refresh();
    int cols = 0;
    while (Choice == 0)
    {
        prefresh(SubWin, cols,0,StartY,StartX,Height,Width);
        Key = wgetch(SubWin);
        switch(Key)
        {
        case KEY_UP:
        {
            if (cols <= 0) continue;
            cols--;
            break;
        }
        case KEY_DOWN:
        {
            if (cols+Height+1 >= PadHeight) continue;
            cols++;
            break;
        }
        case KEY_PPAGE: /* Page Up */
        {
            if (cols <= 0) continue;
            cols -= Height;
            if (cols < 0) cols = 0;
            break;
        }
        case KEY_NPAGE: /* Page Down */
            if (cols+Height+1 >= PadHeight) continue;
            cols += Height;
            if (cols+Height+1 > PadHeight) cols = PadHeight-Height-1;
            break;
        case KEY_HOME:
            cols = 0;
            break;
        case KEY_END:
            cols = PadHeight-Height-1;
            break;
        case 10: /* Enter */
        {
            Choice = 1;
            break;
        }
        }
        refresh();
    }
    delwin(SubWin);
}

void WinClass::FENSTGROESSESETZEN() {
    getmaxyx(stdscr, WinClass::max_yr, WinClass::max_xc);
    WinClass::FensterDesign();
    MenuClass::Hauptmenu();
}

void WinClass::Resize_Handler(int sig) {
    WinClass::Stop_Win();
    WinClass::Start_Win();
    WinClass::FENSTGROESSESETZEN();
}

void WinClass::keypress(int sig) {
    int c;
    c=getch();
    switch (c) {
        case KEY_F(1): {
            mvwaddstr(WinClass::START.TMPWin2, 5, 3,"F1 wurde gedrückt");
            mvwaddstr(WinClass::START.TMPWin3, 6, 3,"F1 wurde gedrückt");
            break;
        }
        default: {
            break;
        }
            refresh();
        wrefresh(ToolBoxClass::ClearWindow(WinClass::START.TMPWin2));
        wrefresh(ToolBoxClass::ClearWindow(WinClass::START.TMPWin3));
    }
}

int main() {
    try {
        werase(stdscr);
        int ch;

        WinClass::Start_Win();
        WinClass::AppColor();

        signal(SIGWINCH, WinClass::Resize_Handler);
        WinClass::FENSTGROESSESETZEN();

        signal(SIGURG, WinClass::keypress);

        //#######################################################################################
        //-------------_DatumUhrZeit_datumuhrzeit_-----------------------------------------------
        std::thread worker(ToolBoxClass::process_signal, std::ref(ToolBoxClass::datumuhrzeit));
        std::signal( SIGINT,ToolBoxClass::set_flag);
        std::signal( SIGTERM,ToolBoxClass::set_flag);
        worker.detach();
        //#######################################################################################

        refresh();
        wrefresh(ToolBoxClass::ClearWindow(WinClass::START.TMPWin1));
        wrefresh(ToolBoxClass::ClearWindow(MenuClass::MENEU.HMWin));
        wrefresh(ToolBoxClass::ClearWindow(WinClass::START.TMPWin2));

        while ((ch=getch()) != KEY_F(10)) {
            switch (ch) {
                case KEY_F(9): {
                    wrefresh(ToolBoxClass::ClearWindow(MenuClass::MENEU.HMWin));
                    pos_menu_cursor(MenuClass::MENEU.HMMenu);
                    set_current_item(MenuClass::MENEU.HMMenu, MenuClass::MENEU.HMItem[MenuClass::MeInAl]);
                    MenuClass::TMPWIN = MenuClass::tmpWi(item_name(current_item(MenuClass::MENEU.HMMenu)),
                                                         item_index(current_item(MenuClass::MENEU.HMMenu)));
                    menu_driver(MenuClass::TMPMENU, REQ_DOWN_ITEM);
                    wrefresh(ToolBoxClass::ClearWindow(MenuClass::MENEU.HMWin));
                    MenuClass::MenuStart();
                    break;
                }
                default: {
                    break;
                }
            }
        }
    } catch (const NCursesException *e) {
        endwin();
        std::cerr << e->message << std::endl;
        cout << e->errorno;
    } catch (const NCursesException &e) {
        endwin();
        std::cerr << e.message << std::endl;
        cout << e.errorno;
    } catch (const std::exception &e) {
        endwin();
        std::cerr << "Exception: " << e.what() << std::endl;
        cout << EXIT_FAILURE;
    }
}
