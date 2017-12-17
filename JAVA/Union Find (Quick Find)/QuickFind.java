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

public class QuickFind<T> {

    private int count;
    private Map<T, T> identifiers;

    public QuickFind(Collection<T> components) {
        count = components.size();
        identifiers = components.stream().collect(Collectors.toMap(Function.identity(), Function.identity()));
    }

    public void union(T t1, T t2) {

        if(!identifiers.containsKey(t1) || !identifiers.containsKey(t2)) {
            throw new IllegalStateException();
        }

        T t1Id = identifiers.get(t1);
        T t2Id = identifiers.get(t2);

        if(t1Id.equals(t2Id)) {
            return;
        }

        identifiers = identifiers.entrySet().stream().map(e -> {
            if(e.getValue().equals(t1Id)) {
                e.setValue(t2Id);
            }
            return e;
        }).collect(Collectors.toMap(Map.Entry::getKey,Map.Entry::getValue));

        count--;

    }

    public T find(T t) {

        if(!identifiers.containsKey(t)) {
            throw new IllegalStateException();
        }

        return identifiers.get(t);
    }

    public boolean connected(T t1, T t2) {

        if(!identifiers.containsKey(t1) || !identifiers.containsKey(t2)) {
            throw new IllegalStateException();
        }

        return identifiers.get(t1).equals(identifiers.get(t2));
    }

    public int count() {
        return count;
    }

}