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

#include <vector>

using namespace std;

double horners_method(const vector<double> &coefficients, double x) {

	double result = 0;
	for (int i = coefficients.size() - 1; i >= 0; i--) {
		result = result * x + coefficients[i];
	}
	return result;

}