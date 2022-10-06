class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> h1(26,0);
         vector<int> h2(26,0);
        int n1=s1.size();
        int n2=s2.size();
        int i=0,j=0;
        if(n1>n2)
            return false;
        while(j<n1)
        {
            h1[s1[j] - 'a']++;
            h2[s2[j] - 'a']++;
            j++;
        }
        j--;
        while(j<n2)
        {
           if(h1 == h2)
           {
               return true;
           }
            j++;
            if(j != n2)
            {
                h2[s2[j] - 'a'] +=1;
                 h2[s2[i] - 'a'] -=1;
                i++;
            }
           
        }
        return false;
    }
};