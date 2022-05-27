import QtQuick 2.1
import QtQuick.Window 2.0
import QtLocation 5.6
import QtPositioning 5.6

Rectangle {
   anchors.fill: parent

   Plugin {
      id: mapboxglPlugin
      name: "mapboxgl"
   }

   Map {
      anchors.fill: parent
      plugin: mapboxglPlugin
      //center: QtPositioning.coordinate(59.91, 10.75) // Oslo
      center: QtPositioning.coordinate(38.335253, -121.091880)
      zoomLevel: 16.4
   }
}
