//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void dfs(vector<vector<int>>& grid, int i, int j, int id, int& size, vector<vector<int>>& ids) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid.size() || grid[i][j] != 1 || ids[i][j] != 0)
            return;
        
        ids[i][j] = id;
        size++;
        
        dfs(grid, i + 1, j, id, size, ids);
        dfs(grid, i - 1, j, id, size, ids);
        dfs(grid, i, j + 1, id, size, ids);
        dfs(grid, i, j - 1, id, size, ids);
    }
    
    
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        vector<vector<int>> ids(n, vector<int>(n, 0));
        unordered_map<int, int> componentSize;
        int componentId = 1;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && ids[i][j] == 0) {
                    int size = 0;
                    dfs(grid, i, j, componentId, size, ids);
                    componentSize[componentId] = size;
                    componentId++;
                }
            }
        }
        
        int maxConnection = 0;
        for (auto& size : componentSize) {
            maxConnection = max(maxConnection, size.second);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> uniqueComponents;
                    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                    for (auto& dir : directions) {
                        int ni = i + dir.first, nj = j + dir.second;
                        if (ni >= 0 && nj >= 0 && ni < n && nj < n && ids[ni][nj] != 0) {
                            uniqueComponents.insert(ids[ni][nj]);
                        }
                    }
                    
                    int potentialSize = 1; // the 0 itself turned to 1
                    for (int id : uniqueComponents) {
                        potentialSize += componentSize[id];
                    }
                    maxConnection = max(maxConnection, potentialSize);
                }
            }
        }
        
        return maxConnection;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends