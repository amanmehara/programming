/*

 Copyright 2020 Gajendra Pandeya

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

package Sorting

fun ArrayList<Int>.bubbleSort()
        : ArrayList<Int> {
    var swap = true
    while (swap) {
        swap = false
        for (i in 0 until this.indices.last) {
            if (this[i] > this[i + 1]) {
                val temp = this[i]
                this[i] = this[i + 1]
                this[i + 1] = temp

                swap = true
            }
        }
    }
    return this
}

fun main(args: Array<String>) {
    val list = arrayListOf(5, 4, 2, 8, 1)
            .bubbleSort()
    list.forEach {
        println(it)
    }
}