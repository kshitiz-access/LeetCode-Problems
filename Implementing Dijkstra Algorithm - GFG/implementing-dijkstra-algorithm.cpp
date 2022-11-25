//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        
        set<pair<int,int>> st;
        vector<int> dis(V);
        for(int i=0;i<V;i++)
        {
            dis[i]=1e9;
        }
        
        dis[S]=0;
        st.insert({0,S});
        
        while(!st.empty())
        {
            auto it = *(st.begin());
            int d=it.first;
            int node=it.second;
            
            st.erase(it);
            
            for(auto i: adj[node])
            {
                int edgeWeight=i[1];
                int adjNode=i[0];
                
                if(d + edgeWeight < dis[adjNode])
                {
                    if(dis[adjNode] != 1e9)
                    {
                        st.erase({dis[adjNode],adjNode});
                    }
                    dis[adjNode] = d + edgeWeight;
                    st.insert({dis[adjNode],adjNode});
                }
            }
        }
        return dis;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends