import QtQuick 2.7
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0

Window {
	id: root
	visible: true
	width: 640
	height: 480
	title: qsTr("QMLMiner")

	property int rows: 9
	property int cols: 9
<<<<<<< HEAD
	color: "#FFF0F0F0"
=======
	color: "#F0F0F0"
>>>>>>> miner_branch




	Item {
		id: drawItem
		property bool hor: parent.width > parent.height
		width: hor ? parent.height : parent.width
		height: hor ? parent.height : parent.width
		anchors.centerIn: parent

		DropShadow {
			anchors.fill: blockContainer

			horizontalOffset: 0
			verticalOffset: 2
			radius: 8.0
			samples: 17
			color: "#60000000"
			source: blockContainer
		}

		Grid {
			id: staffContainer
			anchors.margins: 16
			anchors.fill: parent
			columns: root.cols
			rows: root.rows
			opacity: 0.5
			Repeater {
				model: root.rows * root.cols
				Item {
					width: staffContainer.width / root.cols
					height: width
					property bool hided: true
					Text {
						anchors.centerIn: parent
						font.pixelSize: parent.height * 0.7
						text: Math.round(Math.random()*3)
						visible: text != "0"
						color: {
							switch (text) {
								case "1": return "blue"
								case "2": return "green"
								case "3": return "red"
								case "4": return "darkblue"
								case "5": return "darkred"
								case "6": return "red"
								case "7": return "red"
								case "8": return "red"
							}
							return "black"
						}
					}
				}
			}
		}
		Grid {
			id: blockContainer
			anchors.margins: 16
			anchors.fill: parent
			columns: root.cols
			rows: root.rows
			Repeater {
				model: root.rows * root.cols
				Item {
					id: block
					width: blockContainer.width / root.cols
					height: width
					property bool hided: true

					Rectangle {
						visible: scl
						anchors.centerIn: parent
						property real scl: block.hided ? (mA.containsMouse ? 0.8 : 0.9) : 0
						Behavior on scl {NumberAnimation{duration: 100}}
						width: parent.width * scl
						height: parent.height * scl
						radius: 2
					}
					MouseArea {
						id: mA
						anchors.fill: parent
						hoverEnabled: true
						onClicked: block.hided = false
					}
				}
			}
		}
	}
}
