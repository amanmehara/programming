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

int climb_stairs(int stairs) {
    if (stairs == 1) {
        return 1;
    }

    int previous = 1;
    int current = 2;
    for (int stair = 3; stair <= stairs; stair++) {
        int next = previous + current;
        previous = current;
        current = next;
    }

    return current;
}