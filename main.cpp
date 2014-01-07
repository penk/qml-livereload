#include <QtGui/QGuiApplication>
#include <QFileSystemWatcher>
#include <QtQuick/QQuickView>
#include <QDebug>
#include <QQmlEngine>
#include <QThread>

class LiveReload: public QGuiApplication {
    Q_OBJECT
public:
    LiveReload(int argc, char* argv[]);
    QQuickView view;
    QFileSystemWatcher watcher;
private slots:
    void fileChanged(const QString & path) {
        qDebug() << "file changed: " << path;
        view.engine()->clearComponentCache();
        QThread::msleep(50);
        view.setSource(QUrl("./main.qml"));
        view.show();
    };
};

LiveReload::LiveReload(int argc, char* argv[]): 
  QGuiApplication(argc,argv) {
    watcher.addPath("./");
    watcher.addPath("./main.qml");
    connect(&watcher, SIGNAL(directoryChanged(const QString &)), 
      this, SLOT(fileChanged(const QString &)));
    connect(&watcher, SIGNAL(fileChanged(const QString &)), 
      this, SLOT(fileChanged(const QString &)));
    view.setSource(QUrl("./main.qml"));
    view.show();
}

int main(int argc, char* argv[]) {
    LiveReload app(argc,argv);
    return app.exec();
}

#include "main.moc"
