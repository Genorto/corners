cmake_minimum_required(VERSION 3.28)
project(corners LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(main src/main.cpp src/app.cpp include/app.h include/element.h src/chip.cpp include/chip.h src/field.cpp include/field.h)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE sfml-system sfml-window sfml-graphics)