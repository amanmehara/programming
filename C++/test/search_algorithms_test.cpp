#include "gtest/gtest.h"

#include <vector>

#include "../search/search.h"

namespace mehara::test {

TEST(BinarySearch, Iterative)
{
    std::vector<int> data{1, 2, 3, 4, 5, 6, 7, 8};
    int index;
    ASSERT_EQ(binary_search(data, 0, index, false), false);
    ASSERT_EQ(binary_search(data, 1, index, false), true);
    ASSERT_EQ(index, 0);
    ASSERT_EQ(binary_search(data, 4, index, false), true);
    ASSERT_EQ(index, 3);
    ASSERT_EQ(binary_search(data, 9, index, false), false);
}

TEST(BinarySearch, Recursive)
{
    std::vector<int> data{1, 2, 3, 4, 5, 6, 7, 8};
    int index;
    ASSERT_EQ(binary_search(data, 0, index), false);
    ASSERT_EQ(binary_search(data, 1, index), true);
    ASSERT_EQ(index, 0);
    ASSERT_EQ(binary_search(data, 4, index), true);
    ASSERT_EQ(index, 3);
    ASSERT_EQ(binary_search(data, 9, index), false);
}

TEST(LinearSearch, Default)
{
    std::vector<int> data{1, 2, 3, 4, 5, 6, 7, 8};
    int index;
    ASSERT_EQ(linear_search(data, 0, index), false);
    ASSERT_EQ(linear_search(data, 1, index), true);
    ASSERT_EQ(index, 0);
    ASSERT_EQ(linear_search(data, 4, index), true);
    ASSERT_EQ(index, 3);
    ASSERT_EQ(linear_search(data, 9, index), false);
}

} // namespace mehara::test
