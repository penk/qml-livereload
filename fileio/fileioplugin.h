#ifndef FILEIOPLUGIN_H
#define FILEIOPLUGIN_H

#include <QQmlExtensionPlugin>

class FileIOPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "io.github.penk.FileIO")

public:
    void registerTypes(const char *uri);
};

#endif // FILEIOPLUGIN_H
