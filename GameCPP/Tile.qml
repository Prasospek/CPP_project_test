import QtQuick

Rectangle {
    property int tileIndex: 0

    id: tile
    width: 50
    height: 50

    Image{
        anchors.fill: parent
        source: maper.tiles[tileIndex].texture

        Text {
        color: "white";
        text: maper.tiles[tileIndex].isWall ? "true" : "false"
        }
    }
}
