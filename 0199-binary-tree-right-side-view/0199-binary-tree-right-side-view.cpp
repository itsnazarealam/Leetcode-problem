class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root)   return ans;

        queue<pair<TreeNode*, int>> q;
        map<int, int> mp;
        q.push({root, 0});
        
        while(!q.empty()){
            TreeNode* temp = q.front().first;
            int ind = q.front().second;
            q.pop();

            mp[ind] = temp->val;
            
            if(temp->left && temp->right){
                q.push({temp->left, ind+1});
                q.push({temp->right, ind+1});
            }
            else if(temp->left && !temp->right){
                q.push({temp->left, ind+1});
            }
            else if(!temp->left && temp->right){
                q.push({temp->right, ind+1});
            }
        }
        for(auto x: mp)
            ans.push_back(x.second);

        return ans;
    }
};