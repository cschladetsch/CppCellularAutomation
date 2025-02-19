cmake_minimum_required(VERSION 3.28)
project(cellular_automaton 
        VERSION 1.0
        DESCRIPTION "Advanced Cellular Automaton Simulator"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Create automaton_lib library (for shared automaton logic)
add_library(automaton_lib STATIC src/automation.cpp)
target_include_directories(automaton_lib PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Add main executable
add_executable(automaton src/main.cpp)
target_link_libraries(automaton PRIVATE automaton_lib)

# Add test executables
add_executable(automaton_tests tests/test_automation.cpp)
add_executable(test_rang tests/test_rang.cpp)

target_link_libraries(automaton_tests PRIVATE automaton_lib)
target_link_libraries(test_rang PRIVATE automaton_lib)

target_include_directories(automaton_tests PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(test_rang PRIVATE ${PROJECT_SOURCE_DIR}/include)

enable_testing()
add_test(NAME automaton_tests COMMAND automaton_tests)
add_test(NAME test_rang COMMAND test_rang)

# Install rules
install(TARGETS automaton RUNTIME DESTINATION bin)
install(FILES include/automation.hpp DESTINATION include)
