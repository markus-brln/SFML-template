cmake_minimum_required(VERSION 3.28)
project(SFMLTemplate LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
#set(CMAKE_BUILD_TYPE Debug)  # Release, etc

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.1.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)


file(GLOB_RECURSE PROJECT_SRC CONFIGURE_DEPENDS
        "src/*.h"
        "src/*.hpp"
        "src/*.ih"
        "src/*.cc"
        "assets/*.TTF"
        "assets/*.ttf"
)
add_executable(main ${PROJECT_SRC})

# Copy the entire assets directory to the build folder post-build
add_custom_command(
        TARGET main POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/assets"   # Source folder
        "$<TARGET_FILE_DIR:main>/assets"       # Destination folder next to exe
)


target_compile_features(main PRIVATE cxx_std_23)
target_link_libraries(main PRIVATE SFML::Graphics)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)
