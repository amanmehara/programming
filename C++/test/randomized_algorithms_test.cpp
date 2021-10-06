#include "gtest/gtest.h"
#include <vector>

#include "../randomized_algorithms/fisher_yates_shuffle.h"

TEST(randomized_algorithms, fisher_yates_shuffle)
{
    std::vector<int> sequence{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto randomized = sequence;
    mehara::random::fisher_yates_shuffle<int>(randomized);
    ASSERT_EQ(sequence.size(), randomized.size());
    auto count = 0;
    for (int i = 0; i < sequence.size(); i++) {
        if (sequence[i] == randomized[i])
            count++;
    }
    EXPECT_LT(count, sequence.size());
}