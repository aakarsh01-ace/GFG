//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     long long solve(int idx , int n , vector<vector<long long>>& dp){
        if(n == 1) return 1 ;
        if(dp[n][idx] != -1) return dp[n][idx] ;
        if(idx == 0){
            return dp[n][idx] = (solve(idx , n - 1 , dp) + solve(8 , n - 1 , dp)) ;
        }
        long long left , right , down , up ;
        left = 0 ;
        right = 0 ;
        up = 0 ; 
        down = 0 ;
        if(idx % 3 == 0) left = solve(idx - 1 , n - 1 , dp) ;
        else if(idx % 3 == 2) {
            left = solve(idx - 1 , n - 1 , dp) ;
            right = solve(idx + 1 , n - 1 , dp) ;
        }
        else{
            right = solve(idx + 1 , n - 1 , dp) ;
        }
        if(idx <= 3){
            down = solve(idx + 3 , n - 1 , dp) ;
        }
        else if(idx <= 6){
            down = solve(idx + 3 , n - 1 , dp) ;
            up = solve(idx - 3 , n - 1 , dp) ;
        }
        else{
            up = solve(idx - 3 , n - 1 , dp) ;
            if(idx == 8) down = solve(0 , n - 1 , dp) ;
        }
        return dp[n][idx] = (solve(idx , n - 1 , dp) + up + left + right + down) ;
        
    }

    long long getCount(int n) {
        // Your code goes here
        vector<vector<long long>> dp(n + 1 , vector<long long> (10 , -1)) ;
        long long ans = 0 ;
        for(int i = 0 ; i <= 9 ; i++) ans += solve(i , n , dp) ;
        return ans;

    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends