TEMPLATE = app
TARGET = /usr/local/bin/qmllive
SOURCES += main.cpp

QT += qml quick
mac: {
    CONFIG -= app_bundle
}
