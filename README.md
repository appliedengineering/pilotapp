# pilotapp
 Embedded app for pilot to interact with boat electrical systems - runs on a RPi 4 + touchscreen.

# Setup Instructions

## Links for download (if you don't have these already):
- [QT-Open Source](https://www.qt.io/download-open-source?hsCtaTracking=9f6a2170-a938-42df-a8e2-a9f0b1d6cdce%7C6cb0de4f-9bb5-4778-ab02-bfb62735f3e5)
- [ZMQ](https://github.com/zeromq/libzmq)
- [QGeoView](https://github.com/AmonRaNet/QGeoView)
- [MSGPack (C++)](https://github.com/msgpack/msgpack-c/tree/cpp_master)
- [Visual Studio Community](https://visualstudio.microsoft.com/downloads/)
- [Visual Studio Build Tools](https://visualstudio.microsoft.com/downloads/) (Scoll down to All Downloads->Tools For Visual Studio->Build Tools)
- [Visual Studio Code](https://code.visualstudio.com/download)
- [Boost](https://www.boost.org/users/download/)
- [CMake](https://cmake.org/download/) (binary, either of the x64 if on Windows)

## Pre-Setup Instructions

### Qt SDK Options

[insert image]

### Visual Studio Installation Options
Check `Desktop Development with C++` with these options.
***Do NOT check SDK 10.0.19041.0 due to a bug***

[insert image]

### Visual Studio Build Tools Installation Options
Check `Desktop Development with C++` with these options.

[insert image]

## Environment Variables
Make sure you have the correct paths to VScode bin, CMake bin, and your compiler's bin (MinGW for example). More information in the video below.

### VScode extensions
- CMake Tools
- C/C++
- CMake
- CMake Language Support

## [Windows 11/10 Setup](https://youtu.be/8bXEM16MvEQ)

In the video you will see paths being modified in CMakeLists.txt. Use these in c_cpp_properties.json as well.
Your `settings.json` should look like this. Use Visual Studio as your generator; MinGW Makefiles should be a fallback in case if you have it installed.
```json
{
    "cmake.configureOnOpen": true,
    "cmake.sourceDirectory": "${workspaceFolder}/pilotapp",
    "cmake.cmakePath": "C:/CMake/bin/cmake",
    "cmake.generator": "Visual Studio 17 2022"
}
```

For a reference `settings.json`, you can visit this [gist](https://gist.github.com/richardwei6/95667e3b3287590bc7874ccd1745cff1).
