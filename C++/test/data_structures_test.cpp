#include "gtest/gtest.h"

#include <stdexcept>

#include "../data_structures/linked_queue.h"
#include "../data_structures/linked_stack.h"

namespace mehara::test {

TEST(QueueTest, LinkedQueue)
{
    linked_queue<int> queue;
    ASSERT_TRUE(queue.empty());
    ASSERT_EQ(queue.size(), 0);
    queue.enqueue(100);
    ASSERT_EQ(queue.size(), 1);
    queue.enqueue(121);
    queue.enqueue(144);
    ASSERT_EQ(queue.size(), 3);
    ASSERT_EQ(queue.dequeue(), 100);
    ASSERT_EQ(queue.size(), 2);
    queue.enqueue(169);
    queue.enqueue(196);
    ASSERT_EQ(queue.size(), 4);
    ASSERT_FALSE(queue.empty());
    queue.dequeue();
    queue.dequeue();
    ASSERT_EQ(queue.dequeue(), 169);
    ASSERT_EQ(queue.size(), 1);
    queue.dequeue();
    ASSERT_TRUE(queue.empty());
    ASSERT_EQ(queue.size(), 0);
    ASSERT_THROW(queue.dequeue(), std::underflow_error);
}

TEST(StackTest, LinkedStack)
{
    linked_stack<int> stack;
    ASSERT_TRUE(stack.empty());
    ASSERT_EQ(stack.size(), 0);
    stack.push(100);
    ASSERT_EQ(stack.size(), 1);
    stack.push(121);
    stack.push(144);
    ASSERT_EQ(stack.size(), 3);
    ASSERT_EQ(stack.pop(), 144);
    ASSERT_EQ(stack.size(), 2);
    stack.push(169);
    stack.push(196);
    ASSERT_EQ(stack.size(), 4);
    ASSERT_FALSE(stack.empty());
    stack.pop();
    stack.pop();
    ASSERT_EQ(stack.pop(), 121);
    ASSERT_EQ(stack.size(), 1);
    stack.pop();
    ASSERT_TRUE(stack.empty());
    ASSERT_EQ(stack.size(), 0);
    ASSERT_THROW(stack.pop(), std::underflow_error);
}

} // namespace mehara::test
