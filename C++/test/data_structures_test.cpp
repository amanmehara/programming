#include "gtest/gtest.h"

#include <stdexcept>

#include "../data_structures/linked_queue.h"

namespace mehara::data_structures::test {

TEST(QueueTest, LinkedQueue)
{
    linked_queue<int> queue;
    ASSERT_TRUE(queue.empty());
    ASSERT_EQ(0, queue.size());
    queue.enqueue(100);
    ASSERT_EQ(1, queue.size());
    queue.enqueue(121);
    queue.enqueue(144);
    ASSERT_EQ(3, queue.size());
    ASSERT_EQ(100, queue.dequeue());
    ASSERT_EQ(2, queue.size());
    queue.enqueue(169);
    queue.enqueue(196);
    ASSERT_EQ(4, queue.size());
    ASSERT_FALSE(queue.empty());
    queue.dequeue();
    queue.dequeue();
    ASSERT_EQ(169, queue.dequeue());
    ASSERT_EQ(1, queue.size());
    queue.dequeue();
    ASSERT_TRUE(queue.empty());
    ASSERT_EQ(0, queue.size());
    ASSERT_THROW(queue.dequeue(), std::underflow_error);
}

} // namespace mehara::data_structures::test
