import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window{
    visible: true
    width: 500
    height: 500
    title: "Game"
    color: "gray"

    Map {
        id:map

        Player{
            id: pl
            gridSpacing: map.spacing
            playerFocus: false
        }

    }

    GameMenu {

    }

}
