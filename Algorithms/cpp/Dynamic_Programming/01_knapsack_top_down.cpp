//Top-Down (Memoization) 

#include <iostream>
#include <vector>
using namespace std;

// DP table to store computed results
vector<vector<int>> dp;

// Recursive function with memoization
int knapsackMemo(int capacity, vector<int>& weights, vector<int>& values, int n) {
    // Base case: No items left or no capacity left
    if (n == 0 || capacity == 0)
        return 0;

    // If already computed, return stored value
    if (dp[n][capacity] != -1)
        return dp[n][capacity];

    // If weight of current item exceeds capacity, exclude it
    if (weights[n - 1] > capacity)
        return dp[n][capacity] = knapsackMemo(capacity, weights, values, n - 1);

    // Compute the maximum value by including or excluding the current item
    int includeItem = values[n - 1] + knapsackMemo(capacity - weights[n - 1], weights, values, n - 1);
    int excludeItem = knapsackMemo(capacity, weights, values, n - 1);

    // Store and return the maximum result
    return dp[n][capacity] = max(includeItem, excludeItem);
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;
    int n = values.size();

    // Initialize DP table with -1
    dp.assign(n + 1, vector<int>(capacity + 1, -1));

    int maxValue = knapsackMemo(capacity, weights, values, n);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}
