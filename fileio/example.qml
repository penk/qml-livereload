import QtQuick 2.0
import FileIO 1.0

Item {
    width: 300
    height: 300

    MouseArea {
        anchors.fill: parent
        Text { 
            id: text; 
            anchors { centerIn: parent }
            text: "Click me to write file" 
        }
        onClicked: { file.write("text content\n"); text.text = "File saved to tmp.txt" }
    }

    FileIO {
        id: file
        Component.onCompleted: file.setSource('tmp.txt');
    }
}
