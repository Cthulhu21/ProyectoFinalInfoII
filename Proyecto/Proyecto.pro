QT = core gui
QT += widgets
CONFIG += c++20 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Arma.cpp \
        Juego.cpp \
        Jugador.cpp \
        Mapa.cpp \
        ObjetoEstatico.cpp \
        ObjetoMovible.cpp \
        Plataforma.cpp \
        ZonaGravitacional.cpp \
        ZonaRadial.cpp \
        ZonaRecta.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Arma.h \
    Juego.h \
    Jugador.h \
    Mapa.h \
    ObjetoEstatico.h \
    ObjetoMovible.h \
    Plataforma.h \
    ZonaGravitacional.h \
    ZonaRadial.h \
    ZonaRecta.h

RESOURCES += \
    Recursos.qrc
