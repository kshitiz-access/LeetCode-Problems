class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        if(arr.size() == 0) return true;
            sort(arr.begin(), arr.end());
            auto index=arr.end();
            for(int i = 0; i < arr.size(); ++i)
            {   
                if(arr[i] == INT_MIN) continue;
                if(arr[i] >= 0)
                {   
                if((index = lower_bound(arr.begin() + i + 1, arr.end(), arr[i] * 2)) != arr.end())
                    {   
                        int loc = index - arr.begin();
                        if(arr[loc] == 2 * arr[i]) 
                        {   
                            arr[i] = INT_MIN; 
                            arr[loc] = INT_MIN;
                            continue;   
                        }
                    }
                }
                {   
                if(arr[i] % 2) return false;
                if((index = lower_bound(arr.begin() + i + 1, arr.end(), arr[i] / 2)) != arr.end())
                    {   
                        int loc = index - arr.begin();
                        if(arr[loc] == arr[i] / 2)
                        {   
                            arr[i] = INT_MIN;
                            arr[loc] = INT_MIN;
                            continue;   
                        }
                    }
                }
                return false;
            }
            return true;
    }
};