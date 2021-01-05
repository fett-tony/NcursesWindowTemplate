#ifndef WIN_CLASS_H
#define WIN_CLASS_H

#include <TOOL.BOX.CLASS.h>

using namespace std;

struct FENSTER
{
    int     FEID        {0};
    string  FENAME      {""};
    WINDOW  *TMPWin1    {nullptr};
    MENU    *TMPMenu1   {nullptr};
    ITEM    **TMPItem1  {nullptr};
    WINDOW  *TMPWin2    {nullptr};
    MENU    *TMPMenu2   {nullptr};
    ITEM    **TMPItem2  {nullptr};
    WINDOW  *TMPWin3    {nullptr};
    MENU    *TMPMenu3   {nullptr};
    ITEM    **TMPItem3  {nullptr};
    WINDOW  *TMPWin4    {nullptr};
    WINDOW  *TMPWin5    {nullptr};
    int     TMPWinHigh  {0};
    FORM    *TMPForm1   {nullptr};
    FIELD   **TMPField1 {nullptr};
    void delwinow(WINDOW *tmpwin){
        if(tmpwin){
            int mx,my,bx,by;
            getbegyx(tmpwin,by,bx);
            getmaxyx(tmpwin,my,mx);
            touchwin(tmpwin);
            wborder(tmpwin, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
            touchline(tmpwin,bx,mx);
            delwin(tmpwin);
            endwin();
            tmpwin=nullptr;
        }
    }
    void delmenu(WINDOW *tmpwin, MENU *tmpmenu, ITEM **tmpitem){
        if (tmpmenu){
            int E = item_count(tmpmenu);
            unpost_menu(tmpmenu);
            SAFE_DELETE(tmpmenu);
            SAFE_DELETE_ARRAY(tmpitem);
            wborder(tmpwin, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
            touchline(tmpwin,0,E+1);
            delwin(tmpwin);
            endwin();
        }
    }
    void delform(WINDOW *tmpwin, FORM *tmpform, FIELD **tmpfield){
        if (tmpform){
            int mx,my,bx,by;
            getbegyx(tmpwin,by,bx);
            getmaxyx(tmpwin,my,mx);
            unpost_form(tmpform);
            SAFE_DELETE(tmpform);
            SAFE_DELETE_ARRAY(tmpfield);
            wborder(tmpwin, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
            touchline(tmpwin,bx,mx);
            delwin(tmpwin);
            endwin();
        }
    }
};

class WinClass
{
public:
    static FENSTER START;
    static int max_xc,max_yr;
    //#################MAIN#########################
    static void Start_Win(void);
    static void Stop_Win(void);
    static void FENSTGROESSESETZEN();
    static void Resize_Handler(int);
    static void keypress(int);
    static void AppColor(void);
    static void FensterDesign(void);
    static void ScrollPad(WINDOW * SubWin, int StartY,
                          int StartX, int Height,
                          int Width, int PadHeight);
    //######################################

private:

protected:

};


#endif // WIN_CLASS_H
