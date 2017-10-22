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

import java.util.*;

public class DirectedGraph<V> {

    private final Map<V, Set<V>> adjacencyList;

    public DirectedGraph() {
        this.adjacencyList = new HashMap<>();
    }

    public boolean adjacent(V source, V target) {
        return adjacencyList.containsKey(source) && adjacencyList.get(source).contains(target);
    }

    public Set<V> neighbours(V vertex) {
        if (adjacencyList.containsKey(vertex)) {
            return adjacencyList.get(vertex);
        }
        throw new IllegalStateException("Vertex not found in the Graph.");
    }

    public void addVertex(V vertex) {
        adjacencyList.putIfAbsent(vertex, new HashSet<>());
    }

    public void removeVertex(V vertex) {
        if (adjacencyList.containsKey(vertex)) {
            adjacencyList.remove(vertex);
            adjacencyList.values().forEach(neighbours -> neighbours.remove(vertex));
        }
    }

    public void addEdge(V source, V target) {
        if (adjacencyList.containsKey(source) && adjacencyList.containsKey(target)) {
            adjacencyList.get(source).add(target);
        }
        throw new IllegalStateException("Vertex not found in the Graph.");
    }

    public void removeEdge(V source, V target) {
        if (adjacencyList.containsKey(source)) {
            adjacencyList.get(source).remove(target);
        }
    }

}