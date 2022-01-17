cmake_minimum_required(VERSION 3.2)
project(Isolation VERSION 1 LANGUAGES C CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Isolation_SRC
    main.cpp 
    transform.cpp transform.hpp
    node.cpp node.hpp
    billboard.cpp billboard.hpp
    )

list(TRANSFORM Isolation_SRC PREPEND "src/")

add_executable(Isolation ${Isolation_SRC})

target_include_directories(Isolation PRIVATE external/raylib/src)
target_include_directories(Isolation PRIVATE external/raylib-cpp/include)

add_subdirectory(external/raylib)

target_link_libraries(Isolation PRIVATE raylib)

set_target_properties(Isolation PROPERTIES DEBUG_POSTFIX -d)
