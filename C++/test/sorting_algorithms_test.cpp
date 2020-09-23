#include <iostream>
#include <vector>
#include "gtest/gtest.h"

#include "../sort/sort.h"

TEST(sorting_algorithms, bubble_sort)
{
    auto strategy = mehara::sort::strategy::bubble_sort;
    std::vector<double> sequence{2, 6, 9, 1, 5, 4, 8};
    mehara::sort::sort(sequence, strategy);
    for (auto i = 1; i < sequence.size(); i++) {
        EXPECT_LE(sequence[i - 1], sequence[i]);
    }
}

TEST(sorting_algorithms, heap_sort)
{
    auto strategy = mehara::sort::strategy::heap_sort;
    std::vector<double> sequence{2, 6, 9, 1, 5, 4, 8};
    mehara::sort::sort(sequence, strategy);
    for (auto i = 1; i < sequence.size(); i++) {
        EXPECT_LE(sequence[i - 1], sequence[i]);
    }
}

TEST(sorting_algorithms, insertion_sort)
{
    auto strategy = mehara::sort::strategy::insertion_sort;
    std::vector<double> sequence{2, 6, 9, 1, 5, 4, 8};
    mehara::sort::sort(sequence, strategy);
    for (auto i = 1; i < sequence.size(); i++) {
        EXPECT_LE(sequence[i - 1], sequence[i]);
    }
}

TEST(sorting_algorithms, merge_sort)
{
    auto strategy = mehara::sort::strategy::merge_sort;
    std::vector<double> sequence{2, 6, 9, 1, 5, 4, 8};
    mehara::sort::sort(sequence, strategy);
    for (auto i = 1; i < sequence.size(); i++) {
        EXPECT_LE(sequence[i - 1], sequence[i]);
    }
}

TEST(sorting_algorithms, quick_sort)
{
    auto strategy = mehara::sort::strategy::quick_sort;
    std::vector<double> sequence{2, 6, 9, 1, 5, 4, 8};
    mehara::sort::sort(sequence, strategy);
    for (auto i = 1; i < sequence.size(); i++) {
        EXPECT_LE(sequence[i - 1], sequence[i]);
    }
}

TEST(sorting_algorithms, selection_sort)
{
    auto strategy = mehara::sort::strategy::quick_sort;
    std::vector<double> sequence{2, 6, 9, 1, 5, 4, 8};
    mehara::sort::sort(sequence, strategy);
    for (auto i = 1; i < sequence.size(); i++) {
        EXPECT_LE(sequence[i - 1], sequence[i]);
    }
}
