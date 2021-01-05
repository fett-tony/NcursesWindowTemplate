#ifndef TOOL_BOX_CLASS_H
#define TOOL_BOX_CLASS_H

#include <ncursesw/cursesapp.h>
#include <ncursesw/ncurses.h>
#include <ncursesw/menu.h>
#include <ncursesw/form.h>
#include <ncursesw/panel.h>
#include <ncursesw/unctrl.h>

//#include <ncurses.h>
//#include <menu.h>
//#include <form.h>
//#include <panel.h>
//#include <unctrl.h>
//#include <sys/pci.h>
#include <sys/dir.h>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <net/if.h>
#include <netinet/ether.h>
#include <netinet/in.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <arpa/nameser.h>
#include <resolv.h>
#include <linux/sockios.h>
//#include <linux/if_arp.h>
#include <linux/netlink.h>
#include <linux/wireless.h>
#include <linux/route.h>
#include <linux/rtnetlink.h>
#include <linux/if.h>
#include <linux/ethtool.h>
#include <asm/types.h>
#include <dirent.h>
#include <exception>
#include <utility>
#include <locale.h>
#include <csignal>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cmath>
#include <chrono>
#include <functional>
#include <algorithm>
#include <fstream>
#include <vector>
#include <thread>
#include <termios.h>
#include <term.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdnoreturn.h>
#include <set>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <memory>
#include <yaml-cpp/yaml.h>
#include <stdnoreturn.h>


using namespace std;

#ifdef __GNUC__
#define NO_RETURN __attribute__((noreturn))
#elif __MINGW32__
#define NO_RETURN __attribute__((noreturn))
#elif __clang__
#define NO_RETURN __attribute__((noreturn))
#elif _MSC_VER
#define NO_RETURN __declspec(noreturn)
#endif

#define     CTRLD                   4
#define     BUFSIZE                 8192
#define     CLEARSCR system         ( "clear" )
#define     UNUSED(x)               (void) (x)
#define     SAFE_DELETE(p)          { if(p) { delete (p); (p) = nullptr; } }
#define     SAFE_DELETE_ARRAY(p)    { if(p) { delete[] (p); (p) = nullptr; } }
#define     ARRAY_SIZE(a)           (sizeof(a) / sizeof(a[0]))
#define     SIZEOF(table)           (sizeof(table) / sizeof(table[0]))

struct DatumUhrZeit {
    int     n = 0;
    time_t  Zeitstempel;
    tm      *UHRZEIT;
    char    UHRZEITchar[19];
    string  UHRZEITstr;
    void TIMEFIELD(WINDOW *TMPWin, int TMPmax_xc) {
        Zeitstempel = time(nullptr);
        UHRZEIT = localtime(&Zeitstempel);
        strftime(UHRZEITchar, size_t(UHRZEITchar), "%d.%m.%Y %T", UHRZEIT);
        UHRZEITstr = string(UHRZEITchar);
        wattr_on(TMPWin, COLOR_PAIR(33)|A_STANDOUT,nullptr);//|A_BOLD,0);
        mvwaddnstr(TMPWin, 0, TMPmax_xc-21, UHRZEITstr.c_str(), -1);
        wattr_off(TMPWin, COLOR_PAIR(33)|A_STANDOUT,nullptr);//|A_BOLD,0);
        refresh();
        wrefresh(TMPWin);
    }
};

class ToolBoxClass {
public:
    //######################_UHR_ZEIT_##############################################
    static volatile     std::sig_atomic_t flag ;
    static void         set_flag(int signal);
    static void         process_signal(DatumUhrZeit& object);
    static struct       DatumUhrZeit datumuhrzeit;
    //######################_UHR_ZEIT_##############################################
    static int HaMeFe_HG, HaMe_FG, HaMe_HG, HaMe_grey, UMeFe_HG;
    static int IlMeFe_HG, IlMe_FG, IlMe_HG, IlMe_grey, IlUMeFe_HG;
    //##############################################################################
    typedef struct {
        int min;
        int max;
        int count(){return max - min;}
        int range{1};
    } RANGE;
    static int      zahlenwerk(int zahlen, string i, int max);
    static int      ZahlenBerechnen(int posa, RANGE range, string wahl);
    static int      ZahlenWerk(int mina, int posa, int maxa, string wahl);
    //##############################################################################
    //--------------------Verlassen-und-Löschen-------------------------------------
    static void     TermQuit(int);
    static WINDOW   *ClearWindow(WINDOW *W);
    static void     ClearScreen();
    static void     DeletAllWin(const char *namem);
    //##############################################################################
    ToolBoxClass();
private:

protected:

};

#endif // TOOL_BOX_CLASS_H
