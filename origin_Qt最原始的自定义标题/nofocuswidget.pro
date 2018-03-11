QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = nofocuswidget
TEMPLATE = app


SOURCES += \
    basewindow.cpp \
   # customtitle.cpp \
    main.cpp \
    mytitlebar.cpp \
    nofocuswidget.cpp

HEADERS  += \
    basewindow.h \
   # customtitle.h \
    mytitlebar.h \
    nofocuswidget.h

FORMS    += \
    #customtitle.ui \
    nofocuswidget.ui

RESOURCES += \
    customtitle.qrc
