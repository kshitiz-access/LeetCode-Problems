class Solution {
public:
    void bfs(){
        
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        
        queue<pair<pair<int,int> ,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] ==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }
        int t=0;
        int delRow[]={-1,1,0,0};
        int delCol[]={0,0,-1,1};
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int tm=q.front().second;
            q.pop();
            t=max(t,tm);
            
            for(int i=0;i<4;i++)
            {
                int nrow=r+delRow[i];
                int ncol=c+delCol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                  && vis[nrow][ncol] !=2 && grid[nrow][ncol] ==1)
                {
                    q.push({{nrow,ncol}, tm+1});
                    vis[nrow][ncol]=2;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j] !=2 && grid[i][j] ==1)
                {
                    return -1;
                }
            }
        }
        return t;
    }
};