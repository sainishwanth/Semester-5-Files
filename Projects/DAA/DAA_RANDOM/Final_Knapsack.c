#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LENGTH 4
#define WIDTH 6

int random_(int, int);  // To generate pseudo-random numbers within a given range
int * random_assignment(int, int); //Assigning pseudo-random numbers to an array of size n
int * custom_assignment(int, char []); //
int max(int, int); //Finding the Max b/w two numbers
void rectangle(int, int); //Generates a rectangle (CLI Art for Items)
void Draw(int [], int [], int); // Prints The Rectangles in a specific format
int Dynamic_Knapsack(int [], int [], int, int); // Used to Calculate the Max Profit
void swap(int *, int *); //Swapping two integer variable values
void swap_float(float*, float*); //Swapping two float variable values
void bubbleSort(float [],int [],int ); //Bubble Sorting
void Profitable_Items(int [], int [], int, int); //Function to find out the most profitable items
int display();

int main(int argc, char **agrv){
    display();
    int choice, n, Max_W, Max_P, Input_MaxP;
    int * Profits;
    int * Weights;
    printf("1 - Enter Your Own Values\n2 - Randomly generate items: ");
    scanf("%d", &choice);
    switch (choice){
        case 1:
            printf("Enter the number of item: ");
            scanf("%d", &n);
            printf("Enter the Maximum Weight: ");
            scanf("%d", &Max_W);
            printf("Enter the Profits:\n");
            Profits = custom_assignment(n, "Profit");
            printf("Enter the Weights:\n");
            Weights = custom_assignment(n, "Weight");
            break;
        case 2:
            srand(time(0));
            n = random_(1,5) * 5;
            srand(time(0)*2.1);
            Max_W = random_(2,8) * 10;
            srand(time(0)*3);
            Profits = random_assignment(n, 9);
            srand(time(0)*4);
            Weights = random_assignment(n, 6);
            break;
        default: 
            printf("Wrong Input!");
            exit(0);
    }
    printf("\nMax Weight - %d\n", Max_W);
    printf("\nProfit\tWeight\n");
    for(int i = 0; i < n; ++i){
        printf("%d\t%d\n", Profits[i], Weights[i]);
    }
    Draw(Profits, Weights, n);
    Max_P = Dynamic_Knapsack(Profits, Weights, n, Max_W);
    printf("Max Weight -%d\nMax Profit - %d\nNumber of Items - %d\n", Max_W, Max_P, n);
    printf("Enter the Maximum Profit: ");
    scanf("%d", &Input_MaxP);
    if(Max_P != Input_MaxP){
        printf("Wrong!\nThe Most Profitable items are-\n");
        Profitable_Items(Profits, Weights, n, Max_W);
        // printf("Max Profit - %d", Max_P);
        return 1;
    }
    printf("Correct!");
    return 0;
}

int random_(int min, int max){
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

int * random_assignment(int n, int multiplier){
    int * arr = (int *)malloc(n*sizeof(int));
    for(int i = 0; i < n; ++i){
    arr[i] = random_(2,9) * multiplier;
    //printf("%d\t", arr[i]);
    }
    return arr;
}
int * custom_assignment(int n, char* Str){
    int *arr = (int *)malloc(n*sizeof(int));
    for(int i = 0; i < n; ++i){
        printf("Enter the %s of item %d: ", Str, i+1);
        scanf("%d", &arr[i]);
    }
    return arr;
}

int max(int a, int b){
    if (a > b){
        return a;
    }
    return b;
}

void rectangle(int p, int w){
    for(int i = 0; i < LENGTH; ++i){
        for(int j = 0; j < WIDTH; ++j){
            if(i==0||i==3||j==0||j==5){
                if(i == 1 || i == 2){
                    printf("| ");
                }else{
                 printf("- ");
                }
            }
            else{
                if(i == 1 && j == 2){
                    printf("%d", p);
                }else if(i == 2 && j == 2){
                    printf("%d", w);
                }else{
                printf("  ");
                }
            }
        }
        printf("\n");
    }
}

void Draw(int p[], int w[], int n){
    for(int i = 0; i < n; ++i){
        if(i != 0 && i % 5 == 0){
            // printf("\033[21A");
            // printf("\033[6C");
            printf("\n");
        }
        rectangle(p[i], w[i]);
    }
}

int Dynamic_Knapsack(int Profits[], int Weights[], int n, int Max_W){
    int k[n+1][Max_W+1];
    for(int i = 0; i <=n; ++i){
        for(int w = 0; w <= Max_W; w++){
            if(i==0 || w == 0){
                k[i][w] = 0;
            }else if(Weights[i-1] <= w){
                k[i][w] = max(Profits[i-1]+k[i-1][w-Weights[i-1]], k[i-1][w]);
            }else{
                k[i][w] = k[i-1][w];
            }
        }
    }
    return k[n][Max_W];
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void swap_float(float *xp, float *yp){
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(float p_w[],int item_nos[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++){ 
        for (j = 0; j < n - i - 1; j++){
            if (p_w[j] < p_w[j + 1]){
                swap_float(&p_w[j], &p_w[j + 1]);
                swap(&item_nos[j],&item_nos[j + 1]);
            }
        }
    }
}
void Profitable_Items(int Profits[], int Weights[],int n, int Max_W){
    int item_nos[n];
    float p_w[n];
    int count_W = 0, curr_W = Max_W;
    int max_P_ = 0;
    float p_float, w_float;
    for(int i = 0; i < n; ++i){
        p_float = (float) Profits[i];
        w_float = (float) Weights[i];
        p_w[i] = p_float / w_float;
        item_nos[i] = i;
    }
    bubbleSort(p_w,item_nos,n);
    int *ptr_items = item_nos;
    for(int i = 0; i < n; ++i){
        if(Weights[*ptr_items] > curr_W){
            break;
        }
        count_W += Weights[*ptr_items];
        curr_W -= Weights[*ptr_items];
        max_P_ += Profits[*ptr_items];
        rectangle(Profits[*ptr_items], Weights[*ptr_items]);
        ++ptr_items;
        if(count_W >= Max_W){
            break;
        }
    }
    printf("Max Profit in Profitable_Item - %d\n", max_P_);
}




