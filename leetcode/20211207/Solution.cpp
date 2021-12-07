#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>> &grid,int row,int col,int color) {
        int m=grid.size(),n=grid[0].size();

        vector<vector<bool>> visited(m,vector<bool>(n,false));
        vector<pii> borders;
        int originalColor=grid[row][col];
        int direc[4][2]={ {0,1},{0,-1},{1,0},{-1,0} };
        queue<pii> q;
        q.emplace(row,col);

        visited[row][col] = true;
        while(!q.empty()) {
            pii& node = q.front();
            q.pop();
            int x=node.first,y=node.second;

            bool isBorder = false;
            for(int i=0;i<4;i++) {
                int nx=direc[i][0]+x,ny=direc[i][1]+y;
                if(!(nx>=0&&nx<m&&ny>=0&&ny<n&&grid[nx][ny] == originalColor)) {
                    isBorder=true;
                } else if(!visited[nx][ny]) {
                    visited[nx][ny]=true;
                    q.emplace(nx,ny);
                }
            }

            if(isBorder) {
                borders.emplace_back(x,y);
            }
        }

        for(auto& [x,y] : borders) {
            grid[x][y] = color;
        }

        return grid;
    }
};