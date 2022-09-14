class Solution {
    void func(TreeNode* root,int &ans,vector<int>&hash){
        if(root==NULL)
            return ;
        if(root->left==NULL && root->right==NULL){
            hash[root->val]++;
            int no_of_odds=0;
            for(int i=1;i<=9;i++){
                if(hash[i]%2!=0)
                    no_of_odds++;
            }
            if(no_of_odds<=1)
                ans++;
            hash[root->val]--;
        }
            
        hash[root->val]++;
        func(root->left,ans,hash);
        func(root->right,ans,hash);
        hash[root->val]--;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans=0;
        vector<int>hash(10,0);
        func(root,ans,hash);
        return ans;       
    }
};