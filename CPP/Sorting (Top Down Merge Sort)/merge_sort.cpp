/*
 * Copyright 2018 Aman Mehara
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <vector>

using namespace std;

class MergeSort {

	void merge(vector<int> &a, vector<int> &auxiliary, int begin, int middle, int end) {

		int i = begin;
		int j = middle + 1;

		for (int k = begin; k <= end; k++) {
			if (i <= middle && (j > end || a[i] <= a[j])) {
				auxiliary[k] = a[i++];
			}
			else {
				auxiliary[k] = a[j++];
			}
		}

	}

	void sort(vector<int> &a, vector<int> &auxiliary, int begin, int end) {

		if (end <= begin) {
			return;
		}

		int middle = begin + (end - begin) / 2;
		sort(auxiliary, a, begin, middle);
		sort(auxiliary, a, middle + 1, end);
		merge(auxiliary, a, begin, middle, end);

	}

public:

	void sort(vector<int> &a) {
		vector<int> auxiliary(a);
		sort(a, auxiliary, 0, a.size() - 1);
	}

};