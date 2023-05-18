//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(vector<vector<char>>& mat , vector<vector<int>>& vis , int row , int col,
    int rowSize , int colSize){
        if(row < 0 || col < 0 || row >= rowSize || col >= colSize || mat[row][col] == 'X'
        || vis[row][col] != -1){
            return;
        }else{
            vis[row][col] = 1;
            dfs(mat , vis , row - 1 , col , rowSize , colSize);
            dfs(mat , vis , row + 1 , col , rowSize , colSize);
            dfs(mat , vis , row , col - 1 , rowSize , colSize);
            dfs(mat , vis , row , col + 1 , rowSize , colSize);
            return;
        }
        return;
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        if(n==0 || m==0)
            return mat;
        vector<vector<int>> vis(n,vector<int> (m,-1));
        //first row
        for(int j=0;j<m;j++)
        {
            if(vis[0][j] == -1 && mat[0][j]=='O')
            {
               dfs(mat , vis , 0 , j , n , m);
            }
        }
        //last row
        for(int j=0;j<m;j++)
        {
            if(vis[n-1][j] == -1 && mat[n-1][j]=='O')
            {
                dfs(mat , vis , n-1 , j , n , m);
            }
        }
        //first column
        for(int i=1;i<n;i++)
        {
            if(vis[i][0] == -1 && mat[i][0]=='O')
            {
                dfs(mat , vis , i , 0 , n , m);
            }
        }
        
        for(int i=1;i<n;i++)
        {
            if(vis[i][m-1] == -1 && mat[i][m-1]=='O')
            {
                dfs(mat , vis , i , m-1 , n , m);
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 'O' && vis[i][j] == -1){
                    mat[i][j] = 'X';
                }
            }
        }
        
        return mat;   
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends