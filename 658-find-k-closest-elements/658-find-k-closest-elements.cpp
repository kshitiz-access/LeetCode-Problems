class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        priority_queue<pair<int,int>> maxh;
        for(int i=0;i<arr.size();i++){
            int temp=abs(x-arr[i]);
            maxh.push({temp,arr[i]});
            if(k<maxh.size())
            {
                maxh.pop();
            }
        }
        while(!maxh.empty()){
            res.push_back(maxh.top().second);
            maxh.pop();
        }
        sort(res.begin(),res.end());
        return res;
    }
};