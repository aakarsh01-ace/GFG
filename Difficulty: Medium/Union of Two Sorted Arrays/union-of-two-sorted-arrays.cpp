//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        // take two pointers for the arrays
        int i = 0; // for arr1
        int j = 0; // for arr2;
        
        // step 2: initialize a list to store the union elements
        vector<int> unionArr;
        
        // iterate through the arrays
        while(i<n && j<m){
            if(arr1[i]<=arr2[j]){
                // if the element i of arr1 is not present in the union array then add it to it
                // or union array is still empty
                if(unionArr.size()==0 || unionArr.back() != arr1[i]){
                    unionArr.push_back(arr1[i]);
                }
                i++;
            }else {
                if(unionArr.size()==0 || unionArr.back() != arr2[j]){
                    unionArr.push_back(arr2[j]);
                }
                j++;
            }
        }
        
        // in case if one of the two arrays arr1, arr2 are completely iterated, we still have remaining elements in the other array
        // if second is exhausted
        while(i<n){
            if(unionArr.size()==0 || unionArr.back() != arr1[i]){
                unionArr.push_back(arr1[i]);
            }
            i++;
        }
        
        // if the first array is exhausted
        while(j<m){
            if(unionArr.size()==0 || unionArr.back() != arr2[j]){
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
        
        return unionArr;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends