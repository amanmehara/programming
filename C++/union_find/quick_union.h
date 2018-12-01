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

#ifndef MEHARA_QUICK_UNION_H_
#define MEHARA_QUICK_UNION_H_

#include <vector>

class QuickUnion {

  public:
    QuickUnion(int n);

    void Union(int p, int q);

    int Find(int p);

    bool Connected(int p, int q);

    int Count();

  private:
    int count_;
    std::vector<int> parents_;
};

#endif // MEHARA_QUICK_UNION_H_