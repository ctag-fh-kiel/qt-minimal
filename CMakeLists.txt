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

# create install target
install(TARGETS QTStarter DESTINATION bin)

# add all mingw64 system dlls to install target
# this is overkill, but collecting only the needed dlls is a pain
set(MINGW_ROOT "c:/msys64/mingw64")
# install all dlls except those which start with Qt5
install(DIRECTORY ${MINGW_ROOT}/bin/ DESTINATION bin
        FILES_MATCHING
        PATTERN "*.dll"
        PATTERN "Qt5*" EXCLUDE)

# add all qt dlls to install target
include(cmake/WinDeployQt.cmake)
windeployqt(QTStarter "bin")

# make deployment using cpack and nsis
set(CPACK_GENERATOR "NSIS")
set(CPACK_PACKAGE_NAME "QTStarter")
set(CPACK_PACKAGE_VENDOR "CTAG")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "QTStarter")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "QTStarter")
set(CPACK_NSIS_MODIFY_PATH OFF)
set(CPACK_NSIS_ENABLE_UNINSTALL_BEFORE_INSTALL OFF)
set(CPACK_NSIS_IGNORE_LICENSE_PAGE ON)
set(CPACK_NSIS_EXECUTABLES_DIRECTORY ".")
set(CPACK_NSIS_MUI_ICON "${CMAKE_CURRENT_SOURCE_DIR}/icon.ico")
set(CPACK_NSIS_MUI_UNIICON "${CMAKE_CURRENT_SOURCE_DIR}/icon.ico")
#set(CPACK_NSIS_MENU_LINKS "
#    \"${CMAKE_CURRENT_SOURCE_DIR}/readme.md\" \"Readme\"
#    \"${CMAKE_CURRENT_SOURCE_DIR}/license.txt\" \"License\"
#")


include(CPack)