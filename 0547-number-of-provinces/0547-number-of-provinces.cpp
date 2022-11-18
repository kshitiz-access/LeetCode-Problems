class Solution {
public:
    void bfs(vector<int> adj[],int idx,vector<int> &vis)
    {
        queue<int> q;
        q.push(idx);
        vis[idx]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(auto it: adj[node])
            {
                if(vis[it] == 0)
                {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                bfs(adj,i,vis);
            }
        }
        return cnt;
    }
};