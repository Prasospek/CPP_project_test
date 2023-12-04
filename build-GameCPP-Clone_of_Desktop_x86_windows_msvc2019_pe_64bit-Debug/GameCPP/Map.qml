import QtQuick


    Grid {
        id: map
        anchors.centerIn: parent
        columns: 10
        rows: 10
        spacing: 0
        property int gridSpacing: spacing

        Repeater {
            model: maper.tiles
            Tile {
                tileIndex: index;
            }
        }
    }

