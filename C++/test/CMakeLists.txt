include(GoogleTest)

add_executable(programming_test 
    mathematics_test.cpp
    randomized_algorithms_test.cpp 
    sorting_algorithms_test.cpp)

target_link_libraries(programming_test gtest gtest_main)
gtest_discover_tests(programming_test)
