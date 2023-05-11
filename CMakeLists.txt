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