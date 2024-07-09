//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        int n = arr.size();
        if (n < 3) return 0; // Edge case: not enough elements to form a triplet

        sort(arr.begin(), arr.end()); // Sort the array to use two-pointer technique
        int closestSum = arr[0] + arr[1] + arr[2]; // Initialize with the sum of the first three elements

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int currentSum = arr[i] + arr[left] + arr[right];
                // Update closestSum if the current sum is closer to target
                if (abs(target - currentSum) < abs(target - closestSum)) {
                    closestSum = currentSum;
                } else if (abs(target - currentSum) == abs(target - closestSum)) {
                    // If the current sum is equally close to the target, choose the maximum sum
                    closestSum = max(closestSum, currentSum);
                }

                // Move the pointers based on comparison with the target
                if (currentSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return closestSum;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends