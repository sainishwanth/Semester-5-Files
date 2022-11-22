# include <stdio.h>
# include <time.h>
# include <stdlib.h>
# include <ui_curses.c>

int getMax(int x, int y);
int knapSack(int maxWeight, int noOfItems, int *profit, int *weight);
int *randomWeights(int noOfItems, int maxWeight);
int *randomProfit(int noOfItems, int maxWeight);
void printArray(int *array, int noOfItems);

int main() {
    int noOfItems, maxWeight;
    printf("Enter the number of items: ");
    int startTime = clock();
    scanf("%d", &noOfItems);
    maxWeight = rand() % (noOfItems*10);
    int *profit = randomProfit(noOfItems, maxWeight);
    int *weight = randomWeights(noOfItems, maxWeight);
    printf("The capacity of the knapsack is: %d\n", maxWeight);
    printf("The weights of the items are: \n");
    printArray(weight, noOfItems);
    printf("The profits of the items are: \n");
    printArray(profit, noOfItems);
    printf("\nThe optimal Solution is %d. ", knapSack(maxWeight, noOfItems, profit, weight));
    int endTime = clock();
    int timeElapsed = endTime - startTime;
    printf("\nTime taken: %dms.\n", timeElapsed);
    return 0;
}

int getMax(int x, int y) {
    (x > y) ? x : y;
}

int *randomProfit(int noOfItems, int maxWeight) {
    int *profit = (int *)malloc(noOfItems * sizeof(int));
    for (int i = 0; i < noOfItems; i++) {
        profit[i] = rand() % maxWeight;
    }
    return profit;
}

int *randomWeights(int noOfItems, int maxWeight) {
    int *weight = (int *)malloc(noOfItems * sizeof(int));
    for (int i = 0; i < noOfItems; i++) {
        weight[i] = rand() % maxWeight;
    }
    return weight;
}

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("Item %d: %d\n", (i+1), array[i]);
    }
}

int knapSack(int maxWeight, int noOfItems, int *profit, int *weight) {
    int i, w;
    int valueTable[noOfItems+1][maxWeight+1]; // 2D array to store the values of the knapsack
    for(i = 1; i <= noOfItems; i++) { // fill the rest of the table
        for(w = 1; w <= maxWeight; w++) { 
            if(i == 0 || w == 0) {
                valueTable[i][w] = 0;
            }
            else if(weight[i - 1] <= w) {
                valueTable[i][w] = getMax(profit[i - 1] + valueTable[i - 1][w - weight[i - 1]], valueTable[i - 1][w]);
            }
            else {
                valueTable[i][w] = valueTable[i - 1][w];
            }
        }
    }
    return valueTable[noOfItems][maxWeight];  //print the max value
} 
