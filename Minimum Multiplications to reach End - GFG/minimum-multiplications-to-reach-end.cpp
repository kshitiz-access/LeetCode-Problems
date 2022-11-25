//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int mod=100000;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        
        queue<pair<int,int>> q;
        vector<int> dis(100000,1e9);
        dis[start]=0;
        q.push({0,start});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int steps=it.first;
            int num=it.second;
            
            for(auto it: arr)
            {
                int n=(it*num)%mod;
                if(steps+1 < dis[n])
                {
                    dis[n]=steps+1;
                    if(n==end) return dis[n];
                    q.push({steps+1,n});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends