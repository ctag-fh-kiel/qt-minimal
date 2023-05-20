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
# add qt5 dlls to install target
install(FILES
        $<TARGET_FILE:Qt5::Core>
        $<TARGET_FILE:Qt5::Gui>
        $<TARGET_FILE:Qt5::Network>
        $<TARGET_FILE:Qt5::Widgets>
        DESTINATION bin)

# add msys2 dlls to install target
set(MSYS2_PATH "c:/msys64")
install(FILES
        ${MSYS2_PATH}/mingw64/bin/libgcc_s_seh-1.dll
        ${MSYS2_PATH}/mingw64/bin/libstdc++-6.dll
        ${MSYS2_PATH}/mingw64/bin/libwinpthread-1.dll
        ${MSYS2_PATH}/mingw64/bin/zlib1.dll
        ${MSYS2_PATH}/mingw64/bin/libcurl-4.dll
        ${MSYS2_PATH}/mingw64/bin/libdouble-conversion.dll
        ${MSYS2_PATH}/mingw64/bin/libicuin72.dll
        ${MSYS2_PATH}/mingw64/bin/libicuuc72.dll
        ${MSYS2_PATH}/mingw64/bin/libpcre2-16-0.dll
        DESTINATION bin)

set(CMAKE_MINGW_SYSTEM_LIBRARY_PATH "${MSYS2_PATH}/mingw64/bin")
install(CODE [[
        message(STATUS "Looking for deps in ${CMAKE_SYSTEM_LIBRARY_PATH};${CMAKE_MINGW_SYSTEM_LIBRARY_PATH}")
        file(GET_RUNTIME_DEPENDENCIES
            RESOLVED_DEPENDENCIES_VAR deps_resolved
            UNRESOLVED_DEPENDENCIES_VAR deps_unresolved
            LIBRARIES $<TARGET_FILE:mylib>
            DIRECTORIES ${CMAKE_SYSTEM_LIBRARY_PATH} ${CMAKE_MINGW_SYSTEM_LIBRARY_PATH}
            PRE_EXCLUDE_REGEXES "api-ms-*" "ext-ms-*"
            POST_EXCLUDE_REGEXES ".*system32/.*\\.dll"
            )
        message(STATUS "Resolving runtime dependencies for $<TARGET_FILE:mylib>")
        foreach(dep ${deps_resolved})
            file(INSTALL ${dep} DESTINATION ${CMAKE_INSTALL_PREFIX})
        endforeach()
        foreach(dep ${deps_unresolved})
            message(WARNING "Runtime dependency ${dep} could not be resolved.")
        endforeach()
        ]])


# make deployment using cpack and nsis
set(CPACK_GENERATOR "NSIS")
set(CPACK_PACKAGE_NAME "QTStarter")
set(CPACK_PACKAGE_VENDOR "Dish")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "QTStarter")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "QTStarter")
set(CPACK_NSIS_MODIFY_PATH ON)
set(CPACK_NSIS_ENABLE_UNINSTALL_BEFORE_INSTALL ON)
set(CPACK_NSIS_EXECUTABLES_DIRECTORY ".")
#set(CPACK_NSIS_MUI_ICON "${CMAKE_CURRENT_SOURCE_DIR}/icon.ico")
#set(CPACK_NSIS_MUI_UNIICON "${CMAKE_CURRENT_SOURCE_DIR}/icon.ico")
#set(CPACK_NSIS_MENU_LINKS "
#    \"${CMAKE_CURRENT_SOURCE_DIR}/README.txt\" \"Readme\"
#    \"${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt\" \"License\"
#")
set(CPACK_NSIS_URL_INFO_ABOUT "")
set(CPACK_NSIS_CONTACT "")

include(CPack)