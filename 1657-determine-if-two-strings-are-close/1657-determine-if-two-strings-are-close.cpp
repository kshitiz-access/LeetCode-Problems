class Solution {
public:
    bool closeStrings(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        
        unordered_map<char,int>m1,m2;
        
		priority_queue<pair<int,char>>p1,p2;
        
		for(int i=0;i<s1.length();i++){
			m1[s1[i]]++;
			m2[s2[i]]++;
		}
        
		for(auto i:m1){
			p1.push({i.second,i.first});
		}
		for(auto i:m2){
			p2.push({i.second,i.first});
		}
        
		while(p1.size()&&p2.size()){
			if(m2[p1.top().second]==0)
				return false;
            if(m1[p2.top().second]==0)
                return false;
			if(p1.top().first!=p2.top().first)
				return false;
			p1.pop();
			p2.pop();
		}
		return true;
    }
};