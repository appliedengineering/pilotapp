cmake_minimum_required(VERSION 3.5)

project(pilotapp LANGUAGES CXX)

# Only needed for MSVC/VS code and not Qt Creator
# set(CMAKE_PREFIX_PATH "O:\\Qt\\5.15.2\\msvc2019_64")
set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/qt@5/5.15.2_1")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(EXECUTABLE_OUTPUT_PATH "bin")


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

if(ANDROID)
  add_library(pilotapp SHARED
    main.cpp
    home.cpp
    home.h
  )
else()
  add_executable(pilotapp
    "Source/main.cpp"
    "Source/MainWindow.cpp"
    "Source/MainWindow.h"
    "Source/Widgets/Pages/Home/homePage.cpp"
    "Source/Widgets/Pages/Home/homePage.h"
    "Source/Utilities/utilities.cpp"
    "Source/Utilities/utilities.h")

  add_custom_command( # copies style.qss to bin folder
    TARGET pilotapp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/Source/style.qss
            ${CMAKE_CURRENT_BINARY_DIR}/bin/style.qss)

  add_custom_command( # copies assets folder to bin folder
    TARGET pilotapp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/Assets
            ${CMAKE_CURRENT_BINARY_DIR}/bin/Assets)


endif()

target_link_libraries(pilotapp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
