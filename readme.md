## Steps

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
- Deployment tools
  - pacman -Su mingw-w64-nsis