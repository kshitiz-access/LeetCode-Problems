class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,pair<int,int>>> q;
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        q.push({0,{src,0}});
        vector<int> dis(n,1e9);
        dis[src]=0;
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            
            if(stops> k) continue;
            for(auto it: adj[node])
            {
                int adjN=it.first;
                int adjCost=it.second;
                
                if(cost + adjCost < dis[adjN] && stops<=k)
                {
                    dis[adjN]= cost+adjCost;
                    q.push({ stops+1,{adjN,dis[adjN]}});
                }
            }
        }
        
        
        if(dis[dst] == 1e9) return -1;
        return dis[dst];
    }
};