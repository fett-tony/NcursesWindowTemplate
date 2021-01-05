TEMPLATE = app
CONFIG += console c++11 gnu++11
CONFIG -= app_bundle
CONFIG -= qt

unix:!macx: LIBS += -lncurses++w -Wall -lncursesw -lmenuw -lmenu -lformw -lpanelw -pthread

SOURCES += \
    TOOL.BOX.CLASS.cpp \
    WIN.CLASS.cpp \
    MENU.CLASS.cpp \
    FILE.FOLDER.CLASS.cpp

HEADERS += \
    WIN.CLASS.h \
    TOOL.BOX.CLASS.h \
    MENU.CLASS.h \
    FILE.FOLDER.CLASS.h
