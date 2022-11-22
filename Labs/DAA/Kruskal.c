# include <stdio.h>
# include <time.h>

# define infinity 999

typedef struct graph {
    int v1, v2, cost;
} gr;

gr g[20];
int nodes, edges;

void spanningTree();

int main() {
    int k, startTime, endTime, totalTime;
    printf("\n\tGRAPH CREATION\n");
    printf("Enter no of nodes\n");
    scanf("%d", &nodes);
    printf("Enter no edges\n");
    scanf("%d", &edges);
    for(k = 0; k < edges; k++) {
        printf("Enter edge v1 to v2:");
        scanf("%d %d", &g[k].v1, &g[k].v2);
        printf("Enter the cost:");
        scanf("%d", &g[k].cost);
    }
    startTime = clock();
    spanningTree();
    endTime = clock();
    totalTime = endTime - startTime;
    printf("\nStart Time = %d\n	End Time = %d\n	Total Time = %d\n", startTime, endTime, totalTime);
    return 0;
}

int find(int v2, int parent[]) {
    while(parent[v2]) {
        v2 = parent[v2];
    }
    return v2;
}

void unionFunc(int i, int j, int parent[10]) {
    if(i < j) {
        parent[j] = i;
    }
    else {
        parent[i] = j;
    }
}

int minimum(int n) {
    int i, small, pos;
    small = infinity;
    pos = -1;
    for(i = 0; i < n; i++) {
        if(g[i].cost < small) {
            small = g[i].cost;
            pos = i;
        }
    }
    return pos;
}

void spanningTree() {
    int count, k, v1, v2, i, j, tree[10][10], pos, parent[10];
    int sum;
    count = 0;
    k = 0; 
    sum = 0;
    for(i = 0; i < nodes; i++) {
        parent[i] = i;
    }
    while(count != (nodes - 1)) {
        pos = minimum(edges);
        if(pos == -1) {
            break;
        }
        v1 = g[pos].v1;
        v2 = g[pos].v2;
        i = find(v1, parent);
        j = find(v2, parent);
        if(i != j) {
            tree[k][0] = v1;
            tree[k][1] = v2;
            k++;
            count++;
            sum += g[pos].cost;
            unionFunc(i, j, parent);
        }
        g[pos].cost = infinity;
    }
    if(count == (nodes - 1)) {
        printf("\n\tSPANNING TREE IS:\n");
        printf("\n");
        for(i = 0; i < (nodes - 1); i++) {
            printf("\n%d", tree[i][0]);
            printf("-");
            printf("%d\n", tree[i][1]);
        }
        printf("\nCost of spanning tree is: %d", sum);
    }
    else {
        printf("No spanning tree");
    }
}
