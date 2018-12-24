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

int reverse(int number) {
    int reverse = 0;
    while (number != 0) {
        int digit = number % 10;
        number /= 10;
        if (reverse > INT_MAX / 10 ||
            (reverse == INT_MAX / 10 && digit > INT_MAX % 10) ||
            reverse < INT_MIN / 10 ||
            (reverse == INT_MIN / 10 && digit < INT_MIN % 10)) {
            return 0;
        }
        reverse = reverse * 10 + digit;
    }
    return reverse;
}