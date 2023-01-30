//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& str) {
        // code here
        
        stack<char> s;
        string ans = "";
        for(auto i : str) {
            if(i == '(') {
                s.push(i);
                if(s.size() > 1) ans += i;
            }
            else {
                s.pop();
                if(s.size() > 0) ans += i;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends