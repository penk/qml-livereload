TEMPLATE = app
TARGET = livereload
SOURCES += main.cpp

QT += quick
mac: {
    CONFIG -= app_bundle
}
