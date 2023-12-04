import QtQuick

Rectangle {
property int gridSpacing
property bool playerFocus
id: playerRect
width: 50
height: 50
color: "transparent"
x: (player.x % 10) * 50
y: (player.y % 10) * 50 //TODO: fix TypeError: Cannot read property

Image{
    anchors.fill: parent
    source: "images/player.png"
}

FocusScope {
    anchors.fill: parent
    focus: playerRect.playerFocus


    Timer {
        id: movementTimer
        interval: 200
        onTriggered: {
            movementTimer.stop();
            //handlePlayerMovement();
        }
    }


    Keys.onPressed: (event)=> {
        if (!movementTimer.running) {
            if (event.key === Qt.Key_A) {
                player.setPosition(player.x - 1, player.y);
            } else if (event.key === Qt.Key_D) {
                player.setPosition(player.x + 1, player.y);
            } else if (event.key === Qt.Key_W) {
                player.setPosition(player.x, player.y - 1);
            } else if (event.key === Qt.Key_S) {
                player.setPosition(player.x, player.y + 1);
            }
            movementTimer.start();
        }
    }
}
}
