class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& a) {
        priority_queue<pair<int, pair<int,int>>
        ,vector<pair<int, pair<int,int>>>
        ,greater<pair<int, pair<int,int>>>> pq;
        int n=a.size();
        int m=a[0].size();
        
        vector<vector<int>> dis(n,vector<int> (m,1e9));
        
        dis[0][0]=0;
        pq.push({0 , {0,0}});
        int dr[] = {-1,+1,0,0};
        int dc[] = {0 , 0 , 1,-1};
        
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            
            int diff=it.first;
            int r=it.second.first;
            int c=it.second.second;
            
            if(r==n-1 && c==m-1) return diff;
            for(int i=0;i<4;i++)
            {
                int nr=r+dr[i];
                int nc=c+dc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m)
                {
                    int newEffort=max(diff, abs(a[r][c] - a[nr][nc]));
                    if(newEffort < dis[nr][nc])
                    {
                        dis[nr][nc]=newEffort;
                        pq.push({dis[nr][nc] , {nr,nc}});
                    }
                    
                }
            }
        }
        return -1;
    }
};