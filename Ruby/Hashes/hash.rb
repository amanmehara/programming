# Copyright 2020 sabarishrajamohan@gmail.com
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#     http://www.apache.org/licenses/LICENSE-2.0
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# A hash is like a Dictionary data stucturein Python. It consists of key value pairs

days = Hash.new
days = {"1" => "Sunday", "2" => "Monday"}

# here "1" and "2" are keys and the days are corresponding values to the keys. You can access them like

days["1"] or days["2"]

# To check if a key is present, use

days.key?("1") # true
days.key?("3") # false

# To list out all the keys, use

days.keys

# To list out all the values, use

days.values

days = {"1" => "Sunday", "2" => "Monday", "3" => nil}

# To remove nil values/keys, use

days.compact

# To remove all values/keys, use

days.clear
