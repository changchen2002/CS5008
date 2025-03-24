// Compile : gcc -Wall adjacencymatrix.c -o adjacencymatrix 
//           ^ Note: You may get a few warnings for passing pointers around, 
//             this is okay for this lab.
// Run with: ./adjacencymatrix
    
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// These #define directives are preprocessor instructions. 
// Before compiling, the compiler replaces every occurrence 
// of 'ROWS' and 'COLUMNS' with the numbers 5 and 5. 
// You can modify these values to change the size of the graph matrix.

#define ROWS 5
#define COLUMNS 5

/*  ============= Tutorial on Graph format ============
    You are given a randomly generated graph that looks 
    of the form:

    0 0 1 1 1
    1 0 0 1 1
    0 1 0 1 1
    1 0 0 0 0
    1 0 1 1 0

    You can think of the graph with labels for each of
    the nodes (usually called vertices or nodes) 
    more clearly below:

               0 1 2 3 4
               ---------  
    node 0:    0 0 1 1 1
    node 1:    1 0 0 1 1
    node 2:    0 1 0 1 1
    node 3:    1 0 0 0 0
    node 4:    1 0 1 1 0

    A '1' represents a connection to a node, and a 0
    means it is not connected.

               0 1 2 3 4
               ---------  
    node 0:    0 0 1 1 1
    node 1:    1 0 0 1 1
    node 2:    0 1 0 1 1
    node 3:    1 0 0 0 0
    node 4:    1 0 1 1 0

    In the above, '0' is connected to 2, 3, and 4.
    That means node 0 has directed-edges out 
    to nodes  2,3,and 4. In other words, 
    the edge-list for node 0 is:
    0->2, 0->3, 0->4
    
    The number of connections a node has out is its 'out-degree'
    The number of connections a node has in are it's 'in-degree'
*/



// This function generates a random adjacency matrix for a graph.
// Each cell in the matrix represents a possible edge between two nodes.
// Note: We do NOT seed the random number generator with srand(time(NULL)).
//       This means the same graph will be generated every time the program runs,
//       ensuring consistent results for testing and debugging.

void generateGraph(int* g){
    
    // Uncomment the line below if you want to generate a different random graph 
    // each time the program runs.
    // srand(time(NULL));  
    
    int i, j;
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLUMNS; j++){
            if(i == j){
                g[i * COLUMNS + j] = 0; // No self-loops: a node is not connected to itself.
            } else {
                g[i * COLUMNS + j] = rand() % 2; // Randomly assign 0 or 1 for edge existence.
            }
        }
    }
}


// This function prints out the adjacency matrix of the graph.
// Each row represents a node, and each column indicates if there is a connection (1) or not (0) 
// to another node.

void printGraph(int* g){ 
    int i, j;
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLUMNS; j++){
            printf("%d ", g[i * COLUMNS + j]);
        }
        printf("\n");
    }
}


// This function computes the 'in-degree' of a node in an adjacency matrix.
// The in-degree is the number of incoming edges to the node.

int nodeInDegree(int* g, int node){
    int count = 0;
    for (int i = 0; i < ROWS; i++){
        if (g[i * COLUMNS + node] == 1){
            count++;
        }
    }
    return count;
}



// This function computes the 'out-degree' of a node in an adjacency matrix.
// The out-degree is the number of outgoing edges from the node.

int nodeOutDegree(int* g, int node){
    int count = 0;
    for (int j = 0; j < COLUMNS; j++){
        if (g[node * COLUMNS + j] == 1){
            count++;
        }
    }
    return count;
}



// This function checks if two nodes are directly connected.
// Returns 1 if an edge exists between node1 and node2, otherwise returns 0.
// Note: This only checks for direct connections (edges), not paths.

int isConnected(int* g, int node1, int node2){
    return g[node1 * COLUMNS + node2];
}


int main(){
 
    int* g_testgraph = (int*)malloc(ROWS * COLUMNS * sizeof(int));
    
    // Generate and print graph
    
    generateGraph(*g_testgraph);
    printf("Generated Graph:\n");
    printGraph(*g_testgraph);
    
    // In-degree of each node
    printf("\nNode In-Degrees:\n");
    for (int i = 0; i < ROWS; ++i) {
        printf("Node %d in-degree = %d\n", i, nodeInDegree(*g_testgraph, i));
    }
    
    // Out-degree of each node
    printf("\nNode Out-Degrees:\n");
    for (int i = 0; i < ROWS; ++i) {
        printf("Node %d out-degree = %d\n", i, nodeOutDegree(*g_testgraph, i));
    }
    
    // Check connections for node 0
    printf("\nNode 0 Connections (1 means connected):\n");
    for (int j = 0; j < COLUMNS; ++j) {
        printf("0 -> %d: %d\n", j, isConnected(*g_testgraph, 0, j));
    }

    return 0;
}
