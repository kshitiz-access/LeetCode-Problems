class Solution {
public:
    int f(int i,int j1,int j2,vector<vector<int>>& grid,int n,int m, 
          vector<vector<vector<int>>> &dp)
    {
        if(j1<0 || j1>=m || j2<0 || j2>=m)
            return -1e8;
        if(i==n-1)
        {
            if(j1==j2)
                return grid[i][j1];
            else
                return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        int maxi=0;
        for(int delj1=-1;delj1<=1;delj1++)
        {
            for(int delj2=-1;delj2<=1;delj2++)
            {
                if(j1==j2)
                    maxi=max(maxi, grid[i][j1] + f(i+1,j1+delj1,j2+delj2,grid,n,m,dp));
                else
                    maxi=max(maxi, grid[i][j1]+grid[i][j2] + f(i+1,j1+delj1,j2+delj2,grid,n,m,dp));
            }
        }
        return dp[i][j1][j2] = maxi;
        
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (m,0)));
        // return f(0,0,m-1,grid,n,m,dp);
        //Tabulation
        for(int j1=0;j1<m;j1++)
        {
            for(int j2=0;j2<m;j2++)
            {
                if(j1==j2)
                {
                    dp[n-1][j1][j2]=grid[n-1][j1];
                }
                else
                {
                    dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
                }
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j1=0;j1<m;j1++)
            {
                for(int j2=0;j2<m;j2++)
                {
                    int maxi=0;
                    for(int delj1=-1;delj1<=1;delj1++)
                     {
                            for(int delj2=-1;delj2<=1;delj2++)
                                {
                                    int value=0;
                                    if(j1==j2)
                                        value=grid[i][j1];
                                    else
                                        value=grid[i][j1]+grid[i][j2];
                                    if(j1+delj1>=0 && j1+delj1<m && j2+delj2>=0 && j2+delj2<m)
                                        value+=dp[i+1][j1+delj1][j2+delj2];
                                    else
                                        value=-1e8;
                
                                        maxi=max(maxi,value);
                                }
                        }
                    dp[i][j1][j2]=maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }
};