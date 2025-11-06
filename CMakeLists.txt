cmake_minimum_required(VERSION 3.16)
project(Calculator)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.9.3/mingw_64")
set(CMAKE_AUTOMOC ON)
find_package(Qt6 COMPONENTS Widgets REQUIRED)

qt_add_executable(Calculator
    WIN32
    main.cpp
    tinyexpr.c
    style.css
)

target_link_libraries(Calculator PRIVATE Qt6::Widgets)
if(WIN32)
    add_custom_command(TARGET Calculator POST_BUILD
        COMMAND "${CMAKE_PREFIX_PATH}/bin/windeployqt.exe" $<TARGET_FILE:Calculator>
        COMMENT "Running windeployqt to copy Qt DLLs"
    )
endif()