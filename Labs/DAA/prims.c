/*
	5. Write a C program to find the minimum spanning tree using Prim's algorithm.
*/

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define infinity 9999 
# define MAX 20
 
int initialGraph[MAX][MAX], spanningTree[MAX][MAX], n;
 
int prims();
void displayGraph(int [][MAX], int);

int main() {
	int i, j, startTime, endTime, totalTime, totalCost;
	printf("Enter the number of vertices in the graph: "); 
	scanf("%d", &n);
	printf("\nEnter the adjacency matrix: \n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
				char a = (char)i + 65; // to get ASCII value of vertices
				char b = (char)j + 65; 
                printf("\n Enter the weight for the edge connecting the vertices [%c] and [%c]: ", a, b);
                scanf("%d", &initialGraph[i][j]);
            }
        }
	printf("\nThe initial graph is: \n");
    displayGraph(initialGraph, n);
	startTime = clock();
	totalCost = prims();
	printf("\n\nThe spanning tree is: \n");
	displayGraph(spanningTree, n);
	printf("\n\nTotal cost of spanning tree = %d", totalCost);
    endTime = clock();
	totalTime = endTime - startTime;
   	printf("\nStart Time = %d ms \nEnd Time = %d ms \nTotal Time = %d ms\n", startTime, endTime, totalTime);
	return 0;
}

void displayGraph(int Graph[][MAX], int n) {
    int i, j;
	for(i = 0; i < n; i++) {
		char column = (char)i + 65;
		printf("\t[%c]", column);
	}
    for(i = 0; i < n; i++) {
		char row = (char)i + 65;
        printf("\n[%c]\t", row);
        for(j = 0; j < n; j++) {
            printf(" %d\t", *(*(Graph + i) + j));
        }
    }
}

int prims() {
	int cost[MAX][MAX];
	int u, v, minDistance, distance[MAX], from[MAX];
	int visited[MAX], noOfEdges, i, minCost, j;
	//create cost[][] matrix, spanningTree[][]
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(initialGraph[i][j] == 0) {
				cost[i][j] = infinity;
            }
			else {
				cost[i][j] = initialGraph[i][j];
				spanningTree[i][j] = 0;
            }
		}
    }
	//initialise visited[], distance[] and from[]
	distance[0] = 0;
	visited[0] = 1;
	for(i = 1; i < n; i++) {
		distance[i] = cost[0][i];
		from[i] = 0;
		visited[i] = 0;
	}
	minCost = 0;		//cost of spanningTree tree
	noOfEdges = (n - 1);		//no. of edges to be added
	while(noOfEdges > 0) {
		//find the vertex at minimum distance from the tree
		minDistance = infinity;
		for(i = 1; i < n; i++) {
			if((visited[i] == 0) && (distance[i] < minDistance)) {
				v = i;
				minDistance = distance[i];
			}
        }
		u = from[v];
		//insert the edge in spanningTree tree
		spanningTree[u][v] = distance[v];
		spanningTree[v][u] = distance[v];
		noOfEdges--;
		visited[v] = 1;
		//updated the distance[] array
		for(i = 1; i < n; i++) {
			if((visited[i] == 0) && (cost[i][v] < distance[i])) {
				distance[i] = cost[i][v];
				from[i] = v;
			}
        }
		minCost = minCost + cost[u][v];
	}
	return(minCost);
}
