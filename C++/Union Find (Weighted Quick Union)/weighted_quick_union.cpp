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
#include <iostream>
#include <vector>

using namespace std;

class WeightedQuickUnion {

private:

	int count_;
	vector<int> parents_;
	vector<int> size_;

public:

	WeightedQuickUnion(int n) {
		count_ = n;
		for (int i = 0; i < n; i++) {
			parents_.push_back(i);
			size_.push_back(1);
		}
	}

	void Union(int p, int q) {

		int parent_p = Find(p);
		int parent_q = Find(q);

		if (parent_p == parent_q) return;

		if (size_[parents_[p]] < size_[parents_[q]]) {
			parents_[parent_p] = parent_q;
			size_[parent_q] += size_[parent_p];
		}
		else {
			parents_[parent_q] = parent_p;
			size_[parent_p] += size_[parent_q];
		}

		count_--;

	}

	int Find(int p) {
		if (parents_[p] != p) {
			return Find(parents_[p]);
		}
		return parents_[p];
	}

	bool Connected(int p, int q) {
		return Find(p) == Find(q);
	}

	int Count() {
		return count_;
	}

};