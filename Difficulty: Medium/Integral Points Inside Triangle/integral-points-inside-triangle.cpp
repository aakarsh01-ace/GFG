//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long gcd(long long a, long long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    long long countLatticePointsOnLine(long long p[], long long q[]) {
        
        return gcd(abs(p[0] - q[0]), abs(p[1] - q[1])) + 1;
    }

    long long triangleArea(long long p[], long long q[], long long r[]) {
        
        return abs(p[0] * (q[1] - r[1]) + q[0] * (r[1] - p[1]) + r[0] * (p[1] - q[1]));
    }


    long long int InternalCount(long long int p[], long long int q[],
                                long long int r[]) {
        // code here
         long long Bp = countLatticePointsOnLine(p, q) - 2; // Exclude endpoints
        long long Bq = countLatticePointsOnLine(q, r) - 2;
        long long Br = countLatticePointsOnLine(r, p) - 2;
        long long B = Bp + Bq + Br + 3; // Add endpoints back

        
        long long A2 = triangleArea(p, q, r);

        
        long long I = (A2 - B + 2) / 2;
        return I;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int p[2], q[2], r[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1];
        Solution ob;
        long long int ans = ob.InternalCount(p, q, r);
        cout << ans << "\n";
    }
}
// } Driver Code Ends