#include <QtGui/QGuiApplication>
#include <QFileSystemWatcher>
#include <QtQuick/QQuickView>
#include <QDebug>
#include <QQmlEngine>
#include <QThread>
#include <QFileInfo>
#include <QQmlApplicationEngine>

class LiveReload: public QGuiApplication {
	Q_OBJECT
public:
	LiveReload(int argc, char* argv[]);
	QFileSystemWatcher watcher;

//	QQuickView view;

	QQmlApplicationEngine engine;

private:
	QString filename;
	void show(){
		qobject_cast<QQuickWindow *>(engine.rootObjects().value(0))->show();
	}

private slots:
	void fileChanged(const QString & path) {
		qDebug() << "file changed: " << path;

//        view.engine()->clearComponentCache();
//        QThread::msleep(50);
//		view.setSource(QUrl(filename));
//        view.show();

		engine.clearComponentCache();
		QThread::msleep(50);
		engine.load(QUrl::fromLocalFile(filename));
		show();
	};
};

LiveReload::LiveReload(int argc, char* argv[]):
  QGuiApplication(argc,argv) {

	filename = "./main.qml";
	if (argc>1) filename = argv[1];
	QFileInfo file(filename);
	if (!file.exists()) qFatal("File not found.");
	setApplicationName("Livereload:"+file.baseName());
	watcher.addPath(file.absolutePath());
	watcher.addPath(filename);
	connect(&watcher, SIGNAL(directoryChanged(const QString &)),
	  this, SLOT(fileChanged(const QString &)));
	connect(&watcher, SIGNAL(fileChanged(const QString &)),
	  this, SLOT(fileChanged(const QString &)));

//	view.setSource(QUrl(filename));
//	view.show();

	engine.load(QUrl::fromLocalFile(filename));
	show();
}

int main(int argc, char* argv[]) {
	LiveReload app(argc,argv);
	return app.exec();
}

#include "main.moc"
