// Copyright 2024 Aman Mehara
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

#ifndef MEHARA_RABIN_KARP_H_
#define MEHARA_RABIN_KARP_H_

#include <string>
#include <vector>

namespace mehara::string {

std::vector<int> rabin_karp_matcher(const std::string& text,
                                    const std::string& pattern, int radix,
                                    int prime);

} // namespace mehara::string

#endif // MEHARA_RABIN_KARP_H_
