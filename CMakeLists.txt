cmake_minimum_required(VERSION 3.21)
project(QTStarter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Core Gui Widgets Network REQUIRED)

add_subdirectory(dishlib)

file(GLOB QT_WRAP *.h)
file(GLOB CPP_FILES *.cpp)

add_executable(QTStarter ${CPP_FILES} ${QT_WRAP})

target_link_libraries(QTStarter dishlib Qt5::Core Qt5::Gui Qt5::Network Qt5::Widgets)

# Set NSIS as the generator
set(CPACK_GENERATOR NSIS)

# Set package information
set(CPACK_PACKAGE_NAME "QTStarter")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_VENDOR "PIC-Software")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "QTStarter - QT Demo Application")
set(CPACK_PACKAGE_EXECUTABLES "QTStarter" "QTStarter")

# Set NSIS-specific variables
set(CPACK_NSIS_PACKAGE_NAME "QTStarter")
set(CPACK_NSIS_DISPLAY_NAME "QTStarter")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")

# Set NSIS start menu shortcut
set(CPACK_NSIS_MENU_LINKS "QTStarter.exe" "QTStarter")

# Add CPack module
include(CPack)