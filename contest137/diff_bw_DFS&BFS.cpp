#include <bits/stdc++.h>
using namespace std;

// First used DFS. Damn.... for every cell (i, j) it will traverse 4 times. Time complexity is Huge.

class Solution{
public:


    vector<int> dx = {0, -1, 0, 1};
    vector<int> dy = {-1, 0, 1, 0};
    
    
    bool isValid(int i, int j, vector<vector<int>>& v){
        if (i>=0 && i<v.size() && j>=0 && j<v[0].size()){
            return true;
        }
        return false;
    }

    void JSL(queue<pair<int, int>>& q, vector<vector<int>>& v){

        while (!q.empty()){
            
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for (int k = 0; k<4; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if (isValid(x, y, v) && v[x][y] == INT_MAX){
                    v[x][y] = v[i][j] + 1;
                    q.push({x, y});
                }
            }
            
        }
        
    }


    bool escapeForest(int n,int m,vector<vector<char>> &grid){
        // Code here
        
        vector<vector<int>> dm(n, vector<int>(m, INT_MAX)), df(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q1, q2;
        
        for (int i = 0; i<n; i++){
            for (int j = 0; j<m; j++){
                if (grid[i][j] == 'M'){
                    dm[i][j] = 0;
                    q1.push({i, j});
                    JSL(q1, dm);
                }
                else if (grid[i][j] == 'X'){
                    df[i][j] = 0;
                    q2.push({i, j});
                }
            }
        }
        
        JSL(q2, df);
        
        
        for (int j = 0; j<m; j++){
            if (df[0][j] > dm[0][j] || (df[n-1][j] > dm[n-1][j])){
                return true;
            }
        }
        
        for (int j = 0; j<n; j++){
            if (df[j][0] > dm[j][0] || (df[j][m-1] > dm[j][m-1])){
                return true;
            }
        }
        
        return false;
        
        
    }
};