cmake_minimum_required(VERSION 3.9)

project(pilotapp LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(EXECUTABLE_OUTPUT_PATH "bin")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

##

include("${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.config.txt")

##

message("Configuring...")
message("Binary DIR = ${CMAKE_BINARY_DIR}")
message("Source DIR = ${CMAKE_SOURCE_DIR}")

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Multimedia REQUIRED)
find_package(msgpack REQUIRED)
#find_package(PkgConfig REQUIRED)

if(ANDROID)
  add_library(pilotapp SHARED
  #  main.cpp
  #  home.cpp
  #  home.h
  )
else()
  add_executable(pilotapp
    "Source/main.cpp"
    "Source/MainWindow.cpp"
    "Source/MainWindow.h"
    "Source/Widgets/Pages/Home/homePage.cpp"
    "Source/Widgets/Pages/Home/homePage.h"
    "Source/Backend/Utilities/utilities.cpp"
    "Source/Backend/Utilities/utilities.h"
    "Source/Backend/Display Control/displayControlEventFilter.cpp"
    "Source/Backend/Display Control/displayControlEventFilter.h"
    "Source/Backend/Communication/communicationManager.cpp"
    "Source/Backend/Communication/communicationManager.h"
    "Source/Backend/Communication/communicationThread.cpp"
    "Source/Backend/Communication/communicationThread.h"
    "Source/Backend/Communication/dataManager.cpp"
    "Source/Backend/Communication/dataManager.h"
    "Source/Backend/Boat Kernel/boatKernel.cpp"
    "Source/Backend/Boat Kernel/boatKernel.h"
    "Source/Backend/Preferences/preferencesManager.cpp"
    "Source/Backend/Preferences/preferencesManager.h"
    "Source/Backend/logManager.cpp"
    "Source/Backend/logManager.h"
    "Source/Widgets/Widgets/Toolbar/toolbar.cpp"
    "Source/Widgets/Widgets/Toolbar/toolbar.h"
    "Source/Widgets/Widgets/LeftContentSlate/leftContentSlate.cpp"
    "Source/Widgets/Widgets/LeftContentSlate/leftContentSlate.h"
    "Source/Widgets/Widgets/MainContentSlate/mainContentSlate.cpp"
    "Source/Widgets/Widgets/MainContentSlate/mainContentSlate.h"
    "Source/Widgets/Widgets/MainContentSlate/contentWidget.cpp"
    "Source/Widgets/Widgets/MainContentSlate/contentWidget.h"
    "Source/Widgets/Widgets/MainContentSlate/ContentWidgets/Map/mapWidget.cpp"
    "Source/Widgets/Widgets/MainContentSlate/ContentWidgets/Map/mapWidget.h"
    "Source/Widgets/Widgets/MainContentSlate/ContentWidgets/Power/powerWidget.cpp"
    "Source/Widgets/Widgets/MainContentSlate/ContentWidgets/Power/powerWidget.h"
    "Source/Widgets/Widgets/MainContentSlate/ContentWidgets/Screen/screenWidget.cpp"
    "Source/Widgets/Widgets/MainContentSlate/ContentWidgets/Screen/screenWidget.h"
    "Source/Widgets/Widgets/MainContentSlate/ContentWidgets/Settings/settingsWidget.cpp"
    "Source/Widgets/Widgets/MainContentSlate/ContentWidgets/Settings/settingsWidget.h"
    "Source/Widgets/Widgets/MainContentSlate/ContentWidgets/Settings/SettingsContentWidgets/Options/settingsOptionsWidget.cpp"
    "Source/Widgets/Widgets/MainContentSlate/ContentWidgets/Settings/SettingsContentWidgets/Options/settingsOptionsWidget.h"
    "Source/Widgets/Widgets/MainContentSlate/ContentWidgets/Settings/SettingsContentWidgets/Logs/settingsLogsWidget.cpp"
    "Source/Widgets/Widgets/MainContentSlate/ContentWidgets/Settings/SettingsContentWidgets/Logs/settingsLogsWidget.h"
    "Source/Widgets/Widgets/MainContentSlate/ContentWidgets/Telemetry/telemetryWidget.cpp"
    "Source/Widgets/Widgets/MainContentSlate/ContentWidgets/Telemetry/telemetryWidget.h"
    "Source/Widgets/Widgets/MainContentSlate/ContentWidgets/Map/mapSettingsWidget.cpp"
    "Source/Widgets/Widgets/MainContentSlate/ContentWidgets/Map/mapSettingsWidget.h"
    "Source/Custom/RangeSlider/RangeSlider.cpp"
    "Source/Custom/RangeSlider/RangeSlider.h"
    "Source/Custom/TouchKeypad/touchKeypad.cpp"
    "Source/Custom/TouchKeypad/touchKeypad.h"
    "Source/Custom/TouchInputWidgets/TouchNumericalLineEdit/touchNumericalLineEdit.cpp"
    "Source/Custom/TouchInputWidgets/TouchNumericalLineEdit/touchNumericalLineEdit.h"
    "resources.qrc")

 # add_custom_command( # copies style.qss to bin folder
 #   TARGET pilotapp POST_BUILD
 #   COMMAND ${CMAKE_COMMAND} -E copy
 #           ${CMAKE_SOURCE_DIR}/Source/style.qss
 #           ${CMAKE_CURRENT_BINARY_DIR}/bin/style.qss)

 # add_custom_command( # copies assets folder to bin folder
 #   TARGET pilotapp POST_BUILD
 #   COMMAND ${CMAKE_COMMAND} -E copy
 #           ${CMAKE_SOURCE_DIR}/Assets
 #           ${CMAKE_CURRENT_BINARY_DIR}/bin/Assets)

# Copy required ArcGIS dynamic libraries to the build folder as a post-build step.
#message("Copy ArcGIS Runtime libs")
#add_custom_command(TARGET pilotapp POST_BUILD
#  COMMAND ${CMAKE_COMMAND} -E copy_if_different
#  ${ArcGISRuntime_LIBRARIES}
#  "${PROJECT_BINARY_DIR}/bin")

endif()

target_link_libraries(pilotapp PRIVATE 
  Qt${QT_VERSION_MAJOR}::Widgets 
  Qt${QT_VERSION_MAJOR}::Multimedia
  zmq
  msgpackc-cxx
  QGeoView
  )

