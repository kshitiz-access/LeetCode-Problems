class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        pair<int,int> source={0,0};
        pair<int,int> destination={n-1,n-1};
              
        if(grid[0][0] == 1)
         return -1;
        if(source.first == destination.first && source.second == destination.second)
         return 1;
        
        queue<pair<int, pair<int,int>>> q;
        
        vector<vector<int>> dis(n,vector<int> (m,1e9));
        dis[source.first][source.second]=0;
        q.push({0,{source.first , source.second}});
        
        int dr[] = {-1,0,+1,-1,1,-1,0,1};
        int dc[] = {-1,-1,-1,0,0,+1,+1,+1};
        
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int d=it.first;
            int r=it.second.first;
            int c=it.second.second;
            
            for(int i=0;i<8;i++)
            {
                int nr=r+dr[i];
                int nc=c+dc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 0 && d + 1 < dis[nr][nc])
                {
                    dis[nr][nc] = d+1;
                    if(nr == destination.first && nc== destination.second) return d+2;
                    q.push({dis[nr][nc] , {nr,nc}});
                    
                }
            }
            
            
        }
        return -1;
        
        
    }
};