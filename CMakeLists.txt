cmake_minimum_required(VERSION 3.2)
project(Isolation VERSION 1 LANGUAGES C CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

set(ALL_SRC
    main.cpp
    )

list(TRANSFORM ALL_SRC PREPEND "src/")

add_executable(Isolation ${ALL_SRC})

target_include_directories(Isolation PRIVATE external/raylib/src)

add_subdirectory(external/raylib)

target_link_libraries(Isolation PRIVATE raylib)

set_target_properties(Isolation PROPERTIES DEBUG_POSTFIX -d)
