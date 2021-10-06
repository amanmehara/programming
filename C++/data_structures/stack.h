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

#ifndef MEHARA_STACK_H_
#define MEHARA_STACK_H_

namespace mehara {

template <class T>
class stack {
  public:
    virtual void push(T element) = 0;

    virtual T pop() = 0;

    virtual bool empty() = 0;

    virtual int size() = 0;

    virtual ~stack() {}
};

} // namespace mehara

#endif // MEHARA_STACK_H_
