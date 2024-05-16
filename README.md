# OpenCV C++ Setup, Build, and Run Using VS Code and Cmake
Credits</br>
WalkWithMe https://youtu.be/MAoQqhcKKAo</br>
&nbsp;&nbsp;- opencv undistort code</br>
Kevin Wood https://youtu.be/CnXUTG9XYGI</br>
&nbsp;&nbsp;- how to run opencv with visual studio code

## Install CMake
Go to the cmake website (https://cmake.org/download/) and downlad `cmake-3.28.1-windows-x86_64.msi` for the `Windows x64 Installer`.

## Install OpenCV
Download OpenCV release from the opencv website (https://opencv.org/releases/). Under `OpenCV - 4.8.0`, click on the `Windows` button, and run the exe isntall. Specify path to save (i.e. `C:\opt`)

## Install Boost
Download latest from https://www.boost.org/.
Follow the build+install guide (https://www.boost.org/doc/libs/1_85_0/more/getting_started/windows.html).

Especially step `5 Prepare to Use a Boost Library Binary` and `5.1 Simplified Build From Source`

Open CMakeLists.txt and update this line to point to your boost install root directory
```
set(BOOST_ROOT "C:/Program Files/boost/boost_1_85_0")
```

## Setup Environment Variables
Create a new environment variable (Windows > Edit the system environment variables). Restart VS Code to take effect if already open. This step is required when we call `find_package(OpenCV REQUIRED)` in the `CMakeList.txt` file as we will see later.
```
Variable: `OpenCV_DIR`
Value:`C:\opt\opencv\build`
```
Add the following paths to your environment variables (Windows -> Edit the system environment variables). This is to find the bin and lib folders.
```bash
C:\Program Files\CMake\bin
C:\opt\opencv\build\x64\vc16\bin
C:\opt\opencv\build\x64\vc16\lib
```

## CMakeList.txt
Add your `CMakeLists.txt` file to your project.

## Simple OpenCV Program
Create your main.cpp program.

## Configure Step
Configure the build
```bash
mkdir build
cmake -B .\build\
```

## Build in Debug
Build and Run Exe in Debug
```bash
cmake --build .\build\
.\build\Debug\OpenCVExample.exe
```

## Build in Release
Build and Run Exe in Debug
```bash
cmake --build .\build\ --config Release
.\build\Release\OpenCVExample.exe
```

## Modify Program and Rebuild
If you make any changes to your main.cpp file, you just need to re-run the build step and not the configure step.
```bash
cmake --build .\build\
.\build\Debug\OpenCVExample.exe
```

## Usage
Drag and drop your raw video file onto the exe
&nbsp;&nbsp;- Requires a `Result` folder in the same directory as the exe