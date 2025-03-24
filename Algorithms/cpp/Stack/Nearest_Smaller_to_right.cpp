#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nearestSmallerToRight(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); // Initialize with -1 (default when no smaller element is found)
    stack<int> s; // Stack to keep track of elements

    for (int i = n - 1; i >= 0; --i) {
        // Remove larger elements from the stack
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }
        
        // If stack is not empty, top is the nearest smaller element to the right
        if (!s.empty()) {
            result[i] = s.top();
        }
        
        // Push the current element onto the stack
        s.push(arr[i]);
    }
    
    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = nearestSmallerToRight(arr);
    
    cout << "Nearest Smaller to Right: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
