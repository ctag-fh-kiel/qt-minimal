## About

Minimal Qt5 application for Windows using MSYS2 MinGW x64 toolchain.

## Build & Run

- Download MSYS2 https://www.msys2.org/
- Start MSYS2 MinGW x64 shell
- Install toolchain and dependencies
  - pacman -Su git mingw-w64-x86_64-toolchain mingw-w64-x86_64-cmake mingw-w64-x86_64-qt5
- Build with
  - mkdir build
  - cd build
  - cmake -G "MinGW Makefiles" ..
  - mingw32-make
- Run with
  - ./QtTest.exe

## Create installer / deployment
- Install deployment dependencies / nsis installer
  - pacman -Su mingw-w64-nsis
- Build and create installer with
  - mkdir build
  - cd build
  - cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release ..
  - mingw32-make
  - cpack -C Release