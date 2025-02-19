add_executable(automaton_tests test_automation.cpp)
target_link_libraries(automaton_tests PRIVATE automaton_lib)
target_include_directories(automaton_tests PRIVATE ${PROJECT_SOURCE_DIR}/external)
add_test(NAME automaton_tests COMMAND automaton_tests)

# Add rang test
add_executable(test_rang test_rang.cpp)
target_include_directories(test_rang PRIVATE ${PROJECT_SOURCE_DIR}/external)
add_test(NAME test_rang COMMAND test_rang)
