/*
	// Copyright 2020 Aman Mehara
	//
	// Licensed under the Apache License, Version 2.0 (the "License");
	// you may not use this file except in compliance with the License.
	// You may obtain a copy of the License at
	//
	//     http://www.apache.org/licenses/LICENSE-2.0
	//
	// Unless required by applicable law or agreed to in writing, software
	// distributed under the License is distributed on an "AS IS" BASIS,
	// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	// See the License for the specific language governing permissions and
	// limitations under the License.

/*

	DIJKSTRA'S SHORTEST PATH Problem : 
	
	PROBLEM : 
    A graph of V nodes represented in the form of the adjacency matrix. The task is to find the shortest distance of all the vertex's from the source vertex.
	 
	The first line of each test case contains an integer V denoting the size of the adjacency matrix and in the next line are V*V space-separated values, which denote the weight of an edge of the matrix (gr[i][j] represents the weight of an edge from ith node to jth node). The third line of each test case contains an integer denoting the source vertex s.
	
	Output:
		Case output will be V space-separated integers where the ith integer denotes the shortest distance of the ith vertex from source vertex.
	
	Time Complexity: O(V2).
	Auxiliary Space: O(V).
	
	Constraints:
	1 <= V <= 100
	0 <= graph[i][j] <= 1000
	0 <= s < V
	
	Example:
	Input:
	3
	0 1 43 1 0 6 43 6 0
	2
	
	Output:
	
	7 6 0
	
	Note:
	Assumption  graph[i][j] = 0 means that the path from i to j does not exist.

*/

#include<bits/stdc++.h>
using namespace std;


void dijkstra(vector<vector<int> >, int , int );

//main function 
int main(){
	
	// V is the number of vertexes nodes in a graph
	int V;                    
	
	//graph matrix 
	vector<vector<int> > graph(V);
	
	for(int i = 0; i<V; i++){
		vector<int> temp(V);
		graph[i] = temp;
	}
	
	for(int i=0; i < V; i++){
		for(int j=0;j<V;j++){
			cin>>graph[i][j];
		}
	}
	
	//start or source vertex
	int start; 
	cin>>start;
	
	//calling the dijkstra function 
	dijkstra(graph, start,V);
	
	cout<<endl;
	
}

//pair redefining
typedef pair<int, int> ipair;

//dijkstra function
void dijkstra(vector<vector<int> > graph, int src, int V){
	
	//creating the adjacency list
    vector<ipair>adj[V]; 
    
    for(int i = 0; i<V; i++){
    	
        for(int j=0;j<V;j++){
        	
            if(graph[i][j] != 0)
               adj[i].push_back( make_pair(j,graph[i][j]) );
               
        }
        
    }
    
    //key storing the key value
    vector<int>key(V,INT_MAX);
    
    //parent vector storing the parent of the index
    vector<int>parent(V,-1);
    
    //visited vector stores if the vectex is visitd or not
    vector<bool>visit(V,false);
    
    //min heap to get the shortest distances
    priority_queue<ipair, vector<ipair>, greater<ipair> >pq;
    
    pq.push(make_pair(0,src));
    key[src]=0;
    
    
    while(!pq.empty()){
    	
        int u = pq.top().second;
        pq.pop();
        visit[u] = true;
        
        vector<ipair> :: iterator i;
        
        for(i = adj[u].begin(); i!=adj[u].end(); i++){
        	
            int v = (*i).first;
            int weight = (*i).second ;
            
            if(visit[v]==false && key[v] > key[u] + weight ){
            	
                key[v] = key[u] + weight ; 
                parent[v] = u;
                pq.push(make_pair(key[v],v));
                
            }
        }
        
    }
    
    //printing the shortwst distances 
    for(int i=0 ; i<V;i++){
    	
        cout<<key[i]<<" ";
        
    }   
    return ;
	 
}






