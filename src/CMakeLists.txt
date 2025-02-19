add_library(automaton_lib INTERFACE)
target_include_directories(automaton_lib 
    INTERFACE 
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/external
)

add_executable(automaton main.cpp)
target_link_libraries(automaton PRIVATE automaton_lib)
target_include_directories(automaton PRIVATE ${PROJECT_SOURCE_DIR}/external)
