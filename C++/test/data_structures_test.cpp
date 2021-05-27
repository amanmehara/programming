#include "gtest/gtest.h"

#include <algorithm>
#include <functional>
#include <limits>
#include <stdexcept>

#include "../data_structures/linked_queue.h"
#include "../data_structures/linked_stack.h"
#include "../data_structures/segment_tree.h"

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

TEST(SegmentTreeTest, Sum)
{
    std::vector<int> data{1, 2, 3, 4, 5, 6, 7, 8};
    auto function = [](auto x, auto y) { return x + y; };
    segment_tree<int> tree(data, function, 0);
    ASSERT_EQ(36, tree.query(0, data.size() - 1));
    ASSERT_EQ(10, tree.query(0, 3));
    ASSERT_EQ(13, tree.query(5, 6));
    ASSERT_EQ(18, tree.query(2, 5));
    tree.update(2, 9);
    ASSERT_EQ(42, tree.query(0, data.size() - 1));
    tree.update(5, 0);
    tree.update(6, 0);
    ASSERT_EQ(0, tree.query(5, 6));
}

TEST(SegmentTreeTest, Multiply)
{
    std::vector<int> data{1, 2, 3, 4, 5, 6, 7, 8};
    auto function = [](auto x, auto y) { return x * y; };
    segment_tree<int> tree(data, function, 1);
    ASSERT_EQ(40320, tree.query(0, data.size() - 1));
    ASSERT_EQ(24, tree.query(0, 3));
    ASSERT_EQ(42, tree.query(5, 6));
    ASSERT_EQ(360, tree.query(2, 5));
    tree.update(2, 9);
    ASSERT_EQ(120960, tree.query(0, data.size() - 1));
    tree.update(5, 0);
    tree.update(6, 0);
    ASSERT_EQ(0, tree.query(5, 6));
}

TEST(SegmentTreeTest, Minimum)
{
    std::vector<int> data{1, 2, 3, 4, 5, 6, 7, 8};
    auto function = [](const int& x, const int& y) { return std::min(x, y); };
    segment_tree<int> tree(data, function, std::numeric_limits<int>::max());
    ASSERT_EQ(1, tree.query(0, data.size() - 1));
    ASSERT_EQ(1, tree.query(0, 3));
    ASSERT_EQ(6, tree.query(5, 6));
    ASSERT_EQ(3, tree.query(2, 5));
    tree.update(2, 9);
    ASSERT_EQ(1, tree.query(0, data.size() - 1));
    tree.update(5, 0);
    tree.update(6, 0);
    ASSERT_EQ(0, tree.query(5, 6));
}

TEST(SegmentTreeTest, Maximum)
{
    std::vector<int> data{1, 2, 3, 4, 5, 6, 7, 8};
    auto function = [](const int& x, const int& y) { return std::max(x, y); };
    segment_tree<int> tree(data, function, std::numeric_limits<int>::min());
    ASSERT_EQ(8, tree.query(0, data.size() - 1));
    ASSERT_EQ(4, tree.query(0, 3));
    ASSERT_EQ(7, tree.query(5, 6));
    ASSERT_EQ(6, tree.query(2, 5));
    tree.update(2, 9);
    ASSERT_EQ(9, tree.query(0, data.size() - 1));
    tree.update(5, 0);
    tree.update(6, 0);
    ASSERT_EQ(0, tree.query(5, 6));
}

} // namespace mehara::test
