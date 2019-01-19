#-------------------------------------------------
#
# Project created by QtCreator 2019-01-19T01:29:27
#
#-------------------------------------------------

QT       += core gui webkit webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test_web_view
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += HTML_SOURCE_PATH=\\\"$$PWD\\\"

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwidget.cpp \
    testjsobject.cpp

HEADERS += \
        mainwidget.h \
    testjsobject.h

FORMS += \
        mainwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    test_page.htm \
    example.htm
