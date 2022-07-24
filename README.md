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

- [Git](https://git-scm.com/downloads)

- [Github Desktop](https://desktop.github.com/) 




## Pre-Setup Instructions




### Qt SDK Options




![image](https://user-images.githubusercontent.com/77907654/180627100-e91bf413-128a-4d33-a34f-a3e352bcf824.png)

![image](https://user-images.githubusercontent.com/77907654/180627116-20b05471-68d5-45de-8498-da5103262053.png)







### Visual Studio Installation Options

Check `Desktop Development with C++` with these options.

***Do NOT check SDK 10.0.19041.0 due to a bug***




![image](https://user-images.githubusercontent.com/77907654/180627121-6a3ef022-6010-4a4f-855d-4ff16d0a6355.png)







### Visual Studio Build Tools Installation Options

Check `Desktop Development with C++` with these options.




![image](https://user-images.githubusercontent.com/77907654/180627126-96670f5c-65cb-46ec-9574-75ff407a041f.png)




## Environment Variables

Make sure you have the correct paths to VScode bin, CMake bin, and your compiler's bin (MinGW for example). 

In Windows Search bar, type edit the system environment windows -> open it -> Click "Path" and click edit -> add bin paths.

More information in the video below.




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
