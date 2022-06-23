import QtQuick 2.7
import QtQuick.VirtualKeyboard 2.1

Rectangle {
    id: window
    width: 800
    height: 0

    InputPanel {
        id: inputPanel
        width: window.width

        states: State {
            name: "visible"
            when: inputPanel.active
            PropertyChanges {
                target: window
                height: inputPanel.height
            }
        }
        transitions: Transition {
            from: ""
            to: "visible"
            reversible: true
            ParallelAnimation {
                NumberAnimation {
                    properties: "y"
                    duration: 250
                    easing.type: Easing.InOutQuad
                }
            }
        }
    }
}