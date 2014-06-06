TEMPLATE = lib
CONFIG += plugin
QT += qml quick

DESTDIR = FileIO
TARGET = fileioplugin

HEADERS += fileio.h fileioplugin.h
SOURCES += fileio.cpp fileioplugin.cpp

lib.files = FileIO
lib.path = $$[QT_INSTALL_QML]

INSTALLS += lib
