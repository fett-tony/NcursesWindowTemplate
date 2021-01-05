#ifndef MENU_CLASS_H
#define MENU_CLASS_H

#include "TOOL.BOX.CLASS.h"

using namespace std;

struct HAUPTMENU {
    int       HMID;
    string  HMName;
    WINDOW  *HMWin {nullptr};
    MENU   *HMMenu {nullptr};
    ITEM  **HMItem {nullptr};
    //###############################################
    struct UNTERMENU {
        int       UMID;
        string UMEName;
        WINDOW *UMEWin;
        MENU  *UMEMenu;
        ITEM **UMEItem;
    }UME;
    void LoescheUME(){
        int E = item_count(UME.UMEMenu);
        unpost_menu(UME.UMEMenu);
        SAFE_DELETE(UME.UMEMenu);
        SAFE_DELETE_ARRAY(UME.UMEItem);
        wborder(UME.UMEWin, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
        touchline(UME.UMEWin,0,E+1);
        delwin(UME.UMEWin);
        endwin();
        refresh();
    }
};

class MenuClass
{
public:
    //############################variablen#########
    static HAUPTMENU          MENEU;
    static int               MeInAl;
    static WINDOW           *TMPWIN;
    static MENU            *TMPMENU;
    //##########MENÜ################################
    static void     Hauptmenu(void);
    static void    Datei_menu(void);
    static void   System_menu(void);
    static void   Server_menu(void);
    static void Software_menu(void);
    static void     Info_menu(void);
    static MENU         *tmpMe(string name, int id);
    static WINDOW       *tmpWi(string name, int id);
    static void       fensterwahl(string wahl);
    static void          QUIT(void);
    static void     MenuStart(void);
private:

protected:

};

#endif // MENU_CLASS_H
