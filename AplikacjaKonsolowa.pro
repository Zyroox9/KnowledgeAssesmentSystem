QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle
QT += sql

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        cconskill.cpp \
        cdatabase.cpp \
        cmainskill.cpp \
        cmanage.cpp \
        creport.cpp \
        cskill.cpp \
        cskilltree.cpp \
        cstudent.cpp \
        csubskill.cpp \
        ctest.cpp \
        ctester.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    cconskill.h \
    cdatabase.h \
    cmainskill.h \
    cmanage.h \
    creport.h \
    cskill.h \
    cskilltree.h \
    cstudent.h \
    csubskill.h \
    ctest.h \
    ctester.h \
    squestion.h
