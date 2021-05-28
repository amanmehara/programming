include(GoogleTest)

add_executable(programming_test
    data_structures_test.cpp
    mathematics_test.cpp
    randomized_algorithms_test.cpp 
    search_algorithms_test.cpp
    sorting_algorithms_test.cpp)

target_link_libraries(programming_test programming)
target_link_libraries(programming_test gtest gtest_main)
gtest_discover_tests(programming_test)
