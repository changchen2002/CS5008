/*
  Name: Chang Chen
  LeetCode Problem: https://leetcode.com/problems/coin-change/description/
*/
#include <stdio.h>
#include <limits.h>

//bottom-up DP approach
int coinChange(int* coins, int len, int amount) {
    if (amount == 0) return 0;
    int dp[amount + 1];
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
    }
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < len; j++) {
            if (coins[j] <= i) {
                int temp = dp[i - coins[j]];
                if (temp != INT_MAX && temp + 1 < dp[i]) {
                    dp[i] = temp + 1;
                }
            }
        }
    }
    return (dp[amount] == INT_MAX)? -1 : dp[amount];
}

/*
Time Complexity: O(amount * len)
Where:
	•	amount is the target value.
	•	len is the number of coins available.

Space Complexity:O(amount)
	•	We are using an array dp of size amount + 1 to store the minimum number of coins needed for each amount.

Edge Cases:
	1.	Amount is 0:
	•	Input: coins = [1, 2, 5], amount = 0
	•	Output: 0
	•	Explanation: No coins are needed to make a total of 0, so the result is 0.
	2.	Impossible to make the amount:
	•	Input: coins = [2, 5], amount = 3
	•	Output: -1
	•	Explanation: No combination of the given coins can form the amount 3, so the result is -1.
	3.	Single coin that matches the amount:
	•	Input: coins = [1], amount = 1
	•	Output: 1
	•	Explanation: The single coin matches the amount exactly, so only 1 coin is needed.
	4.	Coin larger than the amount:
	•	Input: coins = [5], amount = 3
	•	Output: -1
	•	Explanation: Since the coin is larger than the amount, it is impossible to make the amount.
	5.	Multiple coin denominations:
	•	Input: coins = [1, 2, 5], amount = 11
	•	Output: 3
	•	Explanation: The best combination is using two 5’s and one 1, so the minimum number of coins required is 3.
	6.	Multiple coins with duplicate denominations:
	•	Input: coins = [1, 1, 2, 5], amount = 11
	•	Output: 3
	•	Explanation: Even though there are duplicate coins, the minimum number of coins required remains the same.
*/