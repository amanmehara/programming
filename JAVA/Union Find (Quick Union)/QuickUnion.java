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

import java.util.Collection;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.Collectors;

public class QuickUnion<T> {

    private int count;
    private Map<T, T> parents;

    public QuickUnion(Collection<T> components) {
        count = components.size();
        parents = components.stream().collect(Collectors.toMap(Function.identity(), Function.identity()));
    }

    public void union(T t1, T t2) {

        if(!parents.containsKey(t1) || !parents.containsKey(t2)) {
            throw new IllegalStateException();
        }

        T t1Parent = find(t1);
        T t2Parent = find(t2);

        if(t1Parent.equals(t2Parent)) {
            return;
        }

        parents.put(t1Parent, t2Parent);

        count--;

    }

    public T find(T t) {

        if(!parents.containsKey(t)) {
            throw new IllegalStateException();
        }

        if(!parents.get(t).equals(t)) {
            return find(parents.get(t));
        }

        return parents.get(t);
    }

    public boolean connected(T t1, T t2) {

        if(!parents.containsKey(t1) || !parents.containsKey(t2)) {
            throw new IllegalStateException();
        }

        return find(t1).equals(find(t2));
    }

    public int count() {
        return count;
    }

}