//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<int> getPrimes(int n) {
        // code here
        vector<bool> isPrime(n + 1, true);
        vector<int> primes;
        isPrime[0] = isPrime[1] = false; 

        for (int p = 2; p * p <= n; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    isPrime[i] = false;
                }
            }
        }

        for (int p = 2; p <= n; p++) {
            if (isPrime[p]) {
                primes.push_back(p);
            }
        }

    
        int i = 0, j = primes.size() - 1;
        while (i <= j) {
            int sum = primes[i] + primes[j];
            if (sum == n) {
                return {primes[i], primes[j]};
            } else if (sum < n) {
                i++;
            } else {
                j--;
            }
        }

        return {-1, -1};

    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends