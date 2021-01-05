#include <MENU.CLASS.h>
#include <TOOL.BOX.CLASS.h>
#include <WIN.CLASS.h>
#include <FILE.FOLDER.CLASS.h>

using namespace std;

HAUPTMENU MenuClass::MENEU;
WINDOW  *MenuClass::TMPWIN;
MENU   *MenuClass::TMPMENU;
int MenuClass::MeInAl = 0;

void MenuClass::Hauptmenu(void) {
    MenuClass::MENEU.HMID = 0;
    MenuClass::MENEU.HMName = string("HAUPTMENÜ");
    MenuClass::MENEU.HMItem = static_cast<ITEM **>(calloc(6, sizeof(ITEM *)));
    MenuClass::MENEU.HMItem[0] = new_item("Datei", MenuClass::MENEU.HMName.c_str());
    MenuClass::MENEU.HMItem[1] = new_item("System", MenuClass::MENEU.HMName.c_str());
    MenuClass::MENEU.HMItem[2] = new_item("Server", MenuClass::MENEU.HMName.c_str());
    MenuClass::MENEU.HMItem[3] = new_item("Software", MenuClass::MENEU.HMName.c_str());
    MenuClass::MENEU.HMItem[4] = new_item("Info", MenuClass::MENEU.HMName.c_str());
    MenuClass::MENEU.HMItem[5] = nullptr;
    MenuClass::MENEU.HMMenu = new_menu(MenuClass::MENEU.HMItem);
    MenuClass::MENEU.HMWin = newwin(1, WinClass::max_xc-1, 0, 1);
    set_menu_win (MenuClass::MENEU.HMMenu, MenuClass::MENEU.HMWin);
    set_menu_sub(MenuClass::MENEU.HMMenu, MenuClass::MENEU.HMWin);
    //###############################################################
    set_menu_sub(MenuClass::MENEU.UME.UMEMenu, MenuClass::MENEU.HMWin);
    set_menu_sub(MenuClass::MENEU.UME.UMEMenu, MenuClass::MENEU.HMWin);
    set_menu_sub(MenuClass::MENEU.UME.UMEMenu, MenuClass::MENEU.HMWin);
    set_menu_sub(MenuClass::MENEU.UME.UMEMenu, MenuClass::MENEU.HMWin);
    set_menu_sub(MenuClass::MENEU.UME.UMEMenu, MenuClass::MENEU.HMWin);
    //###############################################################
    set_menu_spacing(MenuClass::MENEU.HMMenu, 2, 0, 0);
    set_menu_format(MenuClass::MENEU.HMMenu, 0, 6);
    menu_opts_off(MenuClass::MENEU.HMMenu, O_SHOWDESC);
    menu_opts_off(MenuClass::MENEU.HMMenu, O_NONCYCLIC);
    wbkgd(MenuClass::MENEU.HMWin, COLOR_PAIR(ToolBoxClass::HaMeFe_HG)|A_BOLD);
    //set_menu_fore(MenuClass::MENEU.HMMenu, COLOR_PAIR(12)|A_REVERSE|A_BOLD);
    set_menu_fore(MenuClass::MENEU.HMMenu, COLOR_PAIR(ToolBoxClass::HaMe_FG)|A_REVERSE|A_BOLD);
    set_menu_back(MenuClass::MENEU.HMMenu, COLOR_PAIR(ToolBoxClass::HaMe_HG));//|A_BOLD);
    set_menu_grey(MenuClass::MENEU.HMMenu, COLOR_PAIR(ToolBoxClass::HaMe_grey)|A_BOLD);
    set_menu_mark(MenuClass::MENEU.HMMenu,"");
    post_menu(MenuClass::MENEU.HMMenu);
} /* Hauptmenü */

void MenuClass::Datei_menu(void) {
    MenuClass::MENEU.UME.UMID = 0;
    MenuClass::MENEU.UME.UMEName = string("Datei");
    MenuClass::MenuClass::MENEU.UME.UMEWin = newwin(6, 13, 1, 0);
    wbkgd(MenuClass::MENEU.UME.UMEWin,COLOR_PAIR(ToolBoxClass::UMeFe_HG));
    box(MenuClass::MENEU.UME.UMEWin, 0, 0);
    MenuClass::MENEU.UME.UMEItem = static_cast<ITEM **>(calloc(7, sizeof(ITEM *)));
    MenuClass::MENEU.UME.UMEItem[0] = new_item("Man Page", MenuClass::MENEU.UME.UMEName.c_str());
    MenuClass::MENEU.UME.UMEItem[1] = new_item("Einstellung", MenuClass::MENEU.UME.UMEName.c_str());
    MenuClass::MENEU.UME.UMEItem[2] = new_item("Befehle", MenuClass::MENEU.UME.UMEName.c_str());
    MenuClass::MENEU.UME.UMEItem[3] = new_item("Beenden", MenuClass::MENEU.UME.UMEName.c_str());
    MenuClass::MENEU.UME.UMEItem[4] = nullptr;
    MenuClass::MENEU.UME.UMEMenu = new_menu(MenuClass::MENEU.UME.UMEItem);
    set_menu_win(MenuClass::MENEU.UME.UMEMenu, MenuClass::MENEU.UME.UMEWin);
    set_menu_sub (MenuClass::MENEU.UME.UMEMenu, derwin(MenuClass::MENEU.UME.UMEWin, 0, 0, 1, 1));
    set_menu_spacing(MenuClass::MENEU.UME.UMEMenu, 0,0,0);
    set_menu_format(MenuClass::MENEU.UME.UMEMenu, 5, 0);
    menu_opts_off(MenuClass::MENEU.UME.UMEMenu, O_SHOWDESC);
    menu_opts_off(MenuClass::MENEU.UME.UMEMenu, O_NONCYCLIC);
    //set_menu_fore(MenuClass::MENEU.UME.UMEMenu, COLOR_PAIR(12)|A_REVERSE|A_BOLD);
    set_menu_fore(MenuClass::MENEU.UME.UMEMenu, COLOR_PAIR(ToolBoxClass::HaMe_FG)|A_BOLD);
    set_menu_back(MenuClass::MENEU.UME.UMEMenu, COLOR_PAIR(ToolBoxClass::HaMe_HG));//|A_BOLD);
    set_menu_grey(MenuClass::MENEU.UME.UMEMenu, COLOR_PAIR(ToolBoxClass::HaMe_grey)|A_BOLD);
    set_menu_mark(MenuClass::MENEU.UME.UMEMenu,"");
    set_current_item(MenuClass::MENEU.UME.UMEMenu, MenuClass::MENEU.UME.UMEItem[0]);
    post_menu(MenuClass::MENEU.UME.UMEMenu);
} /* Datei Menü */

void MenuClass::System_menu(void) {
    MenuClass::MENEU.UME.UMID = 1;
    MenuClass::MENEU.UME.UMEName = string("System");
    MenuClass::MENEU.UME.UMEWin = newwin(10, 14, 1, 9);
    wbkgd(MenuClass::MENEU.UME.UMEWin, COLOR_PAIR(ToolBoxClass::UMeFe_HG));
    box(MenuClass::MENEU.UME.UMEWin, 0, 0);
    MenuClass::MENEU.UME.UMEItem = static_cast<ITEM **>(calloc(9,sizeof(ITEM *)));
    MenuClass::MENEU.UME.UMEItem[0] = new_item("Netzwerk", MenuClass::MENEU.UME.UMEName.c_str());
    MenuClass::MENEU.UME.UMEItem[1] = new_item("Samba-client", MenuClass::MENEU.UME.UMEName.c_str());//12
    MenuClass::MENEU.UME.UMEItem[2] = new_item("Benutzer", MenuClass::MENEU.UME.UMEName.c_str());
    MenuClass::MENEU.UME.UMEItem[3] = new_item("Firewall", MenuClass::MENEU.UME.UMEName.c_str());
    MenuClass::MENEU.UME.UMEItem[4] = new_item("Service", MenuClass::MENEU.UME.UMEName.c_str());
    MenuClass::MENEU.UME.UMEItem[5] = new_item("Hardware", MenuClass::MENEU.UME.UMEName.c_str());
    MenuClass::MENEU.UME.UMEItem[6] = new_item("Grub", MenuClass::MENEU.UME.UMEName.c_str());
    MenuClass::MENEU.UME.UMEItem[7] = new_item("Datei Rechte", MenuClass::MENEU.UME.UMEName.c_str());
    MenuClass::MENEU.UME.UMEItem[8] = nullptr;
    MenuClass::MENEU.UME.UMEMenu = new_menu(MenuClass::MENEU.UME.UMEItem);
    set_menu_win (MenuClass::MENEU.UME.UMEMenu, MenuClass::MENEU.UME.UMEWin);
    set_menu_sub (MenuClass::MENEU.UME.UMEMenu, derwin(MenuClass::MENEU.UME.UMEWin, 0, 0, 1, 1));
    set_menu_spacing(MenuClass::MENEU.UME.UMEMenu, 0, 1, 0);
    set_menu_format(MenuClass::MENEU.UME.UMEMenu, 8, 1);
    menu_opts_off(MenuClass::MENEU.UME.UMEMenu, O_SHOWDESC);
    menu_opts_off(MenuClass::MENEU.UME.UMEMenu, O_NONCYCLIC);
    //set_menu_fore(MenuClass::MENEU.UME.UMEMenu, COLOR_PAIR(12)|A_REVERSE|A_BOLD);
    set_menu_fore(MenuClass::MENEU.UME.UMEMenu, COLOR_PAIR(ToolBoxClass::HaMe_FG)|A_BOLD);
    set_menu_back(MenuClass::MENEU.UME.UMEMenu, COLOR_PAIR(ToolBoxClass::HaMe_HG));//|A_BOLD);
    set_menu_grey(MenuClass::MENEU.UME.UMEMenu, COLOR_PAIR(ToolBoxClass::HaMe_grey)|A_BOLD);
    set_menu_mark(MenuClass::MENEU.UME.UMEMenu,"");
    set_current_item(MenuClass::MENEU.UME.UMEMenu, MenuClass::MENEU.UME.UMEItem[0]);
    post_menu(MenuClass::MENEU.UME.UMEMenu);

} /* System Untermenü */

void MenuClass::Server_menu(void) {
    MenuClass::MENEU.UME.UMID = 2;
    MenuClass::MENEU.UME.UMEName = string("Server");
    MenuClass::MENEU.UME.UMEWin = newwin(10, 14, 1, 18);
    wbkgd(MenuClass::MENEU.UME.UMEWin, COLOR_PAIR(ToolBoxClass::UMeFe_HG));
    box(MenuClass::MENEU.UME.UMEWin, 0, 0);
    MenuClass::MENEU.UME.UMEItem = static_cast<ITEM **>(calloc(9, sizeof(ITEM *)));
    MenuClass::MENEU.UME.UMEItem[0] = new_item("LDAP", MenuClass::MENEU.UME.UMEName.c_str());
    MenuClass::MENEU.UME.UMEItem[1] = new_item("Samba-Server", MenuClass::MENEU.UME.UMEName.c_str());//12
    MenuClass::MENEU.UME.UMEItem[2] = new_item("Kerberos", MenuClass::MENEU.UME.UMEName.c_str());
    MenuClass::MENEU.UME.UMEItem[3] = new_item("DHCP", MenuClass::MENEU.UME.UMEName.c_str());
    MenuClass::MENEU.UME.UMEItem[4] = new_item("DNS-Server", MenuClass::MENEU.UME.UMEName.c_str());
    MenuClass::MENEU.UME.UMEItem[5] = new_item("FreeRadius", MenuClass::MENEU.UME.UMEName.c_str());
    MenuClass::MENEU.UME.UMEItem[6] = new_item("Netboot", MenuClass::MENEU.UME.UMEName.c_str());
    MenuClass::MENEU.UME.UMEItem[7] = new_item("WLan-AP", MenuClass::MENEU.UME.UMEName.c_str());
    MenuClass::MENEU.UME.UMEItem[8] = nullptr;
    MenuClass::MENEU.UME.UMEMenu = new_menu(MenuClass::MENEU.UME.UMEItem);
    set_menu_win (MenuClass::MENEU.UME.UMEMenu, MenuClass::MENEU.UME.UMEWin);
    set_menu_sub (MenuClass::MENEU.UME.UMEMenu, derwin(MenuClass::MENEU.UME.UMEWin, 0, 0, 1, 1));
    set_menu_spacing(MenuClass::MENEU.UME.UMEMenu, 0, 0, 0);
    set_menu_format(MenuClass::MENEU.UME.UMEMenu, 9, 0);
    menu_opts_off(MenuClass::MENEU.UME.UMEMenu, O_SHOWDESC);
    menu_opts_off(MenuClass::MENEU.UME.UMEMenu, O_NONCYCLIC);
    //set_menu_fore(MenuClass::MENEU.UME.UMEMenu, COLOR_PAIR(12)|A_REVERSE|A_BOLD);
    set_menu_fore(MenuClass::MENEU.UME.UMEMenu, COLOR_PAIR(ToolBoxClass::HaMe_FG)|A_BOLD);
    set_menu_back(MenuClass::MENEU.UME.UMEMenu, COLOR_PAIR(ToolBoxClass::HaMe_HG));//|A_BOLD);
    set_menu_grey(MenuClass::MENEU.UME.UMEMenu, COLOR_PAIR(ToolBoxClass::HaMe_grey)|A_BOLD);
    set_menu_mark(MenuClass::MENEU.UME.UMEMenu,"");
    set_current_item(MenuClass::MENEU.UME.UMEMenu, MenuClass::MENEU.UME.UMEItem[0]);
    post_menu(MenuClass::MENEU.UME.UMEMenu);
} /* Server Untermenü */

void MenuClass::Software_menu(void) {
    MenuClass::MENEU.UME.UMID = 3;
    MenuClass::MENEU.UME.UMEName = string("Software");
    MenuClass::MENEU.UME.UMEWin = newwin(6, 17, 1, 27);
    wbkgd(MenuClass::MENEU.UME.UMEWin,COLOR_PAIR(ToolBoxClass::UMeFe_HG));
    box(MenuClass::MENEU.UME.UMEWin,0,0);
    MenuClass::MENEU.UME.UMEItem = static_cast<ITEM **>(calloc(5,sizeof(ITEM *)));
    MenuClass::MENEU.UME.UMEItem[0] = new_item("Installiert", MenuClass::MENEU.UME.UMEName.c_str());
    MenuClass::MENEU.UME.UMEItem[1] = new_item("Software-Center", MenuClass::MENEU.UME.UMEName.c_str());//15
    MenuClass::MENEU.UME.UMEItem[2] = new_item("AK-UB-conf", MenuClass::MENEU.UME.UMEName.c_str());
    MenuClass::MENEU.UME.UMEItem[3] = new_item("Starten", MenuClass::MENEU.UME.UMEName.c_str());
    MenuClass::MENEU.UME.UMEItem[4] = nullptr;
    MenuClass::MENEU.UME.UMEMenu = new_menu(MenuClass::MENEU.UME.UMEItem);
    set_menu_win (MenuClass::MENEU.UME.UMEMenu, MenuClass::MENEU.UME.UMEWin);
    set_menu_sub (MenuClass::MENEU.UME.UMEMenu, derwin(MenuClass::MENEU.UME.UMEWin, 0, 0, 1, 1));
    set_menu_spacing(MenuClass::MENEU.UME.UMEMenu, 0, 0, 0);
    set_menu_format(MenuClass::MENEU.UME.UMEMenu, 5, 0);
    menu_opts_off(MenuClass::MENEU.UME.UMEMenu, O_SHOWDESC);
    menu_opts_off(MenuClass::MENEU.UME.UMEMenu, O_NONCYCLIC);
    //set_menu_fore(MenuClass::MENEU.UME.UMEMenu, COLOR_PAIR(12)|A_REVERSE|A_BOLD);
    set_menu_fore(MenuClass::MENEU.UME.UMEMenu, COLOR_PAIR(ToolBoxClass::HaMe_FG)|A_BOLD);
    set_menu_back(MenuClass::MENEU.UME.UMEMenu, COLOR_PAIR(ToolBoxClass::HaMe_HG));//|A_BOLD);
    set_menu_grey(MenuClass::MENEU.UME.UMEMenu, COLOR_PAIR(ToolBoxClass::HaMe_grey)|A_BOLD);
    set_menu_mark(MenuClass::MENEU.UME.UMEMenu,"");
    set_current_item(MenuClass::MENEU.UME.UMEMenu, MenuClass::MENEU.UME.UMEItem[0]);
    post_menu(MenuClass::MENEU.UME.UMEMenu);
} /* Software Untermenü */

void MenuClass::Info_menu(void) {
    MenuClass::MENEU.UME.UMID = 4;
    MenuClass::MENEU.UME.UMEName = string("Info");
    MenuClass::MENEU.UME.UMEWin = newwin(5,11,1,36 );
    wbkgd(MenuClass::MENEU.UME.UMEWin,COLOR_PAIR(ToolBoxClass::UMeFe_HG));
    box(MenuClass::MENEU.UME.UMEWin,0,0);
    //MenuClass::MENEU.UME.UMEItem = (ITEM **)calloc(4, sizeof(ITEM *));
    MenuClass::MENEU.UME.UMEItem = static_cast<ITEM **>(calloc(4, sizeof(ITEM *)));
    MenuClass::MENEU.UME.UMEItem[0] = new_item("Code", MenuClass::MENEU.UME.UMEName.c_str());
    MenuClass::MENEU.UME.UMEItem[1] = new_item("E-Mail", MenuClass::MENEU.UME.UMEName.c_str());
    MenuClass::MENEU.UME.UMEItem[2] = new_item("Beenden", MenuClass::MENEU.UME.UMEName.c_str());
    MenuClass::MENEU.UME.UMEItem[3] = nullptr;
    MenuClass::MENEU.UME.UMEMenu = new_menu(MenuClass::MENEU.UME.UMEItem);
    set_menu_win(MenuClass::MENEU.UME.UMEMenu, MenuClass::MENEU.UME.UMEWin);
    set_menu_sub (MenuClass::MENEU.UME.UMEMenu, derwin(MenuClass::MENEU.UME.UMEWin, 0, 0, 1, 1));
    set_menu_spacing(MenuClass::MENEU.UME.UMEMenu, 0,0,0);
    set_menu_format(MenuClass::MENEU.UME.UMEMenu, 5, 0);
    menu_opts_off(MenuClass::MENEU.UME.UMEMenu, O_SHOWDESC);
    menu_opts_off(MenuClass::MENEU.UME.UMEMenu, O_NONCYCLIC);
    //set_menu_fore(MenuClass::MENEU.UME.UMEMenu, COLOR_PAIR(12)|A_REVERSE|A_BOLD);
    set_menu_fore(MenuClass::MENEU.UME.UMEMenu, COLOR_PAIR(ToolBoxClass::HaMe_FG)|A_BOLD);
    set_menu_back(MenuClass::MENEU.UME.UMEMenu, COLOR_PAIR(ToolBoxClass::HaMe_HG));//|A_BOLD);
    set_menu_grey(MenuClass::MENEU.UME.UMEMenu, COLOR_PAIR(ToolBoxClass::HaMe_grey)|A_BOLD);
    set_menu_mark(MenuClass::MENEU.UME.UMEMenu,"");
    set_current_item(MenuClass::MENEU.UME.UMEMenu, MenuClass::MENEU.UME.UMEItem[0]);
    post_menu(MenuClass::MENEU.UME.UMEMenu);
} /* Info Menü */

WINDOW *MenuClass::tmpWi(string name, int id) {
    if ((strcmp(name.c_str(),"Datei")==0) || (id==0)){
        MenuClass::Datei_menu();
        MenuClass::TMPWIN = MenuClass::MENEU.UME.UMEWin;
        MenuClass::TMPMENU = MenuClass::MENEU.UME.UMEMenu;
    }else if ((strcmp(name.c_str(),"System")==0) || (id==1)){
        MenuClass::System_menu();
        MenuClass::TMPWIN = MenuClass::MENEU.UME.UMEWin;
        MenuClass::TMPMENU = MenuClass::MENEU.UME.UMEMenu;
    }else if ((strcmp(name.c_str(),"Server")==0) || (id==2)){
        MenuClass::Server_menu();
        MenuClass::TMPWIN = MenuClass::MENEU.UME.UMEWin;
        MenuClass::TMPMENU = MenuClass::MENEU.UME.UMEMenu;
    }else if ((strcmp(name.c_str(),"Software")==0) || (id==3)){
        MenuClass::Software_menu();
        MenuClass::TMPWIN = MenuClass::MENEU.UME.UMEWin;
        MenuClass::TMPMENU = MenuClass::MENEU.UME.UMEMenu;
    }else if ((strcmp(name.c_str(),"Info")==0) || (id==4)){
        MenuClass::Info_menu();
        MenuClass::TMPWIN = MenuClass::MENEU.UME.UMEWin;
        MenuClass::TMPMENU = MenuClass::MENEU.UME.UMEMenu;
    }
    return MenuClass::TMPWIN;
}

NO_RETURN void MenuClass::fensterwahl(string wahl) {
    if (strcmp(wahl.c_str(), "Man Page")==0){
        exit(EXIT_SUCCESS);
        //DATEIMANPAGE::Start_ManP();
    }else if (strcmp(wahl.c_str(),"Befehle")==0){
        exit(EXIT_SUCCESS);
        //DATEIBEFEHLE::befehle_main();
    }else if (strcmp(wahl.c_str(),"Einstellung")==0){
        exit(EXIT_SUCCESS);
        //WinClass::einDa();
    }else if (strcmp(wahl.c_str(),"Beenden")==0){
        exit(EXIT_SUCCESS);
    }else if (strcmp(wahl.c_str(),"Netzwerk")==0){
        exit(EXIT_SUCCESS);
        //SYSNETZMENU::sys_main();
    }else if (strcmp(wahl.c_str(),"Samba-Client")==0){
        exit(EXIT_SUCCESS);
    }else if (strcmp(wahl.c_str(),"Firewall")==0){
        exit(EXIT_SUCCESS);
        //arrayshow("netzwerk1");
    }else if (strcmp(wahl.c_str(),"Service")==0){
        exit(EXIT_SUCCESS);
    }else if (strcmp(wahl.c_str(),"Hardware")==0){
        exit(EXIT_SUCCESS);
        //arrayshow("netzwerk1");
    }else if (strcmp(wahl.c_str(),"Benutzer")==0){
        exit(EXIT_SUCCESS);
        //TEST::test();
    }else if (strcmp(wahl.c_str(),"LDAP")==0){
        exit(EXIT_SUCCESS);
        //arrayshow("netzwerk1");
    }else if (strcmp(wahl.c_str(),"Samba-Server")==0){
        exit(EXIT_SUCCESS);
    }else if (strcmp(wahl.c_str(),"AK-UB-conf")==0){
        exit(EXIT_SUCCESS);
        //SOFTAKINSTALL::AK_UB_start();
    }else if (strcmp(wahl.c_str(),"Datei Rechte")==0){
        exit(EXIT_SUCCESS);
        //SYSDATEIRECHTE::Start_Rechte();
    }else{
        exit(EXIT_SUCCESS);
    }
}

void MenuClass::QUIT(void)
{
    try {
        //###############--Hauptmenu--###############################################
        int E = item_count(MenuClass::MENEU.HMMenu);
        unpost_menu(MenuClass::MENEU.HMMenu);
        SAFE_DELETE(MenuClass::MENEU.HMMenu);
        SAFE_DELETE_ARRAY(MenuClass::MENEU.HMItem);
        wborder(MenuClass::MENEU.HMWin, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
        touchline(MenuClass::MENEU.HMWin,0,E+1);
        delwin(MenuClass::MENEU.HMWin);
        endwin();
        //###############--Untermenu--###############################################
        E = item_count(MenuClass::MENEU.UME.UMEMenu);
        unpost_menu(MenuClass::MENEU.UME.UMEMenu);
        SAFE_DELETE(MenuClass::MENEU.UME.UMEMenu);
        SAFE_DELETE_ARRAY(MenuClass::MENEU.UME.UMEItem);
        wborder(MenuClass::MENEU.UME.UMEWin, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
        touchline(MenuClass::MENEU.UME.UMEWin,0,E+1);
        delwin(MenuClass::MENEU.UME.UMEWin);
        endwin();

        refresh();
        redrawwin(ToolBoxClass::ClearWindow(WinClass::START.TMPWin2));
        wrefresh(ToolBoxClass::ClearWindow(WinClass::START.TMPWin2));

    } catch (const NCursesException *e) {
        endwin();
        std::cerr << string(e->classname()) << std::endl;
        //res = e.errorno;
    } catch (const NCursesException &e) {
        endwin();
        std::cerr << e.message << std::endl;
        //res = e.errorno;
    } catch (const std::exception &e) {
        endwin();
        std::cerr << "Exception: " << e.what() << std::endl;
        //res = EXIT_FAILURE;
    }
}

void MenuClass::MenuStart(void)
{
    int ch;
    set_current_item(MenuClass::MENEU.HMMenu, MenuClass::MENEU.HMItem[MenuClass::MeInAl]);
    MenuClass::TMPWIN = MenuClass::tmpWi(item_name(current_item(MenuClass::MENEU.HMMenu)),item_index(current_item(MenuClass::MENEU.HMMenu)));
    string tmpMeNa = string(item_name(current_item(MenuClass::MENEU.HMMenu)));
    string MeAuWa = "";
    refresh();

    while((ch=getch()) != KEY_F(10)){
        switch(ch){
            case KEY_DOWN:{
                menu_driver(MenuClass::MENEU.UME.UMEMenu, REQ_DOWN_ITEM);
                break;
            }
            case KEY_UP:{
                menu_driver(MenuClass::MENEU.UME.UMEMenu, REQ_UP_ITEM);
                break;
            }
            case KEY_RIGHT:{
                menu_driver(MenuClass::MENEU.HMMenu, REQ_RIGHT_ITEM);
                tmpMeNa = string(item_name(current_item(MenuClass::MENEU.HMMenu)));
                MenuClass::MENEU.LoescheUME();
                MenuClass::TMPWIN = MenuClass::tmpWi(item_name(current_item(MenuClass::MENEU.HMMenu)),
                                          item_index(current_item(MenuClass::MENEU.HMMenu)));
                break;
            }
            case KEY_LEFT:{
                menu_driver(MenuClass::MENEU.HMMenu, REQ_LEFT_ITEM);
                tmpMeNa = string(item_name(current_item(MenuClass::MENEU.HMMenu)));
                MenuClass::MENEU.LoescheUME();
                MenuClass::TMPWIN = MenuClass::tmpWi(item_name(current_item(MenuClass::MENEU.HMMenu)),
                                          item_index(current_item(MenuClass::MENEU.HMMenu)));
                break;
            }
            case 10:{
                MenuClass::MeInAl = item_index(current_item(MenuClass::MENEU.HMMenu));
                MenuClass::MENEU.LoescheUME();
                MenuClass::fensterwahl(item_name(current_item(MenuClass::MENEU.UME.UMEMenu)));
                break;
            }
        }
        redrawwin(ToolBoxClass::ClearWindow(WinClass::START.TMPWin2));
        wrefresh(ToolBoxClass::ClearWindow(WinClass::START.TMPWin2));
        wrefresh(ToolBoxClass::ClearWindow(MenuClass::MENEU.HMWin));
        redrawwin(ToolBoxClass::ClearWindow(MenuClass::MENEU.UME.UMEWin));
        wrefresh(ToolBoxClass::ClearWindow(MenuClass::MENEU.UME.UMEWin));
    }
}
