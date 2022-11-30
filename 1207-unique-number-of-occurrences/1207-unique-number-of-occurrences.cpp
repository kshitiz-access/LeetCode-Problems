class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr){
        map<int,int> mpp;
        for(int x: arr)
        {
            mpp[x]++;
        }
        set<int> st;
        
        for(auto it: mpp)
        {
            if(st.count(it.second)) return false;
            st.insert(it.second);
        }
        
        return true;  
        
    }
};