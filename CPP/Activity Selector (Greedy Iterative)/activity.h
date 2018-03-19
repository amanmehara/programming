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
#ifndef MEHARA_ACTIVITY_H_
#define MEHARA_ACTIVITY_H_

class Activity {

	int start_time_;
	int finish_time_;

public:

	Activity(int start_time, int finish_time) {
		start_time_ = start_time;
		finish_time_ = finish_time;
	}

	int StartTime() {
		return start_time_;
	}

	int FinishTime() {
		return finish_time_;
	}

};

#endif  // MEHARA_ACTIVITY_H_