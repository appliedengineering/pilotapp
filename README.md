# pilotapp
 Embedded app for pilot to interact with boat electrical systems - runs on a RPi 4 + touchscreen

Links for download (if you don't have these already):
*QT-Open Source: https://www.qt.io/download-open-source?hsCtaTracking=9f6a2170-a938-42df-a8e2-a9f0b1d6cdce%7C6cb0de4f-9bb5-4778-ab02-bfb62735f3e5
*ZMQ: https://github.com/zeromq/libzmq
*QGeoView: https://github.com/AmonRaNet/QGeoView
*MSGPack (C++): https://github.com/msgpack/msgpack-c/tree/cpp_master
*Visual Studio Community: https://visualstudio.microsoft.com/downloads/
*Visual Studio Build Tools: https://visualstudio.microsoft.com/downloads/; Scoll down to All Downloads->Tools For Visual Studio->Build Tools
*Visual Studio Code: https://code.visualstudio.com/download
*Boost: https://www.boost.org/users/download/
*CMake: https://cmake.org/download/ (binary, either of the x64 if on Windows)

For the github links, press Code -> Download ZIP -> right click folder to extract all
Windows video setup: https://youtu.be/8bXEM16MvEQ

However, before you watch the video, you must set up some of the larger software.
For Qt, check these options

For Visual Studio Community, check Desktop development with C++, then these options

Note: Do NOT check SDK 10.0.19041.0 as you are potentially subject to a very frustrating bug

For Visual Studio Build Tools, check Desktop development with C++, then these options

For environment variables, make sure you have paths to VScode bin, CMake bin, and your compiler's bin (MinGW for example)

VScode extensions: CMake Tools, C/C++, CMake, CMake Language Support

In the video you will see paths being modified in CMakeLists.txt. Use these in c_cpp_properties.json as well.
Your settings.json should look like this. Use Visual Studio 17 2022 as your generator; MinGW Makefiles should be a fallback in case.
```json
{
    "cmake.configureOnOpen": true,
    "cmake.sourceDirectory": "${workspaceFolder}/pilotapp",
    "cmake.cmakePath": "C:/CMake/bin/cmake",
    "cmake.generator": "Visual Studio 17 2022"
}
```