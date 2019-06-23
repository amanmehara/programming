// Copyright 2019 Aman Mehara
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

struct node {
    int value;
    node* next;
};

node* add_two_numbers(node* node_1, node* node_2) {
    auto carry = 0;
    auto dummy = new node({0, nullptr});
    auto _node = dummy;
    while (node_1 != nullptr || node_2 != nullptr) {
        auto _sum = carry;
        _sum = _sum + (node_1 != nullptr) ? node_1->value : 0;
        _sum = _sum + (node_2 != nullptr) ? node_2->value : 0;
        _node->next = new node({_sum % 10, nullptr});
        carry = _sum / 10;
        _node = _node->next;
        node_1 = (node_1 != nullptr) ? node_1->next : node_1;
        node_1 = (node_1 != nullptr) ? node_1->next : node_1;
    }
    if (carry > 0) {
        _node->next = new node({carry, nullptr});
    }
    return dummy->next;
}