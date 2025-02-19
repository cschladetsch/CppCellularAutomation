cmake_minimum_required(VERSION 3.20)
project(cellular_automaton 
        VERSION 1.0
        DESCRIPTION "Advanced Cellular Automaton Simulator"
        LANGUAGES CXX)

# Require C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set compiler flags
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
endif()

# Set build type if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Download rang.hpp if not present
set(RANG_PATH ${PROJECT_SOURCE_DIR}/external/rang.hpp)
if(NOT EXISTS ${RANG_PATH})
    file(DOWNLOAD
        https://raw.githubusercontent.com/agauniyal/rang/master/include/rang.hpp
        ${RANG_PATH}
        SHOW_PROGRESS
    )
endif()

# Download catch.hpp if not present
set(CATCH_PATH ${PROJECT_SOURCE_DIR}/external/catch.hpp)
if(NOT EXISTS ${CATCH_PATH})
    file(DOWNLOAD
        https://github.com/catchorg/Catch2/releases/download/v2.13.7/catch.hpp
        ${CATCH_PATH}
        SHOW_PROGRESS
    )
endif()

# Enable testing
enable_testing()

# Add subdirectories
add_subdirectory(src)
add_subdirectory(tests)

# Installation rules
install(TARGETS automaton
    RUNTIME DESTINATION bin
)

# Install headers
install(FILES
    include/automation.hpp
    DESTINATION include)
