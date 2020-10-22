import java.util.Scanner;

/**
 * Program			=>		Implementation of Dijkastra's Shortest Path Algorithm in Java using Data Structure Adjacency Matrix
 * Documentation	=> 		Is provided at the end of the Program
 * Issue Details	=> 		https://github.com/amanmehara/programming/issues/80
 * Contributed by	=>		@sumitaccess007 : https://github.com/sumitaccess007
 */

public class DijkastraShortestPathAlgorithm {
	
	// Main Function - Starting point of any Java Program
	public static void main(String args []){
		
		// STEP-1 - Take Input from User - For the Number of Vertices of the Graph
		int vertices;
		Scanner scanner = new Scanner (System.in);
		System.out.println("Enter the number of vertices present in graph :- ");
		vertices = scanner.nextInt();
		
		// STEP-2 - Ask User to enter Graph in the form of Adjacency Matrix
		int adjacencyMatrix[][] = new int[vertices][vertices];
		System.out.println("Enter the Adjacency Matrix of the graph (Distance between adjacent vertices of the graph) :- ");
		for (int i=0; i<vertices; i++){
			for (int j=0; j<vertices; j++){
				adjacencyMatrix[i][j] = scanner.nextInt();
			}
		}
		
		// STEP-3 - Print the Graph entered by user in the form of Adjacency Matrix
		System.out.println("Printing Graph in the form of Adjacency Matrix :- ");
		for (int i=0; i<vertices; i++){
			for (int j=0; j<vertices; j++){
				System.out.print(adjacencyMatrix[i][j]+" ");
			}
			System.out.println("");
		}
		
		System.out.println("");
		
		// STEP-4 - Call function to calculate shortest path between vertices
		// A utility function to find out the vertex from graph with minimum shortest value
		dijkastraShortestPath(adjacencyMatrix, vertices, 0);
		
	}

	private static void dijkastraShortestPath(int[][] graph, int numberOfVertices, int sourceVertex) {
		
		// Output Array to hold the shortest distance from Source vertex to final vertex of graph
		int shortestDistance[] = new int[numberOfVertices];
		
		// Array to track the status of vertices whether they are included in Shortest Path (Above Array) or not
		Boolean verticesTrackingStatus[] = new Boolean[numberOfVertices];
		
		// Initially we will mark distances of all the vertices as INFINITE
		for (int i=0; i<numberOfVertices; i++){
			shortestDistance[i] = Integer.MAX_VALUE;
		}
		
		// Initially we will mark all the vertices of the graph as untracked i.e. with FALSE value
		for (int i=0; i<numberOfVertices; i++){
			verticesTrackingStatus[i] = false;
		}
		
		// Distance of Source Vertex of Graph from itself is 0
		shortestDistance[sourceVertex]=0;
		
		// Logic to find the shortest path for all the vertices
		for (int i=0; i<numberOfVertices-1; i++){
			// Logic to get the vertex with minimum distance from the set of vertices (Unprocessed Vertices)
			int finalPickedVertex = minimumDistance(shortestDistance, verticesTrackingStatus, numberOfVertices);
			
			// Mark the picked vertex as Processed vertex
			verticesTrackingStatus[finalPickedVertex] = true;
			
			// Update the distances of the adjacent vertices of the picked vertex
			for (int j=0; j<6; j++){
				// Update shortestDistance[j] only if it is not present in verticesTrackingStatus[] array
				if (!verticesTrackingStatus[j]
						&& graph[finalPickedVertex][j] != 0
						&& shortestDistance[finalPickedVertex] != Integer.MAX_VALUE
						&& shortestDistance[finalPickedVertex] + graph[finalPickedVertex][j] < shortestDistance[j]){
					shortestDistance[j] = shortestDistance[finalPickedVertex] + graph[finalPickedVertex][j];
				}
			}
		}
		
		// Printing final constructed shortest distance array shortestDistance[]
		printShortestDistance(shortestDistance, numberOfVertices);
	}

	
	
	private static int minimumDistance(int[] shortestDistance, Boolean[] verticesTrackingStatus, int numberOfVertices) {
		// Initialize the variables with minimum value
		int minimum = Integer.MAX_VALUE;
		int minimumIndex = -1;
		
		for(int i=0; i<numberOfVertices; i++){
			if (verticesTrackingStatus[i] == false && shortestDistance[i] <= minimum){
				minimum = shortestDistance[i];
				minimumIndex = i;
			}
		}
		return minimumIndex;
	}
	

	
	// A simple function to print the final consructed shortest distance array
	private static void printShortestDistance(int[] shortestDistance, int numberOfVertices) {
		// Printing shortest distance of each vertex from source
		System.out.println("Vertex \t\t Distance From Source Vertex");
		for (int i=0; i<numberOfVertices; i++){
			System.out.println(i + "\t\t" + shortestDistance[i]);
		}
		
	}
}

/*
 * Dijkastra Algorithm :
 * 			To find the shortest path between two nodes of a graph, most commonly used algorithm is Dijkastra's Algorithm.
 * 			Dijkastra's Algorithm is a Greedy Algorithm
 * 			Dijkastra's Algorithm finds the shortest path tree for weighted undirected graph
 * 			Dijkastra's Algorithm is very similar to Prim's Algorithm
 * 			In Dijkastra's Algorithm we create Shortest Path Tree while in Prim's Algorithm we create Minimum Spanning Tree
 * 
 * 
 * About Above Implementation :
 * 			The above implementation is for Undirected Graph, the same function written above can also be used for directed graph also.
 * 			Data Structure Used -----	Adjacency Matrix
 * 			Time Complexity 	-----	O(V^2)
 * 
 * 
 * Usage :
 * 			This algorithm is used to find the shortest distance from the source node to all the other nodes in the graph.
 * 			Dijkastra Algorithm does work for the graph with negative weight cycles.
 *  		(It may give correct results sometimes but not always, so better to avoid using it.)
 * 
 * 
 * Input : 
 * 			A weighted graph
 * 			And a starting source verted of the graph
 * 
 * 
 * Output :
 * 			In the result we obtain the shortest path tree with source vertex as root
 * 
 * 
 * Time Complexity of this Implementation :
 * 			O(V^2)
 * 
 * Algorithm Logic :
 * 			We start with Empty Shortest Path Tree.
 * 			Maintain a array (verticesTrackingStatus[]) to keep track of vertices included in Shortest Path Tree
 * 			Initially assign INFINITE value as a distance to all vertices
 * 				Pick up a vertex (say x) which is not tracked and has a minimum distance value
 * 				Include it in tracked vertices  array(verticesTrackingStatus[])
 * 				Update distance value for all the adjacent vertices of x (which we picked above)
 * 				=> 	To update the distance value - we have to iterate through all the adjacent vertices.
 * 					For every adjavcent vertices v, if sum (Distance value of x from source + weight of edge x-v) is less than the distance value of v
 * 					Then update the distance value of v.
 * 
 * verticesTrackingStatus
 * 			
 * 			
 * 			
 * Input :
 * 		Enter the number of vertices present in graph :- 
 * 		6
 *		Enter the Adjacency Matrix of the graph (Distance between adjacent vertices of the graph) :- 
 *		0
 *		2
 *		1
 *		0
 *		0
 *		0
 *		2
 *		0
 *		7
 *		0
 *		8
 *		4
 *		1
 *		7
 *		0
 *		7
 *		0
 *		3
 *		0
 *		0
 *		7
 *		0
 *		8
 *		4
 *		0
 *		8
 *		0
 *		8
 *		0
 *		5
 *		0
 *		4
 *		3
 *		4
 *		5
 *		0
 *
 *		Printing Graph in the form of Adjacency Matrix :- 
 *		0 2 1 0 0 0 
 *		2 0 7 0 8 4 
 *		1 7 0 7 0 3 
 *		0 0 7 0 8 4 
 *		0 8 0 8 0 5 
 *		0 4 3 4 5 0 
 *
 * Output :
 *		Vertex 		 Distance From Source Vertex
 *		0		0
 *		1		2
 *		2		1
 *		3		8
 *		4		9
 *		5		4
 *
 */
