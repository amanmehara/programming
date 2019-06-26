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

node* revserse_list(node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    auto _tail = head;
    head = revserse_list(head->next);
    _tail->next->next = _tail;
    _tail->next = nullptr;
    return head;
}
