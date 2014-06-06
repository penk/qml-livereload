#ifndef FILEIO_H
#define FILEIO_H

#include <QObject>

class FileIO: public QObject
{
    Q_OBJECT

public:
    Q_INVOKABLE QByteArray read(const QString &filename);
    Q_INVOKABLE bool write(const QString &filename);
    QString source() { return mSource; };

public slots:
      void setSource(const QString& source) { mSource = source; };
private:
        QString mSource;
};

#endif // FILEIO_H
