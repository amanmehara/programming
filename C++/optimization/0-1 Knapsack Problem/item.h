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
#ifndef MEHARA_ITEM_H_
#define MEHARA_ITEM_H_

class Item {

	int value_;
	int weight_;

public:

	Item(int value, int weight) {
		value_ = value;
		weight_ = weight;
	}

	int Value() {
		return value_;
	}

	int Weight() {
		return weight_;
	}

};

#endif  // MEHARA_ITEM_H_