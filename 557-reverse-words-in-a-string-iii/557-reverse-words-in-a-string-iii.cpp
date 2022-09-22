class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=0;
       for (i = 0; i < n; i++)
        {
           if(s[i] != ' ')
           {
               int j=i;
            while(s[j] != ' ' && j<n)
            {
                j++;
            }
            reverse(s.begin()+i , s.begin() + j);
            i=j-1;
           }
        }
        return s;
    }
};