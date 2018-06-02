import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: root

    x: 0
    y: 0
    width: 320
    height: 240
   
    footer: TabBar {
        id: tabBar
        
        TabButton {
            text: qsTr("First")
        }
        TabButton {
            text: qsTr("Second")
        }
    }
}