//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        long long total_sum = 0;
        long long current_value = 0;
        
        
        for (int i = 0; i < n; i++) {
            total_sum += a[i];
            current_value += i * (long long)a[i];
        }
        
        long long max_value = current_value;
        
        
        for (int i = 1; i < n; i++) {
            
            current_value = current_value + total_sum - n * (long long)a[n-i];
            max_value = max(max_value, current_value);
        }
        
        return max_value;

    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends