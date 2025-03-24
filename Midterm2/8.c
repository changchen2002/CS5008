#include <stdio.h>
#include <limits.h>
int max(int a, int b) {
    if (a > b) {return a;}
    else {return b;}
}

int rodCut(int price[], int n) {
    // TODO: Write your code here
    if (n < 1){
        return NULL;
    }

    int dp[n];
    dp[0] = 0;
    dp[1] = price[0];
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i/2; j++){
            dp[i] = max(price[i-1], dp[j] + dp[i - j]);
        }
        // Print dp array at each step
        printf("dp[%d]: ", i);
        for (int k = 0; k <= i; k++) {
            printf("%d ", dp[k]);
        }
        printf("\n");
    }
    
    

    return dp[n];
}

int main() {
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int rod_length = 4;
    int n = sizeof(price) / sizeof(price[0]);

    int max_profit = rodCut(price, rod_length);
    printf("Maximum profit for a rod of length %d: %d\n", rod_length, max_profit);

    return 0;
}
