//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        // code her
        if(q<=n+1)
        {
            return q-1;
        }
        else if((q>(n+1) && q<=(2*n)))
        {
            long long k=q-(n+1);
            return n-k;
        }
        else
        {
            return 0;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n,q;
        
        cin>>n>>q;

        Solution ob;
        cout << ob.sumMatrix(n,q) << endl;
    }
    return 0;
}
// } Driver Code Ends