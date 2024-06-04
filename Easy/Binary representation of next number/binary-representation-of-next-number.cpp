//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        string result="";
        
        int zerofound=0;
        for(int i=s.size()-1 ; i>=0 ; i--)
          {
              if(s[i]=='1' && zerofound==0 )
               {
                   result='0'+result;
               }
               else if(s[i]=='0' && zerofound==0)
                {
                    result='1'+result;
                    zerofound=1;
                }
                else
                 result=s[i]+result;
          }
        
        if(zerofound==0) result='1'+result;
        
        int j=0;
        
        while(result[j]=='0')
         {
             j++;
         }
        result=result.substr(j, result.size());
        
        return result;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends