TEMPLATE = app
TARGET = qmllive
SOURCES += main.cpp

QT += quick
mac: {
    CONFIG -= app_bundle
}
