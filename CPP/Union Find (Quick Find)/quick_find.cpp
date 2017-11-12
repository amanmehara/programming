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

#include <iostream>
#include <vector>

using namespace std;

class QuickFind {

private:

	int count_;
	vector<int> identifiers_;

public:

	QuickFind(int n) {
		count_ = n;
		for (int i = 0; i < n; i++) {
			identifiers_.push_back(i);
		}
	}

	void Union(int p, int q) {

		int identifier_p = identifiers_[p];
		int identifier_q = identifiers_[q];

		if (identifier_p == identifier_q) return;

		for (int i = 0; i < identifiers_.size(); i++) {
			if (identifiers_[i] == identifier_p) {
				identifiers_[i] = identifier_q;
			}
		}

		count_--;

	}

	int Find(int p) {
		return identifiers_[p];
	}

	bool Connected(int p, int q) {
		return identifiers_[p] == identifiers_[q];
	}

	int Count() {
		return count_;
	}

};