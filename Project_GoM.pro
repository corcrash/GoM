TEMPLATE = app
CONFIG += console
CONFIG -= qt

LIBS += -lSDL -lSDL_image

SOURCES += main.cpp \
    freckle/csurface.cpp \
    freckle/cevent.cpp \
    freckle/centity.cpp \
    freckle/capp_onrender.cpp \
    freckle/capp_onloop.cpp \
    freckle/capp_oninit.cpp \
    freckle/capp_onevent.cpp \
    freckle/capp_oncleanup.cpp \
    freckle/capp.cpp \
    freckle/canimation.cpp

HEADERS += \
    freckle/csurface.h \
    freckle/cevent.h \
    freckle/centity.h \
    freckle/capp.h \
    freckle/canimation.h

