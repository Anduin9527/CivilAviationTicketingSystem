QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Date.cpp \
    Flight.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    userwindow.cpp

HEADERS += \
    Crasa.h \
    Date.h \
    Flight.h \
    Sort.h \
    login.h \
    mainwindow.h \
    userwindow.h

FORMS += \
    login.ui \
    mainwindow.ui \
    userwindow.ui

TRANSLATIONS += \
    NJUPTClassDesign_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
