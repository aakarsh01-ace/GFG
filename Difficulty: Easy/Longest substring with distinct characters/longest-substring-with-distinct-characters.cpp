//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        unordered_map<char, int> LsI;
        int maxL = 0;
        int strt = 0;
        
        for(int end = 0; end < s.size(); ++end){
            char currCh = s[end];
            if(LsI.find(currCh) != LsI.end() && LsI[currCh] >= strt){
                strt = LsI[currCh] + 1;
            }
            LsI[currCh] = end;
            maxL = max(maxL, end - strt + 1);
        }
        return maxL;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends