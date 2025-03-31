#include <iostream>
#include <vector>
using namespace std;

// Recursive function to solve the 0/1 Knapsack problem
int knapsackRecursive(int capacity, vector<int>& weights, vector<int>& values, int n) {
    // Base case: No items left or no capacity left
    if (n == 0 || capacity == 0)
        return 0;

    // If the weight of the current item is greater than the remaining capacity, skip it
    if (weights[n - 1] > capacity)
        return knapsackRecursive(capacity, weights, values, n - 1);

    // Otherwise, explore both options: including and excluding the item
    int includeItem = values[n - 1] + knapsackRecursive(capacity - weights[n - 1], weights, values, n - 1);
    int excludeItem = knapsackRecursive(capacity, weights, values, n - 1);

    // Return the maximum of the two choices
    return max(includeItem, excludeItem);
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;
    int n = values.size();

    int maxValue = knapsackRecursive(capacity, weights, values, n);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}
