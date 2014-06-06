#include "fileio.h"
#include <QFile>
#include <QTextStream>

QByteArray FileIO::read(const QString &filename)
{
QFile file(filename);
if (!file.open(QIODevice::ReadOnly))
    return QByteArray();

return file.readAll();
}

bool FileIO::write(const QString& data)
{
if (mSource.isEmpty())
    return false;

QFile file(mSource);
if (!file.open(QFile::WriteOnly | QFile::Truncate))
    return false;

QTextStream out(&file);
out << data;

file.close();

return true;
}
