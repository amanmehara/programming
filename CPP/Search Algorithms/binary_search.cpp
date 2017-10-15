/*

Copyright 2017 Aman Mehara

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

#include "search.h"

std::tuple<bool, int> BinarySearch::Iterative(std::vector<int> const &data, int key) {
	int start = 0;
	int end = data.size() - 1;
	while (start <= end) {
		int middle = start + ((end - start) / 2);
		if (data.at(middle) == key) {
			return std::make_tuple(true, middle);
		}
		else if (data.at(middle) > key) {
			end = middle - 1;
		}
		else {
			start = middle + 1;
		}
	}
	return std::make_tuple(false, -1);
}

std::tuple<bool, int> BinarySearch::Recursive(std::vector<int> const &data, int key, int start, int end) {
	if (start <= end) {
		int middle = start + ((end - start) / 2);
		if (data.at(middle) == key) {
			return std::make_tuple(true, middle);
		}
		else if (data.at(middle) > key) {
			return Recursive(data, key, start, middle - 1);
		}
		else {
			return Recursive(data, key, middle + 1, end);
		}
	}
	else {
		return std::make_tuple(false, -1);
	}
}

std::tuple<bool, int> BinarySearch::RecursiveWrapper(std::vector<int> const &data, int key) {
	return Recursive(data, key, 0, data.size() - 1);
}