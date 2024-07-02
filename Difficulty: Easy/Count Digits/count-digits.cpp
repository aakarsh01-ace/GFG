//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int evenlyDivides(int N){
        //code here
        string numStr = to_string(N);
        int count = 0;
        for (char digitChar : numStr) {
            int digit = digitChar - '0'; // Convert char to int
            if (digit != 0 && N % digit == 0) { // Check if digit is not zero and divides N evenly
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends