'''
Copyright [2020] [Anoop Bhat]
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
'''


import math

def Dijkstras(graph, start, goal):
    unseen_nodes = graph
    predecessor = {}
    shortest_distance = {}
    path = []
    infinty = math.inf

    for node in unseen_nodes:
        shortest_distance[node] = infinty
    shortest_distance[start] = 0

    while unseen_nodes:
        minNode = None
        for node in unseen_nodes:
            if minNode is None:
                minNode = node

            elif shortest_distance[node] < shortest_distance[minNode]:
                minNode = node

        for chilNode,weight in graph[minNode].items():
            if weight + shortest_distance[minNode] < shortest_distance[chilNode]:
                shortest_distance[chilNode] = weight + shortest_distance[minNode]
                predecessor[chilNode] = minNode
        
        unseen_nodes.pop(minNode)

    
    curren_node = goal
    while curren_node != start:
        try:
            path.insert(0,curren_node)

            curren_node = predecessor[curren_node]
        except KeyError:
            print('path not found')
            break

    path.insert(0,start)

    if shortest_distance[goal] != infinty:
        print('The shortest distance is ' + str(shortest_distance[goal]))
        print('And the path is ' + str(path))


graph = {'a':{'b':10,'c':3},'b':{'c':1,'d':2},'c':{'b':4,'d':8,'e':2},'d':{'e':7},'e':{'d':9}}
Dijkstras(graph, 'a', 'd')


