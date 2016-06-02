TEMPLATE = app
TARGET = qmllive
SOURCES += main.cpp

QT += qml quick
mac: {
    CONFIG -= app_bundle
}
