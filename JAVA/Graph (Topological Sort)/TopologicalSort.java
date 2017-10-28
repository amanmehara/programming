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

public class TopologicalSort<V> {

    public List<V> topologicalSort(DirectedGraph<V> graph) {

        final LinkedList<V> sorted = new LinkedList<>();
        final Map<V, VertexStatus> statusMap = new HashMap<>();

        graph.adjacencyList().keySet().forEach(v -> recurse(graph, v, sorted, statusMap));

        return sorted;

    }

    private void recurse(DirectedGraph<V> graph, V vertex, LinkedList<V> sorted, Map<V, VertexStatus> statusMap) {

        VertexStatus vertexStatus = statusMap.getOrDefault(vertex, VertexStatus.NOT_MARKED);

        if (vertexStatus.equals(VertexStatus.PERMANENTLY_MARKED)) {
            return;
        }

        if (vertexStatus.equals(VertexStatus.TEMPORARILY_MARKED)) {
            throw new IllegalStateException("Grapg has atleast 1 cycle.");
        }

        statusMap.put(vertex, VertexStatus.TEMPORARILY_MARKED);
        graph.adjacencyList().get(vertex).forEach(v -> recurse(graph, v, sorted, statusMap));
        statusMap.put(vertex, VertexStatus.PERMANENTLY_MARKED);
        sorted.push(vertex);

    }

}
