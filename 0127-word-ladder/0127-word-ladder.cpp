class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());

        queue<pair<string,int>> q;
        
        q.push({startWord,1});
        st.erase(startWord);
        
        while(!q.empty())
        {
            string s=q.front().first;
            int d=q.front().second;
            q.pop();
            
            if(s==targetWord)
            {
                return d;
            }
            for(int i=0;i<s.size();i++)
            {
                char org=s[i];
                for(char ch='a';ch<='z';ch++)
                {
                    s[i]=ch;
                    if(st.find(s) != st.end()){
                        st.erase(s);
                        q.push({s,d+1});
                    }
                }
                s[i]=org;
            }
        }
        return 0;
    }
};