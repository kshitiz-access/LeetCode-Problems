class Solution {
public:
    int bfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& vis)
    {
        int n=grid.size();
        int m=grid[0].size();
        int maxi=0;
        vis[r][c]=1;
        queue<pair<int,int>> q;
        q.push({r,c});
        int delR[]={-1,1,0,0};
        int delC[]={0,0,1,-1};
        int cnt=1;
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr=row+delR[i];
                int nc=col+delC[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m &&
                  !vis[nr][nc] && grid[nr][nc] ==1)
                {
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                    cnt++;
                }
            }
        }
        maxi=cnt;
        return maxi;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int res=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j] ==1)
                    res=max(res,bfs(i,j,grid,vis));
            }
        }
        return res;
    }
};