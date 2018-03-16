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
public class Activity <T extends Comparable<T>> {

    private final T startTime;
    private final T finishTime;

    public Activity(T startTime, T finishTime) {
        this.startTime = startTime;
        this.finishTime = finishTime;
    }

    public T startTime() {
        return startTime;
    }

    public T finishTime() {
        return finishTime;
    }

}