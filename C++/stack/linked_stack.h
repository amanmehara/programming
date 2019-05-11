// Copyright 2018 Aman Mehara
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef MEHARA_LINKED_STACK_H_
#define MEHARA_LINKED_STACK_H_

#include "stack.h"

#include <stdexcept>

template <class T>
class linked_stack : public stack<T> {
  public:
    linked_stack();

    void push(T element) override;

    T pop() override;

    bool empty() override;

    int size() override;

    ~linked_stack() override;

  private:
    struct node {
        T element;
        node* next;
    };

    node* top_;
    int size_;
};

template <class T>
linked_stack<T>::linked_stack() {
    top_ = nullptr;
    size_ = 0;
}

template <class T>
void linked_stack<T>::push(T element) {
    node* current = new node();
    current->element = element;
    current->next = top_;
    top_ = current;
    size_++;
}

template <class T>
T linked_stack<T>::pop() {
    if (size_ == 0) {
        throw std::underflow_error("Stack is already empty.");
    }

    node* current = top_;
    top_ = top_->next;
    T element = current->element;
    delete current;
    size_--;

    return element;
}

template <class T>
bool linked_stack<T>::empty() {
    return size_ == 0;
}

template <class T>
int linked_stack<T>::size() {
    return size_;
}

template <class T>
linked_stack<T>::~linked_stack() {
    while (top_) {
        node* current = top_;
        top_ = top_->next;
        delete current;
        size_--;
    }
}

#endif // MEHARA_LINKED_STACK_H_
