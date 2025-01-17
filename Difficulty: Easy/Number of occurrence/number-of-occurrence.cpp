//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int first(vector<int>& arr, int target){
        int n = arr.size();
        int left = 0, right = n - 1;
        int result = -1;
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(arr[mid] == target){
                result = mid;
                right = mid - 1;
            }else if(arr[mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return result;
    }
    
    int last(vector<int>& arr, int target){
        int n = arr.size();
        int left = 0, right = n - 1;
        int result = -1;
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(arr[mid] == target){
                result = mid;
                left = mid + 1;
            }else if(arr[mid] > target){
                right = mid - 1;
            }else{
                left  = mid + 1;
            }
        }
        return result;
    }
    int countFreq(vector<int>& arr, int target) {
        // code here
        int F = first(arr, target);
        int L = last(arr, target);
        
        if(F == -1){
            return 0;
        }else{
            return (L - F) + 1;
        }
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends