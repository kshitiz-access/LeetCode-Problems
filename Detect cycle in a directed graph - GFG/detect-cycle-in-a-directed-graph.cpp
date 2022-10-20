//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool dfs(int id,vector<int> adj[],int V, int vis[],int pathvis[])
  {
      vis[id]=1;
      pathvis[id]=1;
      
      for(auto it: adj[id])
      {
          if(!vis[it])
          {
              if(dfs(it,adj,V,vis,pathvis) == true) return true;
          }
          else if(pathvis[it])
          {
              return true;
          }
      }
      
      pathvis[id]=0;
      return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
    
        vector<int> in(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto it: adj[i])
            {
                in[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(in[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node])
            {
                in[it]--;
                if(in[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        if(topo.size() == V)
        return false;
        else
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends