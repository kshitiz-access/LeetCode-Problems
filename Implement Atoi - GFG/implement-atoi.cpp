//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    int myAtoi(string s, int sign, int i, int result) {

        if (i >= s.size())
            return sign * result;
        if(s[i]< '0' || s[i]>'9')
            return -1;
        

        int tmp = s[i] - '0';
        if (result > INT_MAX / 10 || result == INT_MAX / 10 && tmp > 7)
            return sign > 0 ? INT_MAX : INT_MIN;
        int d=myAtoi(s, sign, i + 1, result * 10 + tmp);
        if(d==-1)
        {
            return -1;
        }
        else return d;
    }
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
         int i = 0, n = str.size(), sign = 1;
        while (i < n && str[i] == ' ')
            ++i;

        if (str[i] == '-')
            sign = -1, ++i;
        else if (str[i] == '+')
            ++i;

        return myAtoi(str, sign, i, 0);
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends