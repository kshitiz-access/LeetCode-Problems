class Solution {
public:
    void reverse_word(string &str, int i, int j)
    {
        while(i <= j)
        {
            swap(str[i], str[j]);
            
            i++;
            
            j--;
        }
    }
    string reverseWords(string str) {
        int n = str.size();
        int j = 0;
        int i = 0;
       
        while(i < n)
        {   
            while(i < n && str[i] == ' ')
            {
                i++;
            }
            while(i < n && isalnum(str[i]))
            {
                str[j++] = str[i];
                
                i++;
            }
            str[j++] = ' ';
        }
        
        str = str.substr(0, j);
        i = 0;
        
        while(i < str.size())
        {
            
            int start = i;
            
            while(i < str.size() && isalnum(str[i]))
            {
                i++;
            }
            
            reverse_word(str, start, i - 1);
            
            i++;
        }
        reverse(str.begin(), str.end());
        i = 0;
        
        while(i < str.size() && str[i] == ' ')
        {
            i++;
        }
        
        return str.substr(i);
    }
};