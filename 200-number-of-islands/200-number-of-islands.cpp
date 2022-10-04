class Solution {
public:
    void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>> &vis)
    {
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n =grid.size();
        int m=grid[0].size();
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            if(r-1 >=0 && grid[r-1][c] =='1' && !vis[r-1][c])
            {
                vis[r-1][c]=1;
                q.push({r-1,c});
            }
            if(r+1<n &&  grid[r+1][c] =='1' && !vis[r+1][c])
            {
                vis[r+1][c]=1;
                q.push({r+1,c});
            }
            if(c-1>=0 && grid[r][c-1] =='1' && !vis[r][c-1])
            {
                vis[r][c-1]=1;
                q.push({r,c-1});
            }
            if(c+1<m && grid[r][c+1] =='1' && !vis[r][c+1])
            {
                vis[r][c+1]=1;
                q.push({r,c+1});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        int cnt=0;
        for(int r=0;r<n;r++)
        {
            for(int c=0;c<m;c++)
            {
                if(!vis[r][c] && grid[r][c]=='1')
                {
                    cnt++;
                    bfs(r,c,grid,vis);
                }
            }
        }
        return cnt;
    }
};