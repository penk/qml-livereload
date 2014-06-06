QML Playgrounds
===============

![playgrounds](http://i.imgur.com/bUyvDQU.png)

### Reload-as-you-type QML editor and live preview 

1. Install QML [HttpServer](https://github.com/rschroll/qhttpserver) plugin, see [more details](http://rschroll.github.io/beru/2013/08/16/a-http-server-in-qml.html)
2. Start the editor by: `qmlscene playgrounds.qml` 

QML Playgrounds monitors changes in its `TextEdit`, and trigger the view to reload source from the local http server. If you're looking for a file system watcher implementation, please refer to QML LiveReload. 

QML LiveReload
==============

![screencast](https://raw.github.com/penk/qml-livereload/master/screencast.gif)

### Simple QtQuick app live viewer

Put your `main.qml` file under the same directory of `livereload`, and starts `./livereload &`
