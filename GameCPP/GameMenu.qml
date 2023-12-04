import QtQuick
import QtQuick.Controls

Rectangle {
    id: gameMenu
    color: "grey"
    width: 400
    height: 250
    border.color: "#333333"
    border.width: 2
    radius: 10
    visible: true
    anchors.centerIn: parent

    Text {
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            topMargin: 50
        }
        text: "GAME MENU"
        font.pixelSize: 24
        color: "#333333"
    }

    Row {
        spacing: 10
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            topMargin: 120
        }

        Button {
            text: "Start Game"
            width: 150
            height: 50
            onClicked: {
                gameMenu.visible = false
                pl.playerFocus = true
            }
        }

        Button {
            text: "Close Game"
            width: 150
            height: 50
            onClicked: {
                Qt.quit()
            }
        }
    }
}

