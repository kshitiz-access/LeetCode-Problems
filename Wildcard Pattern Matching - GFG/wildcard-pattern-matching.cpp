//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
bool f(int i,int j,string &s1,string &s2, vector<vector<int>> &dp)
    {
        if(i==00 && j==00) return true;
        if(i==00 && j>0) return false;
        
        if(j==0 && i>0)
        {
            for(int k=1;k<=i;k++)
            {
                if(s1[k-1] != '*')
                    return false;
            }
            return true;
        }
        
        if(dp[i][j] !=-1) return dp[i][j];
        if(s1[i-1] == s2[j-1] || s1[i-1] == '?')
            return dp[i][j]= f(i-1,j-1,s1,s2,dp);
        if(s1[i-1] == '*')
        {
            return dp[i][j] = f(i-1,j,s1,s2,dp) || f(i,j-1,s1,s2,dp);
        }
        
        return dp[i][j] = false;
    }
    int wildCard(string s1,string s2)
    {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return f(n,m,s1,s2,dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends