class Solution {
public:
   bool bfs(vector<vector<int>> arr,vector<int>& flag,int ind){
        queue<int> p;
        p.push(ind);
        flag[ind]=1;
        while(!p.empty()){
            int node=p.front();
            p.pop();
            for(int i=0;i<arr[node].size();i++){
                if(flag[arr[node][i]]==-1){
                    flag[arr[node][i]]=1-flag[node];
                    p.push(arr[node][i]);
                }
                else if(flag[arr[node][i]]==flag[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& g) {
        vector<int> flag(g.size(),-1);
        for(int i=0;i<g.size();i++){
            if(flag[i]==-1){
                if(!bfs(g,flag,i))return false;
            }
        }
        return true;
    }
};