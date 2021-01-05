#include <MENU.CLASS.h>
#include <TOOL.BOX.CLASS.h>
#include <WIN.CLASS.h>
#include <FILE.FOLDER.CLASS.h>

using namespace std;

//####################################################################
//-------Color-Hauptmenue---------------------------------------------
int ToolBoxClass::HaMeFe_HG = 06,//Fenster_Background-----------------
    ToolBoxClass::HaMe_FG = 01,//Hauptmenue_Foreground----------------
    ToolBoxClass::HaMe_HG = 06,//Hauptmenue_Background----------------
    ToolBoxClass::HaMe_grey = 04,//Hauptmenue_inaktive----------------
    ToolBoxClass::UMeFe_HG = 01;//Fenster_Untermenue------------------
//####################################################################
//-------Color-InApp-Menues-------------------------------------------
int ToolBoxClass::IlMeFe_HG = 61,//Fenster_Background-----------------
    ToolBoxClass::IlMe_FG = 42,//InnLineMenue_Foreground--------------
    ToolBoxClass::IlMe_HG = 63,//InnLineMenue_Background--------------
    ToolBoxClass::IlMe_grey = 63,//InnLineMenue_inaktive--------------
    ToolBoxClass::IlUMeFe_HG = 35;//Fenster_Untermenue----------------
//####################################################################
//-------Uhrzeit-Anzeigen---------------------------------------------
volatile std::sig_atomic_t ToolBoxClass::flag ;
void ToolBoxClass::set_flag(int signal) { flag = signal ; }
struct DatumUhrZeit ToolBoxClass::datumuhrzeit;
void ToolBoxClass::process_signal( DatumUhrZeit& object ) {
    while (flag != SIGTERM) {
        object.TIMEFIELD(MenuClass::MENEU.HMWin,WinClass::max_xc);
        std::this_thread::sleep_for( std::chrono::milliseconds(1000) ) ;
    }
}
//####################################################################
//eigenes zählwerk um von forn an fangen zu können
//aktuelle zahl, string ob + oder -, maximale höchste zahl
int ToolBoxClass::zahlenwerk(int zahlen, string i, int max)
{
    int tmp = 0;
    if (strcmp(i.c_str(),"++")==0){
        if(zahlen>=max){
            tmp = 1;
        }else if(zahlen==0){
            tmp = 1;
        }else if (zahlen>0){
            tmp = ++zahlen;
        }else if (zahlen<max){
            tmp = ++zahlen;
        }
    }else if(strcmp(i.c_str(),"--")==0){
        if(zahlen<=0){
            tmp = max;
        }else if (zahlen==1){
            tmp = max;
        }else if (zahlen>1){
            tmp = --zahlen;
        }else if(zahlen<=max){
            tmp = --zahlen;
        }
    }else{
        tmp = 1;
    }
    return tmp;
}

int ToolBoxClass::ZahlenBerechnen(int posa, RANGE range, string wahl)
{
    int tmp;
    if (wahl.compare("+") == 0){
        posa++;
    }else if (wahl.compare("-") == 0){
        posa--;
    }

    if (posa >= range.min && posa <= range.max){
        tmp = ((posa - range.min) + range.min);
    }else if (posa >= range.min && posa > range.max){
        tmp = (posa - range.max);// + range.min;
        while(tmp > range.max){
            tmp = (tmp - range.max);// + range.min;
        }
    }else if (posa < range.min && posa <= range.max){
        tmp = range.max + posa;
        while(tmp < range.min){
            if(tmp == 0){tmp = range.max;}
            else{tmp = range.max + tmp;}
        }
    }else if (posa == 0){
        tmp = range.max;
    }else{tmp = posa;}

    return tmp;
}

int ToolBoxClass::ZahlenWerk(int mina, int posa, int maxa, string wahl){
    vector<RANGE> list;
    int included;
    RANGE range;

    range.min = mina;
    range.max = maxa;
    range.count();
    range.range = 1;
    list.push_back(range);

    do {
        included = ToolBoxClass::ZahlenBerechnen(posa, range, wahl);
    }while (included > range.max);
    return included;
}

WINDOW *ToolBoxClass::ClearWindow(WINDOW *TEMPWINDOW) {
    clearok(TEMPWINDOW,true);
    return TEMPWINDOW;
}

void ToolBoxClass::ClearScreen() {
    if (!cur_term) {
        int result;
        setupterm( nullptr, STDOUT_FILENO, &result );
        if (result <= 0) return;
    }
    putp(tigetstr("clear"));
}

NO_RETURN void ToolBoxClass::TermQuit(int sig) {
    UNUSED(sig);
    FileFolderClass::ConfigDateiList.clear();
    vector<string>().swap(FileFolderClass::ConfigDateiList);
    ToolBoxClass::DeletAllWin("Ende");
    clear();
    raise(SIGTERM);
    exit(EXIT_SUCCESS);
}

void ToolBoxClass::DeletAllWin(const char *name) {
    try {
        if (strcmp(name,"Ende")==0){
            if (WinClass::START.TMPWin1){
                werase(WinClass::START.TMPWin1);
                delwin(WinClass::START.TMPWin1);
                endwin();
            }
            if (WinClass::START.TMPWin1){
                werase(WinClass::START.TMPWin2);
                delwin(WinClass::START.TMPWin2);
                endwin();
            }
            if (WinClass::START.TMPWin1){
                werase(WinClass::START.TMPWin3);
                delwin(WinClass::START.TMPWin3);
                endwin();
            }
            endwin();
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

ToolBoxClass::ToolBoxClass() {

}
