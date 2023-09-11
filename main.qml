import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15



Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Home Hub")


    Rectangle{
        id: app_
        color: "#87CEEB"
        anchors.fill: parent

        Column{
            id: main
            spacing: 10

            Row{
                id: set_bus_stop_row
                spacing: 10

                TextField {
                                id: cityInput
                                placeholderText: "Enter Home City"
                                width: 200
                                color: "black"
                                onAccepted: {
                                    // Handle city input here, e.g., save it to a variable or database
                                    var homeCity = cityInput.text;
                                    console.log("Home City: " + homeCity);
                                }
                            }

                TextField {
                              id: busStopInput
                              placeholderText: "Enter Bus Stop"
                              width: 200
                              color: "black"
                              onAccepted: {
                                  // Handle bus stop input here, e.g., save it to a variable or database
                                  var busStop = busStopInput.text;
                                  console.log("Bus Stop: " + busStop);
                              }
                          }

                Rectangle {
                               id: customButton
                               width: 60
                               height: 20
                               color: "#3498db"
                               radius: 5

                               Text {
                                   anchors.centerIn: parent
                                   text: "Save"
                                   color: "#ffffff"
                               }

                               MouseArea {
                                   id: buttonArea
                                   anchors.fill: parent

                                   onClicked: {
                                       // Handle saving data to your application
                                       var homeCity = cityInput.text;
                                       var busStop = busStopInput.text;
                                       console.log("Home City: " + homeCity);
                                       console.log("Bus Stop: " + busStop);

                                       nysse_wrap.fetchData(busStop);
                                   }

                                   onPressed: {
                                       // Scale the button on press
                                       customButton.scale = 0.9;
                                   }

                                   onReleased: {
                                       // Reset the button size on release
                                       customButton.scale = 1.0;
                                   }
                               }
                }
            }
        }

    }

    }

